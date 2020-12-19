class RangedWeapon
{
    EntityAI CreateInInventory(HumanInventory inventory)
    {
        EntityAI weapon = inventory.CreateInInventory(GetName());
        return Equip(inventory, weapon);
    }

    EntityAI CreateInHands(HumanInventory inventory)
    {
        EntityAI weapon = inventory.CreateInHands(GetName());
        return Equip(inventory, weapon);
    }

    private EntityAI Equip(HumanInventory inventory, EntityAI weapon)
    {
        GameInventory weaponInventory = weapon.GetInventory();

        EntityAI optic = CreateAttachment(weaponInventory, GetOptic());
        if (optic != null)
        {
            optic.GetInventory().CreateAttachment("Battery9V");
        }

        CreateAttachment(weaponInventory, GetHandguard());
        CreateAttachment(weaponInventory, GetButtstock());

        string ammunition = GetAmmunition();
        inventory.CreateInInventory(ammunition);
        inventory.CreateInInventory(ammunition);
        inventory.CreateInInventory(ammunition);

        return weapon;
    }

    private EntityAI CreateAttachment(GameInventory inventory, string attachment)
    {
        if (attachment == "") return null;

        return inventory.CreateAttachment(attachment);
    }

    string GetName() {return "";}
    string GetAmmunition() {return "";}
    string GetOptic() {return "";}
    string GetHandguard() {return "";}
    string GetButtstock() {return "";}
}


class FixedRangedWeapon extends RangedWeapon
{
    private string m_name;
    private string m_ammunition;
    private string m_optic;
    private string m_handguard;
    private string m_buttstock;

    void Init(
        string name, string ammunition, string optic = "", string handguard = "",
        string buttstock = "")
    {
        m_name = name;
        m_ammunition = ammunition;
        m_optic = optic;
        m_handguard = handguard;
        m_buttstock = buttstock;
    }

    string GetName()
    {
        return m_name;
    }

    string GetAmmunition()
    {
        return m_ammunition;
    }

    string GetOptic()
    {
        return m_optic;
    }

    string GetHandguard()
    {
        return m_handguard;
    }

    string GetButtstock()
    {
        return m_buttstock;
    }
}


class RandomRangedWeapon extends RangedWeapon
{
    static ref TStringArray EMPTY = new TStringArray();

    private TStringArray m_names;
    private string m_ammunition;
    private TStringArray m_optics;
    private TStringArray m_handguards;
    private TStringArray m_buttstocks;

    void Init(
        TStringArray names, string ammunition, TStringArray optics = EMPTY,
        TStringArray handguards = EMPTY, TStringArray buttstocks = EMPTY)
    {
        m_names = names;
        m_optics = optics;
        m_handguards = handguards;
        m_buttstocks = buttstocks;
        m_ammunition = ammunition;
    }

    string GetName()
    {
        return GetRandomElement(m_names);
    }

    string GetAmmunition()
    {
        return m_ammunition;
    }

    string GetOptic()
    {
        return GetRandomElement(m_optics);
    }

    string GetHandguard()
    {
        return GetRandomElement(m_handguards);
    }

    string GetButtstock()
    {
        return GetRandomElement(m_buttstocks);
    }

    private string GetRandomElement(TStringArray elements)
    {
        if (elements == null) return "";
        if (elements.Count() == 0) return "";

        return elements.GetRandomElement();
    }
}


class Winchester extends FixedRangedWeapon
{
    void Winchester()
    {
        Init("Winchester70", "Ammo_308Win", "HuntingOptic");
    }
}


class Blaze extends FixedRangedWeapon
{
    void Blaze()
    {
        Init("B95", "Ammo_308Win", "HuntingOptic");
    }
}


class Mosin extends RandomRangedWeapon
{
    static private ref TStringArray Names = {
        "Mosin9130", "Mosin9130_Black", "Mosin9130_Camo", "Mosin9130_Green"
    };
    static private ref TStringArray Optics = {"PUScopeOptic"};

    void Mosin()
    {
        Init(Names, "Ammo_762x54", Optics);
    }
}


