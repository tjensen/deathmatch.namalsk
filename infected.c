class Infected
{
    static private ref TVectorArray POSITIONS = {
        "6784.183594 15.066430 11285.520508",
        "6771.352539 14.457588 11269.403320",
        "6790.735352 15.019649 11257.916016",
        "6780.126465 15.013450 11242.509766",
        "6765.749512 14.939205 11232.805664",
        "6741.599121 15.099929 11244.019531",
        "6720.636719 15.006340 11220.804688",
        "6705.955078 15.012425 11190.069336",
        "6692.942871 15.012391 11164.122070",
        "6669.304199 15.044222 11142.613281",
        "6668.557617 15.052386 11108.140625",
        "6640.932617 15.043003 11087.150391",
        "6637.305664 15.102500 11050.697266",
        "6700.537109 15.132428 11028.620117",
        "6728.319824 15.202497 10987.439453",
        "6722.020020 15.157741 11015.386719",
        "6721.739746 15.147317 11074.734375",
        "6754.543457 15.133533 11103.314453",
        "6782.390137 15.143668 11136.727539",
        "6739.616699 14.889225 11157.235352",
        "6646.899902 15.030795 11169.843750",
        "6648.066406 15.012496 11206.022461",
        "6645.814941 15.065917 11232.723633",
        "6653.910156 15.223911 11268.119141",
        "6623.399902 15.042478 11294.906250",
        "6614.834961 15.042422 11321.968750",
        "6640.097656 15.042500 11362.413086",
        "6646.416504 15.042500 11399.889648",
        "6681.701660 15.042433 11403.049805",
        "6695.236328 15.042468 11362.647461",
        "6730.889160 15.186091 11361.755859",
        "6782.621094 15.122472 11382.272461",
        "6827.494629 15.172486 11381.819336",
        "6873.933105 16.162659 11381.077148",
        "6923.598145 15.483494 11399.403320",
        "6899.089844 15.142081 11438.586914",
        "6928.288574 15.277870 11449.418945",
        "6948.306641 15.334351 11459.896484",
        "6966.195313 15.195316 11435.947266",
        "6970.858887 15.396772 11411.706055",
        "6883.115234 15.310733 11344.580078",
        "6857.945801 15.591326 11309.906250",
        "6830.748047 15.191681 11277.549805",
        "6806.068359 14.972486 11262.542969",
        "6822.385254 14.887427 11224.444336",
        "6761.320801 14.835117 11165.024414",
    };

    static private ref TStringArray TYPES = {
        "ZmbF_BlueCollarFat_Blue", "ZmbF_BlueCollarFat_Green", "ZmbF_BlueCollarFat_Red",
        "ZmbF_BlueCollarFat_White", "ZmbF_CitizenANormal_Beige", "ZmbF_CitizenANormal_Blue",
        "ZmbF_CitizenANormal_Brown", "ZmbF_CitizenBSkinny", "ZmbF_Clerk_Normal_Blue",
        "ZmbF_Clerk_Normal_Green", "ZmbF_Clerk_Normal_Red", "ZmbF_Clerk_Normal_White",
        "ZmbF_DoctorSkinny", "ZmbF_HikerSkinny_Blue", "ZmbF_HikerSkinny_Green",
        "ZmbF_HikerSkinny_Grey", "ZmbF_HikerSkinny_Red", "ZmbF_JoggerSkinny_Blue",
        "ZmbF_JoggerSkinny_Brown", "ZmbF_JoggerSkinny_Green", "ZmbF_JoggerSkinny_Red",
        "ZmbF_JournalistNormal_Blue", "ZmbF_JournalistNormal_Green", "ZmbF_JournalistNormal_Red",
        "ZmbF_JournalistNormal_White", "ZmbF_MechanicNormal_Beige", "ZmbF_MechanicNormal_Green",
        "ZmbF_MechanicNormal_Grey", "ZmbF_MechanicNormal_Orange", "ZmbF_MilkMaidOld_Beige",
        "ZmbF_MilkMaidOld_Black", "ZmbF_MilkMaidOld_Green", "ZmbF_MilkMaidOld_Grey",
        "ZmbF_NurseFat", "ZmbF_ParamedicNormal_Blue", "ZmbF_ParamedicNormal_Green",
        "ZmbF_ParamedicNormal_Red", "ZmbF_PatientOld", "ZmbF_PoliceWomanNormal",
        "ZmbF_ShortSkirt_beige", "ZmbF_ShortSkirt_black", "ZmbF_ShortSkirt_brown",
        "ZmbF_ShortSkirt_checks", "ZmbF_ShortSkirt_green", "ZmbF_ShortSkirt_grey",
        "ZmbF_ShortSkirt_red", "ZmbF_ShortSkirt_stripes", "ZmbF_ShortSkirt_white",
        "ZmbF_ShortSkirt_yellow", "ZmbF_SkaterYoung_Brown", "ZmbF_SkaterYoung_Striped",
        "ZmbF_SkaterYoung_Violet", "ZmbF_SurvivorNormal_Blue", "ZmbF_SurvivorNormal_Orange",
        "ZmbF_SurvivorNormal_Red", "ZmbF_SurvivorNormal_White", "ZmbF_VillagerOld_Blue",
        "ZmbF_VillagerOld_Green", "ZmbF_VillagerOld_Red", "ZmbF_VillagerOld_White",
        "ZmbM_CitizenASkinny_Blue", "ZmbM_CitizenASkinny_Brown", "ZmbM_CitizenASkinny_Grey",
        "ZmbM_CitizenASkinny_Red", "ZmbM_CitizenBFat_Blue", "ZmbM_CitizenBFat_Green",
        "ZmbM_CitizenBFat_Red", "ZmbM_ClerkFat_Brown", "ZmbM_ClerkFat_Grey", "ZmbM_ClerkFat_Khaki",
        "ZmbM_ClerkFat_White", "ZmbM_CommercialPilotOld_Blue", "ZmbM_CommercialPilotOld_Brown",
        "ZmbM_CommercialPilotOld_Grey", "ZmbM_CommercialPilotOld_Olive",
        "ZmbM_ConstrWorkerNormal_Beige", "ZmbM_ConstrWorkerNormal_Black",
        "ZmbM_ConstrWorkerNormal_Green", "ZmbM_ConstrWorkerNormal_Grey", "ZmbM_DoctorFat",
        "ZmbM_FarmerFat_Beige", "ZmbM_FarmerFat_Blue", "ZmbM_FarmerFat_Brown",
        "ZmbM_FarmerFat_Green", "ZmbM_FirefighterNormal", "ZmbM_FishermanOld_Blue",
        "ZmbM_FishermanOld_Green", "ZmbM_FishermanOld_Grey", "ZmbM_FishermanOld_Red",
        "ZmbM_HandymanNormal_Beige", "ZmbM_HandymanNormal_Blue", "ZmbM_HandymanNormal_Green",
        "ZmbM_HandymanNormal_Grey", "ZmbM_HandymanNormal_White", "ZmbM_HeavyIndustryWorker",
        "ZmbM_HermitSkinny_Beige", "ZmbM_HermitSkinny_Black", "ZmbM_HermitSkinny_Green",
        "ZmbM_HermitSkinny_Red", "ZmbM_HikerSkinny_Blue", "ZmbM_HikerSkinny_Green",
        "ZmbM_HikerSkinny_Yellow", "ZmbM_HunterOld_Autumn", "ZmbM_HunterOld_Spring",
        "ZmbM_HunterOld_Summer", "ZmbM_HunterOld_Winter", "ZmbM_Jacket_beige", "ZmbM_Jacket_black",
        "ZmbM_Jacket_blue", "ZmbM_Jacket_bluechecks", "ZmbM_Jacket_brown",
        "ZmbM_Jacket_greenchecks", "ZmbM_Jacket_grey", "ZmbM_Jacket_khaki", "ZmbM_Jacket_magenta",
        "ZmbM_Jacket_stripes", "ZmbM_JoggerSkinny_Blue", "ZmbM_JoggerSkinny_Green",
        "ZmbM_JoggerSkinny_Red", "ZmbM_JournalistSkinny", "ZmbM_MechanicSkinny_Blue",
        "ZmbM_MechanicSkinny_Green", "ZmbM_MechanicSkinny_Grey", "ZmbM_MechanicSkinny_Red",
        "ZmbM_MotobikerFat_Beige", "ZmbM_MotobikerFat_Black", "ZmbM_MotobikerFat_Blue",
        "ZmbM_OffshoreWorker_Green", "ZmbM_OffshoreWorker_Orange", "ZmbM_OffshoreWorker_Red",
        "ZmbM_OffshoreWorker_Yellow", "ZmbM_ParamedicNormal_Black", "ZmbM_ParamedicNormal_Blue",
        "ZmbM_ParamedicNormal_Green", "ZmbM_ParamedicNormal_Red", "ZmbM_PatientSkinny",
        "ZmbM_PatrolNormal_Autumn", "ZmbM_PatrolNormal_Flat", "ZmbM_PatrolNormal_PautRev",
        "ZmbM_PatrolNormal_Summer", "ZmbM_PolicemanFat", "ZmbM_PolicemanSpecForce",
        "ZmbM_PrisonerSkinny", "ZmbM_SkaterYoung_Blue", "ZmbM_SkaterYoung_Brown",
        "ZmbM_SkaterYoung_Green", "ZmbM_SkaterYoung_Grey", "ZmbM_SoldierNormal",
        "ZmbM_VillagerOld_Blue", "ZmbM_VillagerOld_Green", "ZmbM_VillagerOld_White",
        "ZmbM_priestPopSkinny", "ZmbM_usSoldier_normal_Desert", "ZmbM_usSoldier_normal_Woodland"
    };
    static private ref TStringArray CHRISTMAS_TYPES = {
        "ZmbF_BlueCollarFat_Red", "ZmbF_Clerk_Normal_Red", "ZmbF_HikerSkinny_Red",
        "ZmbF_JoggerSkinny_Red", "ZmbF_JournalistNormal_Red", "ZmbF_ParamedicNormal_Red",
        "ZmbF_ShortSkirt_red", "ZmbF_SurvivorNormal_Red", "ZmbF_VillagerOld_Red",
        "ZmbM_CitizenASkinny_Red", "ZmbM_CitizenBFat_Red", "ZmbM_FishermanOld_Red",
        "ZmbM_HermitSkinny_Red", "ZmbM_JoggerSkinny_Red", "ZmbM_MechanicSkinny_Red",
        "ZmbM_OffshoreWorker_Red"
    };
    static private ref TStringArray COWBOY_HATS = {
        "CowboyHat_Brown", "CowboyHat_black", "CowboyHat_darkBrown", "CowboyHat_green"
    };

    static string InfectedType(bool christmas)
    {
        if (christmas)
        {
            return CHRISTMAS_TYPES.GetRandomElement();
        }

        return TYPES.GetRandomElement();
    }

    static void Spawn(
            CGame game, int playerCount, int playerScaleFactor, int minimum, int maximum,
            bool christmas, bool cowboy)
    {
        int infectedCount = playerCount * playerScaleFactor;
        if (infectedCount < minimum) infectedCount = minimum;
        if (infectedCount > maximum) infectedCount = maximum;

        Print("Spawning " + infectedCount + " infected");
        for (int i = 0; i < infectedCount; i++)
        {
            string infectedType = InfectedType(christmas);
            vector position = POSITIONS.GetRandomElement();
            Object infected = game.CreateObject(infectedType, position, false, true, true);
            if (cowboy)
            {
                EntityAI.Cast(infected).GetInventory().CreateAttachment(
                        COWBOY_HATS.GetRandomElement());
            }
            else if (christmas)
            {
                EntityAI.Cast(infected).GetInventory().CreateAttachment("SantasHat");
            }
            Print("Spawned " + infectedType + " at " + position);
        }
        Print("Done spawning infected");
    }
}

// vim:ft=cs
