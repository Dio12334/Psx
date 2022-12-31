#include "img.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_stdinc.h>


namespace psx::img {

	Color::Color(float t_r, float t_g, float t_b, float t_a): r(t_r), g(t_g), b(t_b), a(t_a){

	}

	Uint32 Color::ToUint32(){
		Uint32 rgba;
		Uint8 R = static_cast<Uint8>(r*255);
		Uint8 G = static_cast<Uint8>(g*255);
		Uint8 B = static_cast<Uint8>(b*255);
		Uint8 A = static_cast<Uint8>(a*255);
		
		#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rgba = R;
		rgba = (rgba << 8) + G;
		rgba = (rgba << 8) + B;
		rgba = (rgba << 8) + A;
		#else
		rgba = A;
		rgba = (rgba << 8) + B;
		rgba = (rgba << 8) + G;
		rgba = (rgba << 8) + R;
		#endif

		return rgba; 

	}
	SDL_Surface* CreateBlankSurface(unsigned w, unsigned h){
		
		Uint32 rmask, gmask, bmask, amask;
		#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
		#else
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
		#endif
		return SDL_CreateRGBSurface(0, w, h, 32, rmask, gmask, bmask, amask);
	}

	void SetPixelOnSurface(SDL_Surface *surface, unsigned int x, unsigned int y, std::uint32_t color){
		Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels 
														+ y * surface->pitch
														+ x * surface->format->BytesPerPixel);
		*target_pixel = color;
	}

	void SaveSurfaceAsPNG(SDL_Surface *surface, std::string title){
		title += ".png";
		IMG_SavePNG(surface, title.c_str());	
	}
}
