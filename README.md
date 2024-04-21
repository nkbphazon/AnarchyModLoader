# Anarchy Mod Loader
A mod loader for Anarchy Online which simply loads all DLLs found in the "mods" folder when the game starts.

You can find the mods I've made for the mod loader in this repo: https://github.com/nkbphazon/AnarchyMods

## Mod framework
If you want to develop a DLL mod, I recommend checking out [ModUtils.h](https://github.com/nkbphazon/AnarchyMods/blob/main/ModUtils.h) in the mods repo. This header-only library contains various helpful tools such as a signature scanner, safe memory manipulation functions and a logger for troubleshooting.

## Load ordering
To specify a load order for a mod, create a folder with the same name as your DLL inside the "mods" folder. Inside the folder create "load.txt" and enter the load order number, which must go from 0 and up. Mods will load in order from lowest to highest number with an interval of 1 second. 

Alternatively, you can specify the load order in "mod_loader_config.ini" like so:
```
[loadorder]
MyDllMod.dll = 1
```
(This overrides the load order specified in the "mods" folder).

Mods with a load order of 0 will be loaded instantly, even ignoring the load delay set inside "mod_loader_config.ini". I recommend not using 0 unless the mod is absolutely required to have an immediate effect, as race conditions may occur for some types of mods if they load too quickly.

If a load order is not specified for a mod, it will automatically receive a load order after the highest specified load order. Mods can have the same load order number, in which case they will load at the same time.

# Credit
This project is based on [Elden Ring Mod Loader](https://github.com/techiew/EldenRingModLoader) which I modified to work for AO. A huge thank you to the creators of the original project!