class SKS extends FixedRangedWeapon
{
    void SKS()
    {
        Init("SKS", "Ammo_762x39", "PUScopeOptic");
    }
}


class MP5 extends RandomRangedWeapon
{
    static private ref TStringArray Names = {"MP5K"};
    static private ref TStringArray Optics = {"M68Optic", "M4_T3NRDSOptic", "ReflexOptic"};
    static private ref TStringArray Handguards = {"MP5_PlasticHndgrd", "MP5_RailHndgrd"};
    static private ref TStringArray Buttstocks = {"MP5k_StockBttstck"};

    void MP5()
    {
        Init(Names, "Mag_MP5_30Rnd", Optics, Handguards, Buttstocks);
    }
}


class UMP extends RandomRangedWeapon
{
    static private ref TStringArray Names = {"UMP45"};
    static private ref TStringArray Optics = {"M68Optic", "M4_T3NRDSOptic", "ReflexOptic"};

    void UMP()
    {
        Init(Names, "Mag_UMP_25Rnd", Optics);
    }
}

class KAS74U extends RandomRangedWeapon
{
    static private ref TStringArray Names = {"AKS74U", "AKS74U_Black", "AKS74U_Green"};
    static private ref TStringArray Buttstocks = {
        "AK_FoldingBttstck", "AK_FoldingBttstck_Black", "AK_FoldingBttstck_Green",
        "AK_PlasticBttstck", "AK_PlasticBttstck_Black", "AK_PlasticBttstck_Green",
        "AK_WoodBttstck"," AK_WoodBttstck_Black", "AK_WoodBttstck_Camo", "AK74_WoodBttstck",
        "AKS74U_Bttstck"
    };

    void KAS74U()
    {
        Init(Names, "Mag_AK74_30Rnd", EMPTY, EMPTY, Buttstocks);
    }
}


class M4A1 extends RandomRangedWeapon
{
    static private ref TStringArray Names = {"M4A1", "M4A1_Black", "M4A1_Green"};
    static private ref TStringArray Optics = {"M68Optic", "M4_T3NRDSOptic", "ReflexOptic"};
    static private ref TStringArray Handguards = {
        "M4_MPHndgrd", "M4_PlasticHndgrd", "M4_RISHndgrd"
    };
    static private ref TStringArray Buttstocks = {"M4_CQBBttstck", "M4_MPBttstck", "M4_OEBttstck"};

    void M4A1()
    {
        Init(Names, "Mag_STANAG_30Rnd", Optics, Handguards, Buttstocks);
    }
}


class AKWeapon extends RandomRangedWeapon
{
    static private ref TStringArray Optics = {"KobraOptic"};
    static private ref TStringArray Handguards = {
        "AK_PlasticHndgrd", "AK_RailHndgrd", "AK_RailHndgrd_Black", "AK_RailHndgrd_Green",
        "AK_WoodHndgrd", "AK_WoodHndgrd_Black", "AK_WoodHndgrd_Camo", "AK74_Hndgrd"
    };
    static private ref TStringArray Buttstocks = {
        "AK_FoldingBttstck", "AK_FoldingBttstck_Black", "AK_FoldingBttstck_Green",
        "AK_PlasticBttstck", "AK_PlasticBttstck_Black", "AK_PlasticBttstck_Green",
        "AK_WoodBttstck"," AK_WoodBttstck_Black", "AK_WoodBttstck_Camo", "AK74_WoodBttstck",
        "AKS74U_Bttstck"
    };

    void InitAK(TStringArray names, string ammunition)
    {
        Init(names, ammunition, Optics, Handguards, Buttstocks);
    }
}


class KA101 extends AKWeapon
{
    static private ref TStringArray Names = {"AK101", "AK101_Black", "AK101_Green"};

    void KA101()
    {
        InitAK(Names, "Mag_AK101_30Rnd");
    }
}


class KA74 extends AKWeapon
{
    static private ref TStringArray Names = {"AK74", "AK74_Black", "AK74_Green"};

    void KA74()
    {
        InitAK(Names, "Mag_AK74_30Rnd");
    }
}


