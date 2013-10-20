

void unfadeScreen()
{
	//__asm("mov r0, #0x0");
	//__asm("mov r1, #0x0");
	//int (*func)(void) = (int (*)(void))0x0807A819;
	//int x = func();
	fadeScreen2(0,0x10,0);
}

void fadeScreen()
{
	__asm("mov r0, #0x1");
	__asm("mov r1, #0x4");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void fadeScreen2(int nub, int r2, int r3)
{
	int (*func)(void) = (int (*)(void))0x08790025;
	func();
}

void fadeScreenFast()
{
	__asm("mov r0, #0x1");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void unfadeScreenWhite()
{
	__asm("mov r0, #0x2");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void fadeScreenWhite()
{
	__asm("mov r0, #0x3");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void fadePal(int *something1, int *something2)
{
	int (*func)(void) = (int (*)(void))0x08045275;
	func();
}

void fadeSong()
{
	__asm("mov r0, #0x4");
	int (*func)(void) = (int (*)(void))0x0806b155;
	int x = func();
}

void copyPal(void *source, void *dest)
{
	copyPalFull(source,dest,8);
}

void copyPalFull(void *source, void *dest, void *size)
{
	SystemCall(0xC);
}

void copyMem(void *source, void *dest, void *size)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void playSong(int *songNum)
{
	int (*func)(void) = (int (*)(void))0x081DD0F5;
	int x = func();
}

void playCry(int *pkmnNum, int *fx)
{
	int (*func)(void) = (int (*)(void))0x08071dF1;
	int x = func();
}

void playSound(int *fxNum)
{
	int (*func)(void) = (int (*)(void))0x080722CD;
	int x = func();
}

void killSong()
{
	playSong(0);
}

void soundSomething(int *something)
{
	int (*func)(void) = (int (*)(void))0x08071BC5;
	func();
}

int random(int max)
{
	int i = rando();
	i = modulo(i, max);
	return i;
}

int rando()
{
	int (*func)(void) = (int (*)(void))0x08044EC9;
	return func();
}

int modulo(int *input, int *dividend)
{
	int (*func)(void) = (int (*)(void))0x081E4685;
	return func();
}

void drawText(int *foo, int *font, int *x, int *y, int *bar, int *baz, long *str)
{
	//__asm("str r4, [SP,#0xBC]");
	//__asm("str r5, [SP,#0xBC+4]");
	//__asm("str r6, [SP,#0xBC+8]");
	int (*func)(void) = (int (*)(void))0x0812E51D;
	int i = func();
}

void changeIO(int *a, int *b)
{
	int (*func)(void) = (int (*)(void))0x08000A39;
	int i = func();
}

void something2(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x08001B91;
	int i = func();
}

void something(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x080F6F1D;
	int i = func();
}

void clearOAM()
{
	int (*func)(void) = (int (*)(void))0x08006B11;
	int i = func();
}

void callOAM()
{
	int (*func)(void) = (int (*)(void))0x08006B5D;
	int i = func();
}

void copyOAM()
{
	int (*func)(void) = (int (*)(void))0x08006BA9;
	int i = func();
}

void deleteOAM(int oamNum)
{
	int j = 0x0202063C;
	oamNum = oamNum * 0x44;
	oamNum = oamNum + j;
	deleteOAM_sys(oamNum);
}

void deleteOAM_sys(int *oamNum)
{
	int (*func)(void) = (int (*)(void))0x08007281;
	int i = func();
}

void copyUnkToPre(int unknown, u8 x, u8 y, u8 s3)
{
	int (*func)(void) = (int (*)(void))0x08006F8D;
	int i = func();
}

int spawnOamFromUnk(int *unknown, u8 *x, u8 *y, u8 *derp) 
{
	int (*func)(void) = (int (*)(void))0x08006F8D;
	return func();
} __attribute__((__call_from_r4))

void resetVars()
{
	TIMER[0] = 0;
	TIMER[1] = 0;
	for(int i = 0; i < 90; i++)
	{
		VAR[i] = 0;
	}
} 

int isin(int x) 
{       
	int qN = 13, qA= 12, qP= 15, qR= 2*qN-qP, qS= qN+qP+1-qA; 
	x= x<<(30-qN);          
     	if( (x^(x<<1)) < 0)             
		x= (1<<31) - x;     
	x= x>>(30-qN);     
	return x * ( (3>>qR) ) >> qS; 
}

u16 oscillateVar(int var, int max)
{
	if(VAR[var] >> 15 == 0)
	{
		VAR[var] = VAR[var] + 1;
	}
	else if(VAR[var] >> 15 == 1)
	{
		VAR[var] = VAR[var] - 1;
	}

	if(VAR[var] > max && VAR[var] < 1 << 15)
	{
		VAR[var] = max + (1 << 15);
	}
	if(VAR[var] == (1 << 15))
	{
		VAR[var] = 0;
	}

	return VAR[var] & 0xFF;
}

void *memcpy(void* dst, const void* src, size_t size)
{
     if(size==0 || dst==NULL || src==NULL)
         return;
     u32 count;
     u16 *dst16;
     // hword destination
     u8  *src8;
      // byte source
     // Ideal case: copy by 4x words. Leaves tail for later.
     if( ((u32)src|(u32)dst)%4==0 && size>=4)
     {
         u32 *src32= (u32*)src, *dst32= (u32*)dst;
         count= size/4;
         u32 tmp= count&3;
         count /= 4;
         // Duff, bitch!
         switch(tmp) {
             do {
    *dst32++ = *src32++;
         case 3:
     *dst32++ = *src32++;
         case 2:
     *dst32++ = *src32++;
         case 1:
     *dst32++ = *src32++;
         case 0:
     ; } while(count--);
         }         // Check for tail
         size &= 3;
         if(size == 0)
             return;
         src8= (u8*)src32;
         dst16= (u16*)dst32;
     }
     else
        // Unaligned.
     {
         u32 dstOfs= (u32)dst&1;
         src8= (u8*)src;
         dst16= (u16*)(dst-dstOfs);
         // Head: 1 byte.
         if(dstOfs != 0)
         {
             *dst16= (*dst16 & 0xFF) | *src8++<<8;
             dst16++;
             if(--size==0)
                 return;
         }
     }
     // Unaligned main: copy by 2x byte.
     count= size/2;
     while(count--)
     {
         *dst16++ = src8[0] | src8[1]<<8;
         src8 += 2;
     }
     // Tail: 1 byte.
     if(size&1)
         *dst16= (*dst16 &~ 0xFF) | *src8;
 }

const unsigned int sineTable[1280] __attribute__((aligned(4)))=
{
	
0,3,7,11,15,19,22,25,28,31,33,35,37,38,39,39,39,39,38,37,36,34,32,29,27,23,20,17,13,9,5,1,-2,-6,-10,-14,-17,-21,-24,-27,-30,-32,-34,-36,-38,-39,-39,-39,-39,-39,-38,-37,-35,-33,-30,-28,-25,-22,-18,-14,-11,-7,-3,0,4,8,12,16,19,23,26,29,31,34,35,37,38,39,39,39,39,38,37,36,34,31,29,26,23,20,16,12,8,4,0,-3,-6,-10,-14,-18,-21,-25,-27,-30,-33,-35,-36,-38,-39,-39,-39,-39,-39,-38,-36,-35,-32,-30,-27,-24,-21,-17,-14,-10,-6,-2,1,5,9,13,16,20,23,26,29,32,34,36,37,38,39,39,39,39,38,37,35,33,31,28,26,22,19,15,12,8,4,0,-3,-7,-11,-15,-18,-22,-25,-28,-31,-33,-35,-37,-38,-39,-39,-39,-39,-39,-37,-36,-34,-32,-30,-27,-24,-20,-17,-13,-9,-5,-1,2,5,9,13,17,20,24,27,30,32,34,36,37,39,39,39,39,39,38,37,35,33,31,28,25,22,18,15,11,7,3,0,-4,-8,-12,-15,-19,-22,-26,-28,-31,-33,-35,-37,-38,-39,-39,-39,-39,-38,-37,-36,-34,-32,-29,-26,-23,-20,-16,-13,-9,-5,-1,2,6,10,14,18,21,24,27,30,32,35,36,38,39,39,39,39,39,38,36,35,33,30,27,24,21,18,14,10,6,2,-1,-5,-8,-12,-16,-20,-23,-26,-29,-31,-34,-36,-37,-38,-39,-39,-39,-39,-38,-37,-35,-33,-31,-29,-26,-23,-19,-16,-12,-8,-4,0,3,7,11,14,18,22,25,28,30,33,35,37,38,39,39,39,39,39,38,36,34,32,30,27,24,21,17,13,10,6,2,-1,-5,-9,-13,-17,-20,-23,-27,-29,-32,-34,-36,-37,-38,-39,-39,-39,-39,-38,-37,-35,-33,-31,-28,-25,-22,-19,-15,-11,-7,-3,0,4,7,11,15,19,22,25,28,31,33,35,37,38,39,39,39,39,38,37,36,34,32,29,26,23,20,17,13,9,5,1,-2,-6,-10,-14,-17,-21,-24,-27,-30,-32,-34,-36,-38,-39,-39,-39,-39,-39,-38,-37,-35,-33,-30,-28,-25,-21,-18,-14,-11,-7,-3,0,4,8,12,16,19,23,26,29,31,34,35,37,38,39,39,39,39,38,37,36,34,31,29,26,23,20,16,12,8,4,0,-3,-7,-10,-14,-18,-21,-25,-28,-30,-33,-35,-36,-38,-39,-39,-39,-39,-39,-38,-36,-35,-32,-30,-27,-24,-21,-17,-14,-10,-6,-2,1,5,9,13,16,20,23,26,29,32,34,36,37,38,39,39,39,39,38,37,35,33,31,28,25,22,19,15,12,8,4,0,-3,-7,-11,-15,-18,-22,-25,-28,-31,-33,-35,-37,-38,-39,-39,-39,-39,-39,-37,-36,-34,-32,-30,-27,-24,-20,-17,-13,-9,-5,-1,2,6,9,13,17,20,24,27,30,32,34,36,37,39,39,39,39,39,38,37,35,33,31,28,25,22,18,15,11,7,3,0,-4,-8,-12,-15,-19,-22,-26,-28,-31,-33,-35,-37,-38,-39,-39,-39,-39,-38,-37,-36,-34,-32,-29,-26,-23,-20,-16,-13,-9,-5,-1,2,6,10,14,18,21,24,27,30,32,35,36,38,39,39,39,39,39,38,36,35,33,30,27,24,21,18,14,10,6,2,-1,-5,-8,-12,-16,-20,-23,-26,-29,-31,-34,-36,-37,-38,-39,-39,-39,-39,-38,-37,-35,-33,-31,-29,-26,-23,-19,-16,-12,-8,-4,0,3,7,11,15,18,22,25,28,30,33,35,37,38,39,39,39,39,39,38,36,34,32,30,27,24,21,17,13,10,6,2,-1,-5,-9,-13,-17,-20,-23,-27,-29,-32,-34,-36,-37,-38,-39,-39,-39,-39,-38,-37,-35,-33,-31,-28,-25,-22,-19,-15,-11,-7,-3,0,4,8,11,15,19,22,25,28,31,33,35,37,38,39,39,39,39,38,37,36,34,32,29,26,23,20,17,13,9,5,1,-2,-6,-10,-14,-17,-21,-24,-27,-30,-32,-34,-36,-38,-39,-39,-39,-39,-39,-38,-37,-35,-33,-30,-28,-25,-21,-18,-14,-11,-7,-3,0,4,8,12,16,19,23,26,29,31,34,35,37,38,39,39,39,39,38,37,36,34,31,29,26,23,19,16,12,8,4,0,-3,-7,-10,-14,-18,-21,-25,-28,-30,-33,-35,-36,-38,-39,-39,-39,-39,-39,-38,-36,-34,-32,-30,-27,-24,-21,-17,-14,-10,-6,-2,1,5,9,13,16,20,23,26,29,32,34,36,37,38,39,39,39,39,38,37,35,33,31,28,25,22,19,15,12,8,4,0,-3,-7,-11,-15,-18,-22,-25,-28,-31,-33,-35,-37,-38,-39,-39,-39,-39,-39,-37,-36,-34,-32,-29,-27,-24,-20,-17,-13,-9,-5,-1,2,6,9,13,17,20,24,27,30,32,34,36,37,39,39,39,39,39,38,37,35,33,31,28,25,22,18,15,11,7,3,0,-4,-8,-12,-15,-19,-22,-26,-28,-31,-33,-35,-37,-38,-39,-39,-39,-39,-38,-37,-36,-34,-32,-29,-26,-23,-20,-16,-12,-9,-5,-1,2,6,10,14,18,21,24,27,30,32,35,36,38,39,39,39,39,39,38,36,35,33,30,27,24,21,18,14,10,6,2,-1,-5,-9,-12,-16,-20,-23,-26,-29,-32,-34,-36,-37,-38,-39,-39,-39,-39,-38,-37,-35,-33,-31,-29,-26,-23,-19,-16,-12,-8,-4,0,3,7,11,15,18,22,25,28,30,33,35,37,38,39,39,39,39,39,38,36,34,32,30,27,24,21,17,13,10,6,2,-1,-5,-9,-13,-17,-20,-24,-27,-29,-32,-34,-36,-37,-38,-39,-39,-39,-39,-38,-37,-35,-33,-31,-28,-25,-22,-19,-15,-11,-7,-3,0,4,8,11,15,19,22,25,28,31,33,35,37,38,39,39,39,39,38,37,36,34,32,29,26,23,20,16,13,9,5,1,-2,-6,-10,-14,-17,-21,-24,-27,-30,-32,-34,-36,-38,-39,-39,-39,-39,-39,-38,-36,-35,-33,-30,-28,-25,-21,-18,-14,-11,-7,-3,0,4,8,12,16,19,23,26,29,31,34,35,37,38,39,39,39,39,38,37,36,34,31,29,26,23,19,16,12,8,4,0,-3,-7,-10,-14,-18,-21,-25,-28,-30,-33,-35,-36,-38,-39,-39,-39,-39,-39,-38,-36,-34,-32,-30,-27,-24,-21,-17,-14,-10,-6,-2,1,5,9,13,16,20,23,26,29,32,34,36,37,38,39,39,39,39,38,37,35,33,31,28,
};

typedef struct
{
	u16 x, y;
} Position;

typedef struct
{
	u8 y, flags, x, msbXFlags;
	u16 tileProPal, irrelivant;
} Oam;

typedef struct
{
	Oam oam;
	u32 animation;
	u8 fC, fD, fE, fF;
	u32 f10, objectTemplate, f18, callback;
	Position pos1, pos2;
	u8 pos3x, pos3y, animNr, animFrame, time, f2D;
	Position iPos, iVel;
	u32 derp1, derp2;
	u8 f42, f43, end;
} OamThingy;

typedef struct
{
	u16 f0, f1;
	u32 oam, animation, gfx, animation2, callback;
	u8 end;
} ObjTemplate;

