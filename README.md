# DayZ Namalsk Deathmatch

This is a DayZ mission for running a deathmatch server on the Namalsk Island
mod map.

* [Installation Instructions](#installation-instructions)
* [Recommended Server Settings](#recommended-server-settings)
* [Optional Server Settings](#optional-server-settings)

## Installation Instructions

Install the `deathmatch.namalsk` folder (the contents of this Git repository)
in your `DayZServer\mpmissions` folder. If DayZ server was installed using the
Steam Windows application, the `mpmissions` folder is typically located at:

```
C:\Program Files (x86)\Steam\steamapps\common\DayZServer\mpmissions
```

Edit the DayZ server configuration file (typically `serverDZ.cfg`) to load the
`deathmatch.namalsk` mission:

```
class Missions
{
    class DayZ
    {
        template="deathmatch.namalsk";
    };
};
```

## Recommended Server Settings

TBD

## Optional Server Settings

TBD
