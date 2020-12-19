class Infected
{
    static private ref TVectorArray POSITIONS = {
        "7697.10 296.762 2744.83",
        "7693.67 296.762 2736.43",
        "7686.79 296.762 2723.84",
        "7674.64 296.762 2718.06",
        "7691.71 296.762 2690.22",
        "7654.47 296.504 2708.49",
        "7647.78 296.743 2690.91",
        "7639.65 296.762 2676.05",
        "7626.63 296.762 2665.91",
        "7610.70 296.762 2659.31",
        "7618.15 296.762 2635.58",
        "7636.24 296.762 2625.15",
        "7593.92 296.242 2637.05",
        "7570.84 289.222 2601.04",
        "7573.18 289.222 2577.60",
        "7544.26 289.099 2577.48",
        "7529.51 288.341 2577.65",
        "7508.67 287.787 2585.89",
        "7506.49 287.052 2558.73",
        "7499.92 287.052 2544.58",
        "7514.20 287.052 2530.29",
        "7509.86 287.052 2521.04",
        "7498.01 287.052 2514.16",
        "7495.70 287.052 2531.50",
        "7470.60 287.052 2533.41",
        "7472.27 287.052 2544.37",
        "7475.59 287.052 2553.90",
        "7481.74 287.052 2565.05",
        "7469.77 287.052 2565.47",
        "7460.14 287.052 2574.66",
        "7448.24 287.052 2586.85",
        "7435.97 287.052 2578.33",
        "7433.83 287.052 2565.81",
        "7425.80 287.052 2558.29",
        "7451.47 287.052 2530.26",
        "7443.19 287.190 2539.98",
        "7428.62 287.180 2544.94",
        "7407.57 287.199 2552.89",
        "7387.52 287.032 2553.66",
        "7370.32 287.184 2558.23",
        "7367.06 287.052 2570.62",
        "7376.70 287.052 2584.10",
        "7378.29 287.052 2596.86",
        "7367.21 287.052 2600.54",
        "7363.12 287.052 2610.45",
        "7360.68 287.052 2620.97",
        "7345.85 287.052 2612.33",
        "7330.14 287.052 2605.29",
        "7351.56 287.052 2587.92",
        "7340.58 287.052 2588.27",
        "7340.11 287.240 2572.87",
        "7355.50 287.240 2571.64",
        "7329.08 287.052 2569.60",
        "7317.92 287.257 2572.84",
        "7303.32 287.254 2574.45",
        "7337.95 287.024 2656.51",
        "7308.99 287.052 2584.82",
        "7301.18 287.052 2590.30",
        "7308.33 287.052 2600.63",
        "7303.79 287.125 2611.80",
        "7315.61 287.052 2607.47",
        "7317.32 290.511 2618.90",
        "7321.73 287.052 2628.49",
        "7336.09 287.052 2635.37",
        "7280.72 287.052 2588.48",
        "7258.44 287.052 2569.67",
        "7280.31 287.068 2547.09",
        "7343.05 287.052 2549.70",
        "7378.20 287.028 2544.85",
        "7410.83 287.022 2535.11",
        "7433.85 287.025 2522.18",
        "7468.50 287.052 2496.98",
        "7430.40 287.052 2599.30",
        "7412.43 287.052 2593.84",
        "7414.28 287.052 2618.27",
        "7392.03 287.052 2606.64",
        "7380.74 287.052 2621.21",
        "7376.94 287.052 2641.16",
        "7369.99 287.052 2655.92",
        "7375.40 287.052 2672.40",
        "7370.58 287.835 2691.51",
        "7379.65 288.266 2706.58",
        "7369.47 288.136 2728.29",
        "7390.81 288.578 2730.02",
        "7390.44 288.752 2748.62",
        "7395.43 288.602 2764.57",
        "7377.05 288.752 2771.47",
        "7382.06 288.733 2791.05",
        "7373.23 288.935 2806.60",
        "7380.10 289.502 2826.11",
        "7373.87 289.502 2844.42",
        "7377.78 289.502 2856.14",
        "7373.67 289.502 2870.05",
        "7356.25 289.502 2870.19",
        "7339.70 289.502 2874.49",
        "7339.52 290.619 2893.13",
        "7326.93 292.309 2906.07",
        "7327.01 293.381 2923.94",
        "7315.47 293.272 2934.53",
        "7314.09 293.275 2953.80",
        "7296.15 293.272 2965.21",
        "7289.10 293.272 2973.59",
        "7269.96 293.272 2968.69",
        "7277.74 293.312 2949.64",
        "7265.60 293.272 2939.53",
        "7251.61 293.272 2936.62",
        "7250.14 293.272 2912.38",
        "7257.78 293.009 2899.48",
        "7263.09 292.831 2888.89",
        "7277.01 291.932 2877.33",
        "7297.15 292.197 2887.42",
        "7305.33 293.284 2908.81",
        "7296.80 293.262 2924.42",
        "7318.09 289.768 2876.14",
        "7313.73 289.262 2867.30",
        "7295.99 289.262 2856.89",
        "7286.95 289.283 2847.73",
        "7295.73 289.262 2831.95",
        "7302.73 289.363 2819.70",
        "7311.58 289.262 2803.81",
        "7321.14 289.262 2799.14",
        "7331.82 289.262 2808.27",
        "7327.50 289.262 2840.44",
        "7339.51 289.262 2842.99",
        "7352.84 289.309 2829.63",
        "7358.89 289.262 2814.91",
        "7351.01 289.295 2801.88",
        "7344.56 288.616 2781.33",
        "7322.87 288.752 2771.83",
        "7318.84 289.635 2741.80",
        "7316.03 290.918 2728.34",
        "7315.02 290.863 2716.27",
        "7314.45 288.910 2700.50",
        "7352.91 288.012 2731.40",
        "7342.53 288.012 2734.00",
        "7334.06 288.012 2718.96",
        "7336.24 288.012 2705.33",
        "7354.92 288.012 2693.32",
        "7344.35 288.012 2691.37",
        "7335.92 287.436 2684.38",
        "7317.73 287.052 2674.91",
        "7319.14 287.052 2664.66",
        "7349.53 287.052 2669.16",
        "7310.32 287.052 2651.00",
        "7305.65 287.052 2635.89",
        "7311.63 299.959 2837.64",
        "7319.73 299.959 2824.77",
        "7382.46 297.237 2570.27",
        "7670.21 307.399 2690.44",
        "7660.63 307.302 2659.81",
        "7634.83 307.302 2655.25",
        "7366.47 290.383 2625.86",
        "7355.20 292.833 2824.18",
        "7264.21 300.673 2960.72"
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
