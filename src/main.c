#include "neslib.h"

//	Globals
unsigned char index;
const unsigned char text[] = { "Hello World!" };
const unsigned char palette[] = { 0x0f, 0x1b, 0x20, 0x0f };

void main(void) {


	SCREEN_OFF();
	WRITE_PALETTE(palette, index, 4);

	//load the text
	PPU_ADDRESS = 0x21;  	//	set an address in the PPU of 0x21ca
	PPU_ADDRESS = 0xca;  	//	about the middle of the screen
	for (index = 0; index < sizeof(text); ++index) {
		PPU_DATA = text[index];
	}

	RESET_SCROLL();
	SCREEN_ON();

	//	infinite loop
	while (1)
		;
}
