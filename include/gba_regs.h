//
// Registers
//
 
#ifndef GBA_REGS_H
#define GBA_REGS_H
 
#include "gba_types.h"
 
#define OAM_Mem                ((u16*)0x03003128) // Sprites(128), coordinates, size..(total 1Kb) (adjusted for FR callback)
#define OBJ_PaletteMem        ((u16*)0x020373F8) // Sprite Palette(256/16 colors) (adjusted for FR callback)
#define OAM_Data                 ((u16*)0x6010000) // Sprite data (bitmapped)
 
#define FrontBuffer     ((u16*)0x6000000) // Front Display Memory (the screen in mode 3-5)
#define BG_PaletteMem          ((u16*)0x020371F8) // Background Palette(256/16 colors) (adjusted for FR callback)
#define BG_PaletteMem_Faded          ((u16*)0x020375F8) // Background Palette(256/16 colors) (adjusted for FR callback)
#define PaletteMem          ((u16*)0x04000000) // Background Palette(256/16 colors) (adjusted for FR callback)
#define DISPSTAT		*(u16*)0x4000004
#define BG0CNT			*(u16*)0x4000008
#define BG1CNT			*(u16*)0x400000A
#define BG2CNT			*(u16*)0x400000C
#define BG3CNT			*(u16*)0x400000E

#define BG0HOFF			*(u16*)0x4000010
#define BG0VOFF			*(u16*)0x4000012

#define BG1HOFF			*(u16*)0x4000014
#define BG1VOFF			*(u16*)0x4000016

#define BG2HOFF			*(u16*)0x4000018
#define BG2VOFF			*(u16*)0x400001A

#define BG3HOFF			*(u16*)0x400001C
#define BG3VOFF			*(u16*)0x400001E

#define WIN0H			*(u16*)0x4000040
#define WIN1H			*(u16*)0x4000042

#define WIN0V			*(u16*)0x4000044
#define WIN1V			*(u16*)0x4000046

#define WININ			*(u16*)0x4000048
#define WINOUT			*(u16*)0x400004A

#define MOSIAC			*(u16*)0x400001C
#define BLDMOD			*(u16*)0x400001E

#define BG2PD			*(u16*)0x4000026

#define BG2X			*(u32*)0x4000028
#define BG2Y			*(u32*)0x400002C
#define IE			*(u16*)0x4000200

#define REG_DISPCNT         *(u16*)0x4000000 // Display control mode
#define VCOUNT         *(volatile u16*)0x4000006  // Vertical control sync
#define vsync() while(VCOUNT != 160);
 
#endif
