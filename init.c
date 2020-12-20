#include "$CurrentDir:\\mpmissions\\deathmatch.namalsk\\clothes.c"
#include "$CurrentDir:\\mpmissions\\deathmatch.namalsk\\crates.c"
#include "$CurrentDir:\\mpmissions\\deathmatch.namalsk\\infected.c"
#include "$CurrentDir:\\mpmissions\\deathmatch.namalsk\\limbo.c"
#include "$CurrentDir:\\mpmissions\\deathmatch.namalsk\\settings.c"
#include "$CurrentDir:\\mpmissions\\deathmatch.namalsk\\weapons.c"


void main()
{
    /*
      [Namalsk] CE init (offline)
    */
    CreateHive();
    GetHive().InitOffline();

    /*
      [Namalsk] Weather init
       Warning: DO NOT ALTER following values as they are interconnected with other Namalsk-specific systems!
       To ensure correct functionality, it is necessary to include weaher init AFTER the hive init.
    */
    Weather weather = GetGame().GetWeather();
    weather.MissionWeather( true );
    weather.GetOvercast().SetLimits( 0.10, 0.30 );
    weather.GetRain().SetLimits( 0.0, 0.0 );
    weather.GetFog().SetLimits( 0.0, 0.0 );
    weather.GetOvercast().SetForecastChangeLimits( 0.1, 0.3 );
    weather.GetOvercast().SetForecastTimeLimits( 1600, 2100 );
    weather.GetOvercast().Set( Math.RandomFloatInclusive( 0.1, 0.2 ), 0, 0 );   // ignored if storage is present
    weather.GetRain().Set( 0, 0, 0 );                                           // ignored if storage is present
    weather.GetFog().Set( 0, 0, 0 );                                            // ignored if storage is present
    weather.SetWindMaximumSpeed( 30 );
    weather.SetWindFunctionParams( 0.1, 1.0, 42 );
    weather.SetStorm( 0, 1, 1 );
    weather.SetRainThresholds( 0.0, 1.0, 0 );

    /*
      [Namalsk] Mission time init
       after CE init to determine if storage mission type is outside of the required time-frame
       currently recommended time-frame is:
        11/1 -> 11/30
        keep in mind that gameplay features are tied to the mission date (stored in the storage) and that it SHOULD remain this period!
       while using:
        day accelerated 6 times (serverTimeAcceleration=6), resulting in an average 78 min of day-time (RL)
        night accelerated 24 times (serverNightTimeAcceleration=4), resulting in an average of 26 min of night-time (RL)
    */
    int year, month, day, hour, minute;
    GetGame().GetWorld().GetDate( year, month, day, hour, minute );

    if ( ( month < 11 ) || ( month >= 12 ) )
    {
        year = 2011;
        month = 11;
        day = 1;

        GetGame().GetWorld().SetDate( year, month, day, hour, minute );
    }
};

class CustomMission: MissionServer
{
    static private ref TStringArray SuicideReasons = {
        " had a senior moment!",
        " had a brain fart!",
        " had an accident!",
        " bought the farm!",
        " took a dirt nap!",
        " pined for the fjords!",
        " kicked the bucket!",
        " shuffled off this mortal coil!",
        " is kaput!",
        " took a permanent vacation!",
        " paid the piper!",
        " croaked!",
        " flatlined!",
        " is no more!",
        " met an untimely end!",
        " forgot to pay the brain bill!"
    };

    static private int DEFAULT_ROUND_DURATION = 30;
    static private int COUNTDOWN_DURATION_MS = 10000;

    static private const vector CHRISTMAS_TREE_POSITION = "6777.04 15.0711 11281.7";
    static private const vector PLAYAREA_CENTER = "6767 0 11261";
    static private const int CLEANUP_RADIUS = 600;
    static private const int KILL_RADIUS = 570;
    static private const int PLAYAREA_RADIUS = 500;

    autoptr TStringStringMap m_Identities = new TStringStringMap();

    autoptr Clothes clothes = new Clothes();
    autoptr Weapons weapons = new Weapons();

    int m_num_rounds = 0;

    int m_round_end;
    bool m_round_ending = false;

    bool m_cowboy_round = false;

