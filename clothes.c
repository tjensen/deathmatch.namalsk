class Clothes
{
    static private ref TStringArray Tops = {
        "BDUJacket", "Blouse_Green", "BomberJacket_Black", "BomberJacket_Brown",
        "BomberJacket_Olive", "DenimJacket", "HikingJacket_Black", "HikingJacket_Green",
        "Hoodie_Black", "Hoodie_Brown", "Hoodie_Green", "HuntingJacket_Brown",
        "HuntingJacket_Summer", "LabCoat", "M65Jacket_Black", "M65Jacket_Olive",
        "ParamedicJacket_Green", "PrisonUniformJacket", "QuiltedJacket_Black",
        "QuiltedJacket_Green", "TacticalShirt_Black", "TacticalShirt_Olive", "WoolCoat_Black"
    };
    static private ref TStringArray ChristmasTops = {
        "Blouse_Green", "HikingJacket_Green", "HikingJacket_Red", "Hoodie_Green", "Hoodie_Red",
        "JumpsuitJacket_Green", "JumpsuitJacket_Red", "MedicalScrubsShirt_Green",
        "MiniDress_GreenChecker", "MiniDress_RedChecker", "ParamedicJacket_Crimson",
        "ParamedicJacket_Green", "QuiltedJacket_Green", "QuiltedJacket_Red", "Raincoat_Green",
        "Raincoat_Red", "Shirt_GreenCheck", "Shirt_RedCheck", "Sweater_Green", "Sweater_Red",
        "TShirt_Green", "TShirt_Red", "TShirt_RedBlackStripes", "TrackSuitJacket_Green",
        "TrackSuitJacket_Red", "WoolCoat_Green", "WoolCoat_Red", "WoolCoat_RedCheck"
    };
    static private ref TStringArray Bottoms = {
        "BDUPants", "CargoPants_Black", "CargoPants_Green", "HunterPants_Brown",
        "HunterPants_Summer", "Jeans_Black", "Jeans_Brown", "Jeans_Green", "ParamedicPants_Green",
        "PrisonUniformPants", "ShortJeans_Black", "ShortJeans_Brown", "ShortJeans_Green"
    };
    static private ref TStringArray ChristmasBottoms = {
        "Breeches_Green", "Breeches_Red", "CanvasPantsMidi_Red", "CanvasPants_Red",
        "CargoPants_Green", "Jeans_Green", "JumpsuitPants_Green", "JumpsuitPants_Red",
        "MedicalScrubsPants_Green", "ParamedicPants_Crimson", "ParamedicPants_Green",
        "ShortJeans_Green", "ShortJeans_Red", "Skirt_Red", "TrackSuitPants_Green",
        "TrackSuitPants_Red"
    };
    static private ref TStringArray Shoes = {
        "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "CombatBoots_Beige",
        "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey",
        "HikingBoots_Black", "HikingBoots_Brown", "JungleBoots_Black", "JungleBoots_Brown",
        "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Black", "MilitaryBoots_Brown",
        "Sneakers_Black", "Sneakers_Green", "Wellies_Black", "Wellies_Brown", "Wellies_Green",
        "WorkingBoots_Brown", "WorkingBoots_Green"
    };
    static private ref TStringArray ChristmasShoes = {
        "AthleticShoes_Green", "JoggingShoes_Red", "JungleBoots_Green", "MilitaryBoots_Redpunk",
        "Sneakers_Green", "Sneakers_Red", "WorkingBoots_Green"
    };
    static private ref TStringArray Vests = {
        "UKAssVest_Black", "UKAssVest_Camo", "UKAssVest_Khaki",
        "UKAssVest_Olive", "SmershVest"
    };
    static private ref TStringArray ChristmasVests = {
        "UKAssVest_Camo", "UKAssVest_Olive", "SmershVest"
    };
    static private ref TStringArray Hats = {
        "BeanieHat_Beige", "BeanieHat_Black", "BeanieHat_Blue", "BeanieHat_Brown",
        "BeanieHat_Green", "BeanieHat_Grey", "BeanieHat_Pink", "BeanieHat_Red", "BoonieHat_Black",
        "BoonieHat_Blue", "BoonieHat_DPM", "BoonieHat_Dubok","BoonieHat_Flecktran",
        "BoonieHat_NavyBlue", "BoonieHat_Olive", "BoonieHat_Orange", "BoonieHat_Red",
        "BoonieHat_Tan", "CowboyHat_Brown", "CowboyHat_black", "CowboyHat_darkBrown",
        "CowboyHat_green", "OfficerHat", "BaseballCap_Beige", "BaseballCap_Blue",
        "BaseballCap_Black", "BaseballCap_CMMG_Black", "BaseballCap_CMMG_Pink", "BaseballCap_Camo",
        "BaseballCap_Olive", "BaseballCap_Pink", "BaseballCap_Red"
    };
    static private ref TStringArray Glasses = {
        "AviatorGlasses", "DesignerGlasses", "SportGlasses_Black", "SportGlasses_Blue",
        "SportGlasses_Green", "SportGlasses_Orange", "ThickFramesGlasses", "ThinFramesGlasses"
    };
    static private ref TStringArray Belts = {"CivilianBelt", "MilitaryBelt"};
    static private ref TStringArray PPE = {"NioshFaceMask", "SurgicalMask"};

    static private ref TStringArray CowboyTops = {
        "Shirt_BlueCheck", "Shirt_BlueCheckBright", "Shirt_GreenCheck", "Shirt_RedCheck",
        "Shirt_WhiteCheck"
    };
    static private ref TStringArray CowboyBottoms = {
        "Jeans_Black", "Jeans_Brown", "Jeans_Green", "Jeans_Blue", "Jeans_BlueDark", "Jeans_Grey"
    };
    static private ref TStringArray CowboyShoes = {
        "CombatBoots_Beige", "CombatBoots_Brown", "HikingBoots_Brown", "JungleBoots_Brown",
        "MilitaryBoots_Brown", "Wellies_Brown", "WorkingBoots_Beige", "WorkingBoots_Brown"
    };
    static private ref TStringArray CowboyHats = {
        "CowboyHat_Brown", "CowboyHat_black", "CowboyHat_darkBrown", "CowboyHat_green"
    };
    static private ref TStringArray CowboyMasks = {
        "BandanaMask_BlackPattern", "BandanaMask_CamoPattern", "BandanaMask_GreenPattern",
        "BandanaMask_PolkaPattern", "BandanaMask_RedPattern"
    };

    EntityAI EquipPlayerClothes(PlayerBase player, bool christmas, bool cowboy)
    {
        HumanInventory inventory = player.GetHumanInventory();

        if (cowboy)
        {
            this.EquipCowboy(inventory);
        }
        else if (christmas)
        {
            this.EquipChristmas(inventory);
        }
        else
        {
            this.EquipNormal(inventory);
        }

        EntityAI belt = inventory.CreateInInventory(Belts.GetRandomElement());
        return belt.GetInventory().CreateAttachment("NylonKnifeSheath");
    }

    private void EquipNormal(HumanInventory inventory)
    {
        inventory.CreateInInventory(Tops.GetRandomElement());
        inventory.CreateInInventory(Bottoms.GetRandomElement());
        inventory.CreateInInventory(Shoes.GetRandomElement());
        inventory.CreateInInventory(Vests.GetRandomElement());
        inventory.CreateInInventory(PPE.GetRandomElement());

        if (Math.RandomInt(0, 2))
        {
            inventory.CreateInInventory(Hats.GetRandomElement());
        }

        this.EquipGlasses(inventory);
    }

    private void EquipChristmas(HumanInventory inventory)
    {
        inventory.CreateInInventory(ChristmasTops.GetRandomElement());
        inventory.CreateInInventory(ChristmasBottoms.GetRandomElement());
        inventory.CreateInInventory(ChristmasShoes.GetRandomElement());
        inventory.CreateInInventory(ChristmasVests.GetRandomElement());
        inventory.CreateInInventory("SantasBeard");
        inventory.CreateInInventory("SantasHat");
        this.EquipGlasses(inventory);
    }

    private void EquipCowboy(HumanInventory inventory)
    {
        inventory.CreateInInventory(CowboyTops.GetRandomElement());
        inventory.CreateInInventory(CowboyBottoms.GetRandomElement());
        inventory.CreateInInventory(CowboyShoes.GetRandomElement());
        inventory.CreateInInventory(CowboyMasks.GetRandomElement());
        inventory.CreateInInventory(CowboyHats.GetRandomElement());
    }

    private void EquipGlasses(HumanInventory inventory)
    {
        if (Math.RandomInt(0, 2))
        {
            inventory.CreateInInventory(Glasses.GetRandomElement());
        }
    }
}

// vim:ft=cs
