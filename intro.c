//Place pointer to bootloader at 0800CC90

#define TITLE     ((u8*)0x020370B7)
#define VAR     ((u16*)0x020370B8)
#define TIMER   ((long*)0x020370BC)
#define init     ((u8*)0x020370B8)
#define hblankIrq *(u32*)0x3003100

#define Tiles     ((u16*)0x6000000)
#define OBJData		((u16*)0x6010000)
#define MapData     ((u16*)0x6003800)
#define MoarColor     ((u16*)0x6008000)
#define BG1Data     ((u16*)0x6008000)
#define BG2Data     ((u16*)0x600C000)
#define OAMBuffer ((OamThingy*)0x0202063C)
#define FADE	*(u8*)0x02037AB8
#define isFading() FADE > 0
#define second 60;
#define numFramestoRun 2699

#include "include/gba_keys.h"

void notMain()
{
	TIMER[0] = TIMER[0] + 1;
	TIMER[10] = TIMER[10] + 1;
	if(init[27] == 0)
	{
		initTitle();
		killSong();
		playSong(278);
		unfadeScreenWhite();
	}	
	else if(init[27] == 1)
	{
		if(TIMER[0] >= 20)
		{
			init[27] = 2;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 2)
	{
		moveSkitty();
		if(VAR[4] == 1)
		{
			VAR[5] = VAR[5] + 3;
			VAR[4] = 0;
		}
		else
		{
			VAR[5] = VAR[5] + 2;
			VAR[4] = 1;
		}
		
		if(VAR[5] == 0 || VAR[5] > 0x1FF)
		{
			VAR[5] = 0;
			moveSkitty();
			init[27] = 3;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 3)
	{
		moveLogo();
		VAR[6] = VAR[6] - 0x0250;
		
		if(VAR[6] == 0 || VAR[6] > 0x3C00)
		{
			VAR[6] = 0;
			moveLogo();
			init[27] = 4;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 4)
	{
		if(TIMER[0] == 1)
		{
			init[27] = 5;
		}
	}
	else if(init[27] == 5)
	{
		spawnText();
		spawnFlavor();
		init[27] = 6;
	}
	else if(init[27] >= 6)
	{
		if(random(3) == 2)
			spawnParticle();
		moveUp();
		if(!isFading() && VAR[0] < 0x20)
			pulseEyes();
	}
	if((keyDown(KEY_A) || keyDown(KEY_START)) && init[27] == 6)
   	{
		TIMER[0] = 0;
		VAR[0] = 0x10;
		init[27] = 12;
		playCry(0x13B,0);
		playCry(0x13A,0);	
	}
	else if(keyDown(KEY_SELECT) && keyDown(KEY_B))
	{
		if(keyDown(KEY_UP))
		{
			int (*func)(void) = (int (*)(void))0x080796CD; //Save Delete
			func();
		}
		else
		{
			int (*func)(void) = (int (*)(void))0x080796E9; //Berry Update
			func();
		}
		return;
	}

	if(TIMER[0] == 60 && VAR[0] == 0x10)
	{
		fadeScreenWhite();
		TIMER[0] = 0;
		VAR[0] = 0x20;
	}
	else if(TIMER[0] == 40 && VAR[0] == 0x10)
		fadeSong();
	if(TIMER[0] == 30 && VAR[0] == 0x20)
	{
		int (*func)(void) = (int (*)(void))0x0800C301;
     		resetVars();
		int x = func();
	}

	if(TIMER[10] > numFramestoRun - 80)
	{
		fadeScreen();
		fadeSong();
		VAR[20] = 0x10;
		VAR[0] = 0x40;
		TIMER[10] = 0;
	}
	if(VAR[20] == 0x10 && TIMER[10] >= 120)
	{
		int (*func)(void) = (int (*)(void))0x080004C5;
		resetVars();
		func();
	}
	return;
}

#include <string.h>
#include "include/gba.h"
#include "useful.h"
#include "titlescreen.c"

