#ifndef NESLIB_H_
#define NESLIB_H_

#define PPU_CTRL     *((unsigned char*)0x2000)
#define PPU_MASK     *((unsigned char*)0x2001)
#define PPU_STATUS   *((unsigned char*)0x2002)
#define SCROLL       *((unsigned char*)0x2005)
#define PPU_ADDRESS  *((unsigned char*)0x2006)
#define PPU_DATA     *((unsigned char*)0x2007)

#define SCREEN_OFF() \
	do { \
		PPU_CTRL = 0; \
		PPU_MASK = 0; \
	} while (0)

#define SCREEN_ON() \
	do { \
		PPU_CTRL = 0x90; \
		PPU_MASK = 0x1e; \
	} while (0)

#define WRITE_PALETTE(palette, i, n) \
	do { \
		PPU_ADDRESS = 0x3f; \
		PPU_ADDRESS = 0x00;	\
		for (i=0; i<n; ++i) { \
			PPU_DATA = palette[i]; \
		} \
	} while (0)

#define RESET_SCROLL() \
	do { \
		PPU_ADDRESS = 0; \
		PPU_ADDRESS = 0; \
		SCROLL = 0; \
		SCROLL = 0; \
	} while (0)

#endif
