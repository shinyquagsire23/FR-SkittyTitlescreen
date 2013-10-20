FR-IntroTemplate
================
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps53387555.png)


This is a custom title screen for use as an example and template for future custom title screens for the FireRed engine. This code is released under GPLv3. Basically that means that if you modify this code and release it as part of a product you are required to open source it. Don't worry though, it's fun!


To compile, first adjust the compile.sh (or .bat) to your appropriate paths and OS.

Next find appropriate freespace in the ROM (about 0x10000 bytes to be confortable, more if needed). Modify linker.lsc and compile.sh (if using auto-insert JAR) appropriately. Insert the bootloader first and then the compiled C binary directly after it.

Finally, place the pointer to the compiled binary (+1) at 0x0800CC90, and viola! Custom title screen.
