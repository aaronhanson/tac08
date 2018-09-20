#ifndef PICO_CORE_H
#define PICO_CORE_H

#include "gfx_core.h"

namespace pico_api {
	typedef uint8_t colour;

	void cls(colour c);
	void spr(int n, int x, int y, int w = 1, int h = 1, bool flip_x = false, bool flip_y = false);
	void map(int cell_x, int cell_y, int scr_x, int scr_y, int cell_w, int cell_h, int layer = 0);
	int btn(int n);
	int btnp(int n);

}  // namespace pico_api

namespace pico_control {
	void init(int x, int y);
	void set_buffer(pixel_t* buffer, int pitch);
	void set_sprite_data(std::string data, std::string flags);
	void set_map_data(std::string data);
}  // namespace pico_control

#endif /* PICO_CORE_H */