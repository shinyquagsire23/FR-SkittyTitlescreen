#include "img_bins/title/titleback.c"
#include "img_bins/title/titleflavor.c"
#include "img_bins/title/titlemon.c"
#include "img_bins/title/titleparticles.c"
#include "img_bins/title/titletexts.c"
#include "img_bins/title/pokemon.c"

void initTitle()
{
	//Copy our palettes first
	REG_DISPCNT = 0x1F41;
	BG0CNT = 0x0700;
	BG1CNT = 0x1002;
	BG2CNT = 0x7884;
	BG0VOFF = 0x1B8;
	VAR[5] = 0x1B8;
	VAR[6] = 0x3C00;
	BG2X = 0xE000;
	BG2Y = 0x3C00;
	//VAR[17] = 0x160 - 0x4;
	//VAR[15] = 1;
	//VAR[19] = 0x8000;

	DISPSTAT = 0x9639;
	IE = 0x87;
	
	//clearOAM();

	copyPalFull(&pokemonPal, &BG_PaletteMem[0],56);
	LZ77UnCompVram(&titlemonTiles, &Tiles[0]);
	LZ77UnCompVram(&titlemonMap, &MapData[0]);

	LZ77UnCompVram(&titlebackTiles, &Tiles[0x400]);
	LZ77UnCompVram(&titlebackMap, &BG1Data[0]);

	LZ77UnCompVram(&pokemonTiles, &Tiles[0x2000]);
	LZ77UnCompVram(&pokemonMap, &BG2Data[0]);

	copyPal(&titleflavorPal, &BG_PaletteMem[256]);
	copyPal(&titleparticlesPal, &BG_PaletteMem[256+16]);
	LZ77UnCompVram(&titleflavorTiles, &OBJData[0]);
	LZ77UnCompVram(&titletextsTiles, &OBJData[0x440]);
	LZ77UnCompVram(&titleparticlesTiles, &OBJData[0x400]);
	//unfadeScreen();
	init[27] = 1;
}

void moveSkitty()
{
	BG0VOFF = VAR[5];
}

void moveLogo()
{
	BG2Y = VAR[6];
}

void spawnFlavor()
{
	int x = (240 / 2) - (64 / 2);
	int y = 70;
	int i = spawnOamFromUnk(&flavorTemplate,x,y,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
	i = spawnOamFromUnk(&flavor2Template,x+64,y,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
}

void spawnText()
{
	int x = 20;
	//int y = 155;
	int i = spawnOamFromUnk(&textTemplate,x,158,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
	x += 32 + 8;
	i = spawnOamFromUnk(&text2Template,x,158,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
	x += 32;
	i = spawnOamFromUnk(&text3Template,x,158,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
	x += 16+8;
	i = spawnOamFromUnk(&text4Template,x,158,0x0);
	OAMBuffer[i].oam.tileProPal = 0;

	x += 64+10;
	i = spawnOamFromUnk(&text5Template,x,158,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
	x += 32;
	i = spawnOamFromUnk(&text6Template,x,158,0x0);
	OAMBuffer[i].oam.tileProPal = 0;
}

void spawnParticle()
{
	int i = 0;
	if(random(4) == 1)
		i = spawnOamFromUnk(&particleTemplate,0,160,0x0);
	else
	{
		i = spawnOamFromUnk(&particle2Template,0,160,0x0);
		OAMBuffer[i].derp1 = 1;
	}
	if(VAR[14] == 0)
		VAR[14] = i;
	
	OAMBuffer[i].pos1.x = i * (random(32) + 19);
	OAMBuffer[i].oam.tileProPal = (2 << 10) | (1 << 12);
}

void moveUp()
{
	for(int i = VAR[14]; i < 0x3F; i++)
	{
		if(OAMBuffer[i].derp1 == 1)
			OAMBuffer[i].pos1.y -= 2;
		else
			OAMBuffer[i].pos1.y -= 1;
		if((int)OAMBuffer[i].pos1.y > 0x160 || (int)OAMBuffer[i].pos1.y < 0)
		{
			deleteOAM(i);
		}
	}
}

void pulseEyes()
{
	if(VAR[10] < 3)
	{
		VAR[10] = VAR[10] + 1;
		return;
	}
	VAR[10] = 0;
	if(VAR[9] == 0)
	{
		BG_PaletteMem_Faded[14] = BG_PaletteMem_Faded[14] - 1;
		if(BG_PaletteMem_Faded[14] == 0)
		{
			VAR[9] = 1;
			TIMER[0] = 0;
		}
	}
	else if (VAR[9] == 1)
	{
		if(TIMER[0] > 20)
			VAR[9] = 2;
	}
	else if(VAR[9] == 2)
	{
		BG_PaletteMem_Faded[14] = BG_PaletteMem_Faded[14] + 1;
		if(BG_PaletteMem_Faded[14] == 0x1C)
		{
			VAR[9] = 3;
			TIMER[0] = 0;
		}
	}
	else if (VAR[9] == 3)
	{
		if(TIMER[0] > 20)
			VAR[9] = 0;
	}
}
