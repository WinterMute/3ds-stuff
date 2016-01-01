#include <string.h>

#include <3ds.h>

#include "keyboard.h"

int main() {

	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL);


	while (aptMainLoop()) {

		hidScanInput();

		// Your code goes here

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		int key = updateKeyboard();

		(void)key;

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
