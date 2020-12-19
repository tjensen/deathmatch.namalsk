class CratePositions
{
    private ref TVectorArray m_positions = {
        "7332.09 295.650 2667.92",  // on top of pipes by crater
        "7304.11 300.059 2850.14",  // on top of red brick warehouse
        "7373.78 296.850 2570.04",  // on white smokestack
        "7356.93 292.834 2825.19",  // on red guardhouse by fallen smokestack
        "7274.52 301.360 2951.12",  // on metal carport at north end of area
        "7303.02 297.038 2916.59",  // on long shed by unenterable warehouse
        "7313.10 293.887 2877.93",  // on pump house by pipes at north end
        "7300.19 291.888 2835.65",  // on yellow container by red warehouse
        "7346.53 282.017 2651.65",  // in cab of wrecked truck in crater
        "7297.61 293.265 2574.91",  // on Livonia grey warehouse at SW corner
        "7707.75 306.870 2725.75",  // on middle silo at Eastern edge
        "7367.28 290.383 2622.74",  // on yellow guardhouse by crater
        "7480.80 292.892 2515.61",  // on pipes by barracks
    };
    private int m_crateIndex = 0;

    void CratePositions()
    {
        // Shuffle the positions
        for (int i = 0; i < m_positions.Count(); i++)
        {
            m_positions.SwapItems(i, m_positions.GetRandomIndex());
        }
    }

    vector GetRandomPosition()
    {
        return m_positions.Get(m_crateIndex++);
    }
}


class Crates
{
    static private ref TStringArray WEAPONS = {"VSS", "FAL", "SVD"};

    static private ref TStringArray FAL_BUTTSTOCKS = {
        "Fal_FoldingBttstck", "Fal_OeBttstck"
    };

    static private ref TStringArray VESTS = {
        "PlateCarrierVest", "PressVest_Blue", "PressVest_LightBlue",
        "PoliceVest"
    };
    static private ref TStringArray HELMETS = {
        "BallisticHelmet_Black", "BallisticHelmet_Green", "BallisticHelmet_UN",
        "GorkaHelmet", "Mich2001Helmet", "Ssh68Helmet", "ZSh3PilotHelmet"
    };
    static private ref TStringArray GLOVES = {
        "TacticalGloves_Beige", "TacticalGloves_Black", "TacticalGloves_Green",
        "SurgicalGloves_Blue", "SurgicalGloves_Green",
        "SurgicalGloves_LightBlue", "SurgicalGloves_White",
        "NBCGlovesGray", "OMNOGloves_Brown", "OMNOGloves_Gray",
        "WorkingGloves_Beige", "WorkingGloves_Black", "WorkingGloves_Brown",
        "WorkingGloves_Yellow"
    };

    static private ref TStringArray TRAPS = {"LandMineTrap", "BearTrap"};
    static private ref TStringArray GRENADES = {
        "FlashGrenade", "M67Grenade", "RGD5Grenade", "M18SmokeGrenade_Purple",
        "M18SmokeGrenade_Green", "M18SmokeGrenade_Red",
        "M18SmokeGrenade_White", "M18SmokeGrenade_Yellow",
        "RDG2SmokeGrenade_Black", "RDG2SmokeGrenade_White"
    };

    static private ref TVectorArray m_positions = {
        "7332.09 295.650 2667.92",  // on top of pipes by crater
        "7304.11 300.059 2850.14",  // on top of red brick warehouse
        "7373.78 296.850 2570.04",  // on white smokestack
        "7356.93 292.834 2825.19",  // on red guardhouse by fallen smokestack
        "7274.52 301.360 2951.12",  // on metal carport at north end of area
        "7303.02 297.038 2916.59",  // on long shed by unenterable warehouse
        "7313.10 293.887 2877.93",  // on pump house by pipes at north end
        "7300.19 291.888 2835.65",  // on yellow container by red warehouse
        "7346.53 282.017 2651.65",  // in cab of wrecked truck in crater
        "7297.61 293.265 2574.91",  // on Livonia grey warehouse at SW corner
        "7707.75 306.870 2725.75",  // on middle silo at Eastern edge
        "7367.28 290.383 2622.74",  // on yellow guardhouse by crater
        "7480.80 292.892 2515.61",  // on pipes by barracks
    };
    static private int m_crateIndex = 0;

    static void SpawnCrates(CGame game)
    {
        autoptr CratePositions positions = new CratePositions();

        Crates.SpawnWeaponCrate(game, positions, WEAPONS.GetRandomElement());
        Crates.SpawnArmorCrate(game, positions);
        Crates.SpawnTrapCrate(game, positions);
    }

    static private void InitializeCratePositions()
    {
        m_crateIndex = 0;
        for (int i = 0; i < m_positions.Count(); i++)
        {
            m_positions.SwapItems(i, m_positions.GetRandomIndex());
        }
    }

    static private vector GetCratePosition()
    {
        vector pos = m_positions.Get(m_crateIndex);
        m_crateIndex++;
        return pos;
    }

