#include "display.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const SDL_Color white_c = {255,255,255};

void render_text_surface(SDL_Surface * surface, const char *text) {
	surface = TTF_RenderText_Solid(font, text, white_c); // TODO: SDL_Color make parameter/
	if (surface ==NULL) {
		printf("render surface error : %s\n", TTF_GetError());
	}
}



// void render_texture(SDL_Texture * target_texture, const char *text){
// 	// SDL_Surface *surface = TTF_RenderText_Blended(font, text, color_white);
// 	SDL_Surface *surface = TTF_RenderText_Solid(font, "hello there", color_white);
// 	if (surface ==NULL) {
// 		printf("surface null\n");
// 	}
// 	target_texture = SDL_CreateTextureFromSurface(renderer, surface);
// 	if (target_texture ==NULL) {
// 		printf("target_texture null\n");
// 	}
// 	SDL_FreeSurface(surface);
// 	printf("loading text texture %s\n" ,text);
// }


void prerender_text(){
	TTF_Init();
	font = TTF_OpenFont("assets/Terminess_Mono.ttf", 30);
	if (font ==NULL) {
		printf("load font error : %s\n", TTF_GetError());
		return;
	}


}

void unload_prerendered_text(){
	int i;
	for (i=0; i<PRE_RENDERED_TEXT_GLYPHS; i++){
		if(text_glyph_surface[i]){ //TODO: check if this check is needed.
			SDL_FreeSurface(text_glyph_surface[i]);	
		}
	}
	for (i=0; i<PRE_RENDERED_TEXT_MESSAGES; i++){
		if(text_message_surface[i]){ //TODO: check if this check is needed.
			SDL_FreeSurface(text_glyph_surface[i]);	
		}
	}
}


void draw_text_message(int message_no, int posX, int posY);
void draw_text_glyph(int glyph_no, int posX, int posY);