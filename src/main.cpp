#include <iostream>

extern "C" {
#include <SDL2/SDL.h>
}

#include "gfx_core.h"
#include "pico_core.h"
#include "pico_data.h"

int main(int, char**) {
	GFX_Init(512, 512);
	GFX_CreateBackBuffer(128, 128);
	pico_control::init(128, 128);
	pico_data::load_test_data();

	int n = 0;

	while (true) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		} else {
			pixel_t* pixels;
			int pitch;
			GFX_LockBackBuffer(&pixels, &pitch);
			pico_control::set_buffer(pixels, pitch);
			pico_api::cls((n >> 8) & 0xf);
			n++;
			GFX_UnlockBackBuffer();
			GFX_Flip();
		}
	}
	GFX_End();
}