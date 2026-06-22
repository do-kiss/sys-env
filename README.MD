## Overview

Sys-env can be used to prevent mods or similar from being loaded in sys/emu (which is configureable) <br> <br>

## Usecases:
The most noteable example are themes: <br>
 - Patches for themes need to match the firmware update, so you will get a crash if you use sys and emunand on different firmware
 - If you only need themes on one of the two, you can block one from being loaded. <br> <br>

The blocking is done by appending ``.bak`` to the end of the file during boot. <br>

## Thanks to:
 - Arcdelta for motivating me to actually finish this lmao.