    static private GameInventory SpawnCrate(
            CGame game, CratePositions positions)
    {
        vector position = positions.GetRandomPosition();

        Print("Spawning crate at " + position);
        ItemBase chest = ItemBase.Cast(
            game.CreateObject("SeaChest", position, false, false, false));
        // CreateObject doesn't always position the object correctly
        chest.SetPosition(position);

        return chest.GetInventory();
    }

    static private void SpawnEmptyMagazine(
            GameInventory inventory, string name)
    {
        Magazine magazine = Magazine.Cast(inventory.CreateInInventory(name));
        magazine.ServerSetAmmoCount(0);
    }

    static private void SpawnVSS(GameInventory inventory)
    {
        inventory.CreateInInventory("VSS");

        inventory.CreateInInventory("PSO1Optic");
        inventory.CreateInInventory("Battery9V");

        Crates.SpawnEmptyMagazine(inventory, "Mag_VSS_10Rnd");
        Crates.SpawnEmptyMagazine(inventory, "Mag_VSS_10Rnd");
        Crates.SpawnEmptyMagazine(inventory, "Mag_VSS_10Rnd");

        // Despite its name, the 20-round box actually contains 10 rounds
        inventory.CreateInInventory("AmmoBox_9x39AP_20Rnd");
        inventory.CreateInInventory("AmmoBox_9x39AP_20Rnd");
        inventory.CreateInInventory("AmmoBox_9x39AP_20Rnd");
        inventory.CreateInInventory("AmmoBox_9x39AP_20Rnd");
        inventory.CreateInInventory("AmmoBox_9x39AP_20Rnd");
        inventory.CreateInInventory("AmmoBox_9x39AP_20Rnd");
    }

    static private void SpawnFAL(GameInventory inventory)
    {
        inventory.CreateInInventory("FAL");

        inventory.CreateInInventory(FAL_BUTTSTOCKS.GetRandomElement());

        inventory.CreateInInventory("ACOGOptic");

        // The FAL currently only accepts an improved suppressor, which doesn't
        // last very long, so offer a few of them.
        inventory.CreateInInventory("ImprovisedSuppressor");
        inventory.CreateInInventory("ImprovisedSuppressor");
        inventory.CreateInInventory("ImprovisedSuppressor");
        inventory.CreateInInventory("ImprovisedSuppressor");
        inventory.CreateInInventory("ImprovisedSuppressor");

        Crates.SpawnEmptyMagazine(inventory, "Mag_FAL_20Rnd");
        Crates.SpawnEmptyMagazine(inventory, "Mag_FAL_20Rnd");
        Crates.SpawnEmptyMagazine(inventory, "Mag_FAL_20Rnd");

        inventory.CreateInInventory("AmmoBox_308Win_20Rnd");
        inventory.CreateInInventory("AmmoBox_308Win_20Rnd");
        inventory.CreateInInventory("AmmoBox_308Win_20Rnd");
        inventory.CreateInInventory("AmmoBox_308Win_20Rnd");
        inventory.CreateInInventory("AmmoBox_308Win_20Rnd");
        inventory.CreateInInventory("AmmoBox_308Win_20Rnd");
    }

    static private void SpawnSVD(GameInventory inventory)
    {
        inventory.CreateInInventory("SVD");

        inventory.CreateInInventory("PSO1Optic");
        inventory.CreateInInventory("Battery9V");

        inventory.CreateInInventory("AK_Suppressor");

        Crates.SpawnEmptyMagazine(inventory, "Mag_SVD_10Rnd");
        Crates.SpawnEmptyMagazine(inventory, "Mag_SVD_10Rnd");
        Crates.SpawnEmptyMagazine(inventory, "Mag_SVD_10Rnd");

        inventory.CreateInInventory("AmmoBox_762x54_20Rnd");
        inventory.CreateInInventory("AmmoBox_762x54_20Rnd");
        inventory.CreateInInventory("AmmoBox_762x54_20Rnd");
    }

    static private void SpawnWeaponCrate(
            CGame game, CratePositions positions, string name)
    {
        GameInventory inventory = Crates.SpawnCrate(game, positions);

        if (name == "VSS")
        {
            SpawnVSS(inventory);
        }
        else if (name == "FAL")
        {
            SpawnFAL(inventory);
        }
        else if (name == "SVD")
        {
            SpawnSVD(inventory);
        }
    }

    static private void SpawnArmorCrate(CGame game, CratePositions positions)
    {
        GameInventory inventory = Crates.SpawnCrate(game, positions);

        inventory.CreateInInventory(VESTS.GetRandomElement());

        inventory.CreateInInventory(HELMETS.GetRandomElement());

        inventory.CreateInInventory(GLOVES.GetRandomElement());
    }

    static private void SpawnTrapCrate(CGame game, CratePositions positions)
    {
        GameInventory inventory = Crates.SpawnCrate(game, positions);

        inventory.CreateInInventory(TRAPS.GetRandomElement());
        inventory.CreateInInventory(TRAPS.GetRandomElement());

        inventory.CreateInInventory(GRENADES.GetRandomElement());
        inventory.CreateInInventory(GRENADES.GetRandomElement());
        inventory.CreateInInventory(GRENADES.GetRandomElement());
    }
}

// vim:ft=cs
