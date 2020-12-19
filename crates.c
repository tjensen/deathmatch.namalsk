class CratePositions
{
    private ref TVectorArray m_positions = {
        "6842.43 17.8126 11334.8",  // on top of yellow shipping container by North supermarket
        "6880.36 39.3823 11188.8",  // on vanilla construction crane
        "6863.28 58.3616 11298.7",  // on roof of East tall apartments
        "6744.81 58.1088 11372.8",  // on roof of West tall apartments
        "6599.16 58.3829 11338.0",  // on highest platform of smokestack
        "6590.21 40.9144 11366.2",  // on roof of factory stairwell
        "6943.16 33.5509 11463.6",  // on top of fire station tower
        "6809.60 26.5908 11251.0",  // on roof of school over cafeteria
        "6755.90 32.5514 10983.6",  // on highest roof of office building
        "6752.06 35.3789 11072.7",  // on roof of mod 4-story apartments with scaffolding
        "6988.18 45.7096 11285.9",  // on elevator shaft roof of Eastmost 8-story mod apartments
        "6591.33 45.1149 11263.2",  // on elevator shaft roof of Westmost 8-story mod apartments
        "6659.83 71.1773 11414.1",  // on mod construction crane at end of arm
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
        "6842.43 17.8126 11334.8",  // on top of yellow shipping container by North supermarket
        "6880.36 39.3823 11188.8",  // on vanilla construction crane
        "6863.28 58.3616 11298.7",  // on roof of East tall apartments
        "6744.81 58.1088 11372.8",  // on roof of West tall apartments
        "6599.16 58.3829 11338.0",  // on highest platform of smokestack
        "6590.21 40.9144 11366.2",  // on roof of factory stairwell
        "6943.16 33.5509 11463.6",  // on top of fire station tower
        "6809.60 26.5908 11251.0",  // on roof of school over cafeteria
        "6755.90 32.5514 10983.6",  // on highest roof of office building
        "6752.06 35.3789 11072.7",  // on roof of mod 4-story apartments with scaffolding
        "6988.18 45.7096 11285.9",  // on elevator shaft roof of Eastmost 8-story mod apartments
        "6591.33 45.1149 11263.2",  // on elevator shaft roof of Westmost 8-story mod apartments
        "6659.83 71.1773 11414.1",  // on mod construction crane at end of arm
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
