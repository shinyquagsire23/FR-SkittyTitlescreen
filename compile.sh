#!/bin/bash
arm-none-eabi-gcc -mthumb -mthumb-interwork -g -c -w -std=c99 -ffast-math -mlong-calls -o intro.out intro.c
arm-none-eabi-ld -o intro.o -T linker.lsc intro.out
#arm-none-eabi-gcc -mthumb -mthumb-interwork -g -c -w -std=c99 -T linker.lsc -c intro.c -o intro.o
arm-none-eabi-objcopy -O binary intro.o toASM.bin
rm intro.o
rm intro.out
java -jar AddASM.jar /home/maxamillion/ROMHacking/ASM/CustomTitle/GS.gba /home/maxamillion/ROMHacking/ASM/CustomTitle/toASM.bin 0x7C0058
#thumb toASM.asm