class AKM extends AKWeapon
{
    static private ref TStringArray Names = {"AKM"};

    void AKM()
    {
        InitAK(Names, "Mag_AKM_30Rnd");
    }
}


class Shotgun extends RandomRangedWeapon
{
    static private ref TStringArray Names = {"Izh43Shotgun", "Mp133Shotgun"};

    void Shotgun()
    {
        Init(Names, "Ammo_12gaPellets");
    }
}


class Vaiga extends FixedRangedWeapon
{
    void Vaiga()
    {
        Init("Saiga", "Mag_Saiga_8Rnd", "", "", "Saiga_Bttstck");
    }
}


class CZ527 extends FixedRangedWeapon
{
    void CZ527()
    {
        Init("CZ527", "Mag_CZ527_5rnd", "HuntingOptic");
    }
}


class Weapons
{
    static private ref TStringArray Knives = {
        "CombatKnife", "HuntingKnife", "KitchenKnife", "SteakKnife"
    };

    private autoptr array<ref RangedWeapon> PrimaryWeapons = new array<ref RangedWeapon>();
    private autoptr array<ref RangedWeapon> SecondaryWeapons = new array<ref RangedWeapon>();

    void Weapons()
    {
        PrimaryWeapons.Insert(new MP5());
        PrimaryWeapons.Insert(new UMP());
        PrimaryWeapons.Insert(new KAS74U());
        PrimaryWeapons.Insert(new M4A1());
        PrimaryWeapons.Insert(new KA101());
        PrimaryWeapons.Insert(new KA74());
        PrimaryWeapons.Insert(new AKM());
        PrimaryWeapons.Insert(new Shotgun());
        PrimaryWeapons.Insert(new Vaiga());

        SecondaryWeapons.Insert(new Winchester());
        SecondaryWeapons.Insert(new Blaze());
        SecondaryWeapons.Insert(new Mosin());
        SecondaryWeapons.Insert(new SKS());
        SecondaryWeapons.Insert(new CZ527());
    }

    void EquipPlayerWeapons(PlayerBase player, EntityAI sheath, bool cowboy)
    {
        HumanInventory inventory = player.GetHumanInventory();
        EntityAI primary = EquipPrimaryWeapon(inventory, cowboy);
        EntityAI secondary = EquipSecondaryWeapon(inventory, cowboy);
        EntityAI melee = EquipKnifeInSheath(sheath, cowboy);

        player.SetQuickBarEntityShortcut(primary, 0);
        player.SetQuickBarEntityShortcut(secondary, 1);
        player.SetQuickBarEntityShortcut(melee, 2);

        player.TakeEntityToHandsImpl(InventoryMode.SERVER, primary);
    }

    private EntityAI EquipPrimaryWeapon(HumanInventory inventory, bool cowboy)
    {
        if (cowboy)
        {
            EntityAI holster = inventory.CreateInInventory("ChestHolster");
            EntityAI primary = holster.GetInventory().CreateAttachment("Magnum");
            inventory.CreateInInventory("Ammo_357");
            inventory.CreateInInventory("Ammo_357");
            inventory.CreateInInventory("Ammo_357");
            return primary;
        }
        else
        {
            return PrimaryWeapons.GetRandomElement().CreateInInventory(inventory);
        }
    }

    private EntityAI EquipSecondaryWeapon(HumanInventory inventory, bool cowboy)
    {
        if (cowboy)
        {
            EntityAI secondary = inventory.CreateInInventory("Repeater");
            inventory.CreateInInventory("Ammo_357");
            inventory.CreateInInventory("Ammo_357");
            inventory.CreateInInventory("Ammo_357");
            return secondary;
        }
        else
        {
            return SecondaryWeapons.GetRandomElement().CreateInInventory(inventory);
        }
    }

    private EntityAI EquipKnifeInSheath(EntityAI sheath, bool cowboy)
    {
        if (cowboy)
        {
            return sheath.GetInventory().CreateAttachment("HuntingKnife");
        }
        else
        {
            return sheath.GetInventory().CreateAttachment(Knives.GetRandomElement());
        }
    }
}

// vim:ft=cs
