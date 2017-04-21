#include "neslib.h"

//	Globals
unsigned char index;
unsigned char text_position;
unsigned char frame_count;
const unsigned char text[] = { "Hello World!" };
const unsigned char palette[] = { 0x0f, 0x1b, 0x20, 0x0f };

void write_text(void) {
	if (text_position < sizeof(text)) {
		PPU_ADDRESS = 0x21;
		PPU_ADDRESS = 0xca + text_position;
		PPU_DATA = text[text_position];
		++text_position;
	} else {
		text_position = 0;
		PPU_ADDRESS = 0x21;
		PPU_ADDRESS = 0xca;
		for (index = 0; index<sizeof(text); ++index) {
			PPU_DATA = 0;
		}
	}
}

void frame(void) {
	++frame_count;

	if (frame_count == 30 || frame_count == 60) {
		write_text();
		RESET_SCROLL();
	}

	if (frame_count == 60) {
		frame_count = 0;
	}
}

void main(void) {
	index = 0;
	text_position = 0;

	SCREEN_OFF();
	WRITE_PALETTE(palette, index, 4);
	RESET_SCROLL();
	SCREEN_ON();

	while (1)
		;
}
