#ifndef IMG_H
#define IMG_H

#include <SDL2/SDL_surface.h>
#include <cstdint>
#include <SDL2/SDL.h>
#include <string>

namespace psx::img {
	
	struct Color{
		float r, g ,b, a;
		Color(float t_r, float t_g, float t_b, float t_a = 1.f);
		Uint32 ToUint32();

	};

	SDL_Surface* CreateBlankSurface(unsigned w, unsigned h);
	void SetPixelOnSurface(SDL_Surface* surface, unsigned x, unsigned y, std::uint32_t color);	
	void SaveSurfaceAsPNG(SDL_Surface* surface, std::string title);
}

#endif

