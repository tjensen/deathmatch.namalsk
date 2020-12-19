class Webhook : Managed
{
    string type;
    string url;
}

class DeathmatchSettings : Managed
{
    int maxRounds = 0;
    int roundMinutes = 0;

    int infectedChance = 0;
    int infectedPlayerFactor = 0;
    int minimumInfected = 0;
    int maximumInfected = 0;

    int cowboyRoundChance = 0;

    int christmas = 0;

    ref Webhook killFeedWebhook = new Webhook();

    void load()
    {
        JsonFileLoader<ref DeathmatchSettings>.JsonLoadFile("$profile:deathmatch-settings.json", this);

        Print("Max rounds: " + this.maxRounds);

        if (this.roundMinutes < 1) this.roundMinutes = 30;
        Print("Round duration: " + this.roundMinutes);

        if (this.infectedChance < 0) this.infectedChance = 0;
        if (this.infectedChance > 100) this.infectedChance = 100;
        Print("Infected chance: " + this.infectedChance);

        if (this.infectedPlayerFactor < 1) this.infectedPlayerFactor = 5;
        Print("Infected player factor: " + this.infectedPlayerFactor);

        if (this.minimumInfected < 1) this.minimumInfected = 25;
        Print("Minimum infected: " + this.minimumInfected);

        if (this.maximumInfected < 1) this.maximumInfected = 50;
        Print("Maximum infected: " + this.maximumInfected);

        if (this.cowboyRoundChance < 0) this.cowboyRoundChance = 0;
        if (this.cowboyRoundChance > 100) this.cowboyRoundChance = 100;
        Print("Cowboy round chance: " + this.cowboyRoundChance);

        Print("Christmas: " + this.christmas);

        Print("Kill feed webhook: " + this.killFeedWebhook.type + " (" + this.killFeedWebhook.url.Substring(0, this.killFeedWebhook.url.Length() / 4) + "...)");
    }
}
