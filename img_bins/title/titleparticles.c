
//{{BLOCK(titleparticles)

//======================================================================
//
//	titleparticles, 8x32@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles lz77 compressed
//	Total size: 32 + 36 = 68
//
//	Time-stamp: 2013-10-19, 16:53:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short titleparticlesTiles[18] __attribute__((aligned(4)))=
{
	0x8010,0x0000,0x002F,0x8000,0x1001,0x0DA0,0x01F0,0x1FF0,
	0x1E70,0x013D,0x3001,0x101F,0xF007,0x3001,0x113B,0x2340,
	0x8080,0x0001,
};

const unsigned short titleparticlesPal[16] __attribute__((aligned(4)))=
{
	0x1084,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

const Oam particleOam = {50,0x0,50,0x20,0x1,0};
unsigned char particleAnimation[12] = {  64+1, 0, 0xA, 0,
					0xFE, 0xFF, 0, 0 };
const unsigned int particleAnimTable = &particleAnimation;
const ObjTemplate particleTemplate = {2,1,&particleOam,&particleAnimTable,0,0x08231CFC,0x080EE4DD,0xFF};

const Oam particle2Oam = {50,0x0,50,0x20,0x1,0};
unsigned char particle2Animation[12] = {  66+1, 0, 0x1, 0,
					67+1, 0, 0x1, 0,
					0xFE, 0xFF, 0, 0 };
const unsigned int particle2AnimTable = &particle2Animation;
const ObjTemplate particle2Template = {2,1,&particle2Oam,&particle2AnimTable,0,0x08231CFC,0x080EE4DD,0xFF};

//}}BLOCK(titleparticles)