    autoptr DeathmatchSettings m_settings = new DeathmatchSettings();

    autoptr map<PlayerIdentity, int> m_player_kills = new map<PlayerIdentity, int>();
    autoptr map<PlayerIdentity, int> m_player_deaths = new map<PlayerIdentity, int>();

    void CustomMission()
    {
        CreateRestApi();

        CGame game = GetGame();

        // Throw away the first random number because it doesn't appear to be random
        Math.RandomInt(0, 100);

        m_settings.load();

        game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.CheckPlayerPositions, 10000, true);

        if (m_settings.christmas) {
            game.CreateObject("ChristmasTree_Green", CHRISTMAS_TREE_POSITION, false, false, false);
        }

        this.RollForCowboyRound();
        this.CleanupObjectsAndStartRound();
    }

    private float DistanceFromCenter(vector pos)
    {
        vector adjusted = Vector(pos[0], 0, pos[2]);

        return vector.Distance(PLAYAREA_CENTER, adjusted);
    }

    private void CheckPlayerPositions()
    {
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        foreach (Man player : players)
        {
            if (player.IsAlive())
            {
                float distance = this.DistanceFromCenter(player.GetPosition());

                if (distance > PLAYAREA_RADIUS)
                {
                    Print("Player " + player.GetIdentity().GetName() + " is too far away (" + distance + ")");
                    NotificationSystem.SendNotificationToPlayerExtended(
                            player, 5.0, "You are outside the zone!",
                            "You will continue to lose health until you return to the zone.");
                    if (distance > KILL_RADIUS)
                    {
                        player.SetHealth(0.0);
                    }
                    else
                    {
                        player.SetHealth(player.GetHealth() - 33);
                    }
                }
            }
        }
    }

    private void NotifyPlayer(PlayerIdentity identity, string message, string details = "")
    {
        string now = GetGame().GetTime().ToString();
        string name = "ALL";
        if (identity)
        {
            name = identity.GetName();
        }

        // This should use chat messaging but, because chat is broken in v1.07, we're using
        // NotificationSystem, instead.
        NotificationSystem.SendNotificationToPlayerIdentityExtended(
                identity, 5.0, message, details);

        Print(now + " | NOTIFY | " + name + " (" + identity + ") | " + message + " | " + details);
    }

    private void NotifyAllPlayers(string message, string details = "")
    {
        this.NotifyPlayer(null, message, details);
    }

    private void EndRoundCountdown(int duration)
    {
        if (duration <= 0)
        {
            this.RestartRound();
        }
        else
        {
            string detail;

            if (m_num_rounds == m_settings.maxRounds)
            {
                detail = "Server will restart";
            }

            int timeLeft = duration / 1000;
            this.NotifyAllPlayers("Round ends in " + timeLeft + " seconds", detail);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(
                    this.EndRoundCountdown, 5000, false, duration - 5000);
        }
    }

    private void StartRound()
    {
        m_num_rounds++;

        Print("Starting round " + m_num_rounds);

        Print("Players:");
        for (int i = 0; i < m_Identities.Count(); i++)
        {
            Print("  | " + i + " | " + m_Identities.GetKey(i) + " | " + m_Identities.GetElement(i) + " |");
        }

        m_round_ending = false;

        m_player_kills.Clear();
        m_player_deaths.Clear();

        CGame game = GetGame();

        m_round_end = game.GetTime() + (m_settings.roundMinutes * 60000);

        int delay = (m_settings.roundMinutes * 60000) - COUNTDOWN_DURATION_MS;
        game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(
                this.EndRoundCountdown,
                delay,
                false,
                COUNTDOWN_DURATION_MS);

        if (!m_cowboy_round)
        {
            Crates.SpawnCrates(game);
        }

        if (m_settings.infectedChance > 0 && Math.RandomInt(0, 100) < m_settings.infectedChance)
        {
            Infected.Spawn(
                    game, m_Identities.Count(), m_settings.infectedPlayerFactor,
                    m_settings.minimumInfected, m_settings.maximumInfected, m_settings.christmas,
                    m_cowboy_round);
        }

        if (m_cowboy_round)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(
                    this.NotifyAllPlayers, 10000, false, "-=- COWBOY ROUND -=-",
                    "Giddy-up, pardner!");
        }

        if (m_settings.christmas)
        {
            GameInventory box1 = ItemBase.Cast(game.CreateObject("GiftBox_Large_1", CHRISTMAS_TREE_POSITION + "-5 0 0", false, false, false)).GetInventory();
            GameInventory megaphone = box1.CreateInInventory("Megaphone").GetInventory();
            megaphone.CreateAttachment("Battery9V");

            GameInventory box2 = ItemBase.Cast(game.CreateObject("GiftBox_Large_2", CHRISTMAS_TREE_POSITION + "5 0 0", false, false, false)).GetInventory();
            box2.CreateInInventory("AK_Suppressor");
            box2.CreateInInventory("M4_Suppressor");
            box2.CreateInInventory("PistolSuppressor");
            box2.CreateInInventory("ImprovisedSuppressor");

            GameInventory box3 = ItemBase.Cast(game.CreateObject("GiftBox_Large_3", CHRISTMAS_TREE_POSITION + "0 0 -5", false, false, false)).GetInventory();
            box3.CreateInInventory("M18SmokeGrenade_Green");
            box3.CreateInInventory("M18SmokeGrenade_Red");
            box3.CreateInInventory("M18SmokeGrenade_Green");
            box3.CreateInInventory("M18SmokeGrenade_Red");
            box3.CreateInInventory("M18SmokeGrenade_Green");
            box3.CreateInInventory("M18SmokeGrenade_Red");
            box3.CreateInInventory("M18SmokeGrenade_Green");
            box3.CreateInInventory("M18SmokeGrenade_Red");
            box3.CreateInInventory("M18SmokeGrenade_Green");
            box3.CreateInInventory("M18SmokeGrenade_Red");

            GameInventory box4 = ItemBase.Cast(game.CreateObject("GiftBox_Large_4", CHRISTMAS_TREE_POSITION + "0 0 5", false, false, false)).GetInventory();
            GameInventory deagle = box4.CreateInInventory("Deagle_Gold").GetInventory();
            deagle.CreateAttachment("PistolOptic");
            deagle.CreateAttachment("PistolSuppressor");
            box4.CreateInInventory("Mag_Deagle_9rnd");
            box4.CreateInInventory("Mag_Deagle_9rnd");
            box4.CreateInInventory("Mag_Deagle_9rnd");
        }

        Print("Done starting round");
    }

    private string ReportPlayerStats()
    {
        array<PlayerIdentity> identities = new array<PlayerIdentity>();
        GetGame().GetPlayerIndentities(identities);
        string bestPlayer;
        int bestKills = -1;
        int bestDeaths = -1;

        for (int i = 0; i < identities.Count(); i++)
        {
            PlayerIdentity identity = identities.Get(i);
            int kills = m_player_kills.Get(identity);
            int deaths = m_player_deaths.Get(identity);
            this.NotifyPlayer(identity, "Your K:D was " + kills + ":" + deaths);

            if (kills > bestKills || ((kills == bestKills) && (deaths < bestDeaths)))
            {
                bestPlayer = identity.GetName();
                bestKills = kills;
                bestDeaths = deaths;
            }
        }

        if (bestPlayer != "")
        {
            return ("The top K:D was " + bestKills + ":" + bestDeaths + " by " + bestPlayer);
        }

        return "";
    }

    void RollForCowboyRound()
    {
        if (m_settings.cowboyRoundChance > 0)
        {
            int roll = Math.RandomInt(0, 100);
            m_cowboy_round = (roll < m_settings.cowboyRoundChance);
        }
        else
        {
            m_cowboy_round = false;
        }
    }

    private void EndRound()
    {
        Print("Ending round");
        CGame game = GetGame();

        this.m_round_ending = true;

        string bestInfo = this.ReportPlayerStats();

        this.NotifyAllPlayers("The round has ended!", bestInfo);

        this.KillAllPlayers();

        ScriptCallQueue queue = game.GetCallQueue(CALL_CATEGORY_GAMEPLAY);

        if (m_settings.maxRounds > 0 && m_num_rounds >= m_settings.maxRounds)
        {
            Print("Max rounds reached -- requesting restart");
            queue.CallLater(game.RequestExit, 200, false, 0);
        }
        else
        {
            this.RollForCowboyRound();
            queue.CallLater(this.CleanupObjectsAndStartRound, 200, false);
        }

        Print("Done ending round");
    }

    private void RestartRound()
    {
        this.EndRound();
    }

    private void KillAllPlayers()
    {
        array<Man> men = new array<Man>();
        GetGame().GetPlayers(men);
        foreach (Man man : men)
        {
            Print("Checking man " + man);
            PlayerBase playerBase = PlayerBase.Cast(man);
            if (playerBase != null)
            {
                Print("Killing player " + playerBase);
                playerBase.SetHealth(0.0);
            }
            Limbo.PutInLimbo(man);
        }
    }

    private void CleanupObjects()
    {
        Print("Cleaning up objects");

        CGame game = GetGame();
        array<Object> objects = new array<Object>();
        array<CargoBase> cargos = new array<CargoBase>();
        Print("Finding objects");
        int start = game.GetTime();
        game.GetObjectsAtPosition(
                PLAYAREA_CENTER, CLEANUP_RADIUS, objects, cargos);
        int end = game.GetTime();
        int delta = end - start;
        Print("Done finding objects");
        Print(" Start: " + start);
        Print(" End: " + end);
        Print(" Delta: " + delta);

        Print(" Objects to check: " + objects.Count());

        foreach (Object obj : objects)
        {
            ItemBase itemBase = ItemBase.Cast(obj);
            if (itemBase != null && itemBase.GetHierarchyParent() == null)
            {
                Print("Cleaning up object " + itemBase);
                itemBase.Delete();
            }

            DayZCreature creature = DayZCreature.Cast(obj);
            if (creature != null)
            {
                Print("Cleaning up " + creature);
                creature.Delete();
            }

            PlayerBase player = PlayerBase.Cast(obj);
            if (player != null)
            {
                if (player.GetIdentity() == null)
                {
                    Print("Cleaning up corpse " + player);
                    player.Delete();
                }
                else
                {
                    Print("Stripping corpse " + player);
                    player.ClearInventory();
                    player.RemoveAllItems();
                    Limbo.PutInLimbo(player);
                }
            }
        }
        Print("Done cleaning up objects");
    }

    private void CleanupObjectsAndStartRound()
    {
        this.CleanupObjects();

        this.StartRound();
    }

    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        Entity playerEnt;
        playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
        Class.CastTo(m_player, playerEnt);

        GetGame().SelectPlayer(identity, m_player);

        return m_player;
    }

    void EquipPlayerForSurvival(PlayerBase player)
    {
        HumanInventory inventory = player.GetHumanInventory();
        EntityAI bandage = inventory.CreateInInventory("BandageDressing");
        inventory.CreateInInventory("SalineBagIV");
        inventory.CreateInInventory("Morphine");

        player.SetQuickBarEntityShortcut(bandage, 3);
    }

    void StartFedAndWatered(PlayerBase player)
    {
        player.GetStatWater().Set(player.GetStatWater().GetMax());
        player.GetStatEnergy().Set(player.GetStatEnergy().GetMax());
    }

    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        player.RemoveAllItems();

        EntityAI sheath = clothes.EquipPlayerClothes(player, m_settings.christmas, m_cowboy_round);
        this.EquipPlayerForSurvival(player);
        weapons.EquipPlayerWeapons(player, sheath, m_cowboy_round);
        this.StartFedAndWatered(player);
    }

    private void ReportTimeLeftInRound(notnull PlayerIdentity identity)
    {
        int remaining = m_round_end - GetGame().GetTime();
        string text;

        if (remaining > 120000)
        {
            text = (remaining / 60000).ToString() + " minutes";
        }
        else if (remaining > 15000)
        {
            text = (remaining / 1000).ToString() + " seconds";
        }
        else
        {
            // We're about to show the 10-second countdown, so don't spam the user with extra
            // notifications.
            return;
        }

        if (m_cowboy_round)
        {
            this.NotifyPlayer(identity, "Cowboy round ends in " + text);
        }
        else
        {
            this.NotifyPlayer(identity, "Round ends in " + text);
        }
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        Print("InvokeOnConnect :: " + player + " :: " + identity);

        string uid = identity.GetId();

        // Unfortunately, InvokeOnConnect gets called when players respawn, so we have to keep
        // track of connects and disconnects in order to know if this is being called for a
        // player's initial spawn.
        if (!m_Identities.Contains(uid))
        {
            string name = identity.GetName();

            m_Identities.Set(uid, name);

            this.NotifyAllPlayers(name + " has entered the arena");

            this.ReportTimeLeftInRound(identity);
        }

        Print("m_Identities.Count() == " + m_Identities.Count());

        super.InvokeOnConnect(player, identity);
    }

    override void PlayerDisconnected(PlayerBase player, PlayerIdentity identity, string uid)
    {
        Print("PlayerDisconnected :: " + player + " :: " + identity + " :: " + uid);

        string name;
        if (m_Identities.Find(uid, name))
        {
            m_Identities.Remove(uid);

            this.NotifyAllPlayers(name + " has left the arena");
        }

        Print("m_Identities.Count() == " + m_Identities.Count());

        super.PlayerDisconnected(player, identity, uid);
    }

    override void HandleBody(PlayerBase player)
    {
        player.DropAllItems();
        // Kill character so that players start fresh every time they connect
        player.SetHealth(0.0);
    }

    void KillFeedMessage(string title, string detail)
    {
        this.NotifyAllPlayers(title, detail);

        if (m_settings.killFeedWebhook.type == "discord")
        {
            JsonObject data = new JsonObject();
            data.AddString("content", title + " " + detail);

            RestCallback cbx = new RestCallback();
            RestContext ctx = GetRestApi().GetRestContext(m_settings.killFeedWebhook.url);
            ctx.SetHeader("application/json");
            ctx.POST(cbx, "", data.GetJson());
        }
        else if (m_settings.killFeedWebhook.type != "")
        {
            Print(" !!! Unsupported webhook type: " + m_settings.killFeedWebhook.type);
        }
    }

    void OnPlayerDeath(Man player)
    {
        PlayerIdentity identity = player.GetIdentity();
        if (identity)
        {
            m_player_deaths.Set(identity, m_player_deaths.Get(identity) + 1);

            string name = identity.GetName();

            string killTitle;
            string killDetails;

            KillerData data = player.m_KillerData;
            if (data)
            {
                Print("Player " + player + " was killed by " + data.m_Killer + " with a " + data.m_MurderWeapon);

                Man killerMan = Man.Cast(data.m_Killer);
                if (DayZInfected.Cast(data.m_MurderWeapon))
                {
                    killTitle = name + " was kissed by a zombie";
                    killDetails = "and liked it!";
                }
                else if (player == killerMan)
                {
                    killTitle = name + SuicideReasons.GetRandomElement();
                }
                else
                {
                    PlayerIdentity killerIdentity;
                    if (killerMan) killerIdentity = killerMan.GetIdentity();
                    if (killerIdentity)
                    {
                        m_player_kills.Set(killerIdentity, m_player_kills.Get(killerIdentity) + 1);

                        string killer = killerIdentity.GetName();
                        killTitle = killer + " killed " + name;

                        if (data.m_MurderWeapon)
                        {
                            if (data.m_MurderWeapon.GetDisplayName() != "Survivor")
                            {
                              killDetails = "using " + data.m_MurderWeapon.GetDisplayName();
                            }
                            else
                            {
                              killDetails = "using fists";
                            }
                        }

                        int distance = vector.Distance(player.GetPosition(), killerMan.GetPosition());
                        killDetails = killDetails + " from " + distance + "m";
                    }
                    else
                    {
                        killTitle = name + " was killed";
                    }
                }
            }
            else
            {
                Print("Player " + player + " was killed without any killer data");

                killTitle = name + " has died";
            }

            this.KillFeedMessage(killTitle, killDetails);
        }
        else
        {
            Print("Someone (" + player + ") died but I don't know who that is");
        }
    }

    override bool InsertCorpse(Man player)
    {
        Print("InsertCorpse :: " + player);

        if (!m_round_ending)
        {
            this.OnPlayerDeath(player);
        }

        return super.InsertCorpse(player);
    }
};

Mission CreateCustomMission(string path)
{
    return new CustomMission();
}

// vim:ft=cs
