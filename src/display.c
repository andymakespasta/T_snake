#include "display.h"
#include "gamestate.h"

#include "snake_obj.h"
#include "pellet_obj.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_MARGIN 8
#define BLOCK_SIZE 16
#define SCREEN_WIDTH (MAX_HOR_BLOCKS * BLOCK_SIZE) + (SCREEN_MARGIN * 2)
#define SCREEN_HEIGHT (MAX_VER_BLOCKS * BLOCK_SIZE) + (SCREEN_MARGIN * 2)

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void display_init(){
	SDL_InitSubSystem(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "WEBASM",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
}

void display_close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}




SDL_Rect point_to_rect(const struct Point * point){
	SDL_Rect block = {.x = SCREEN_MARGIN + (point->x)*BLOCK_SIZE,
					  .y = SCREEN_MARGIN + (point->y)*BLOCK_SIZE,
					  .w = BLOCK_SIZE,
					  .h = BLOCK_SIZE};
	return block;
}

void render_draw_snake(const struct Snake * snake, const SDL_Color color){
	SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0x00, 0x00 );
	SDL_Rect rect;
	for (int i=0; i<(snake->length); i++){
		rect = point_to_rect(&snake->body[i]);
		// SDL_RenderDrawRect(renderer, &rect); 
		SDL_RenderFillRect(renderer, &rect);//TODO: possible optimization using SDL_RenderFillRects	
	}
}


//temp testing
int t_posx = 0;
int t_posy = 0;
int t_vx = 2;
int t_vy = 3;
SDL_Rect r_scr;

const SDL_Color t_white_c = {255,255,255};

void display_draw_gamestate(){
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear(renderer);


// //testing block
// t_posx += t_vx;
// t_posy += t_vy;
// if (t_posx >= SCREEN_WIDTH - BLOCK_SIZE) t_vx = -2;
// if (t_posx <= 0) t_vx = 2;
// if (t_posy >= SCREEN_HEIGHT - BLOCK_SIZE) t_vy = -3;
// if (t_posy <= 0) t_vy = 3;



//     SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0x00, 0x00 );
//     r_scr.x = t_posx;
//     r_scr.y = t_posy;
//     r_scr.w = BLOCK_SIZE;
//     r_scr.h = BLOCK_SIZE;
//     // SDL_RenderDrawRect(renderer, &r_scr);
//     SDL_RenderFillRect(renderer, &r_scr);

//testing block end

    // engine_gamestate 
    render_drawobj_snake(engine_gamestate.snake, t_white_c);
    render_drawobj_pellet(engine_gamestate.pellet);

    SDL_RenderPresent(renderer);

    SDL_UpdateWindowSurface(window);
}








// void render()
// {
//     SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
//     SDL_RenderClear(renderer);

//     SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0x00, 0x00 );
//     SDL_RenderDrawRect(renderer, &r_scr);

//  //    SDL_Rect text_dest = {.x = posX, .y = posY, .w = 20, .h = 20};
	
// 	// text_message_texture[0] = SDL_CreateTextureFromSurface(renderer, surface_text);
// 	// SDL_QueryTexture(text_message_texture[0], NULL, NULL, &text_dest.w, &text_dest.h);
//  //    // SDL_QueryTexture(text_message_texture[0], NULL, NULL, &text_dest.w, &text_dest.h);
//  //    // SDL_RenderDrawRect(renderer, &text_dest);
//  //    SDL_RenderCopy(renderer, text_message_texture[0], NULL, &text_dest);
//  //    // SDL_FreeSurface(surface);

//     SDL_RenderPresent(renderer);
//     TTF_Font *font;

// }







// const SDL_Color white_c = {255,255,255};

// void render_text_surface(SDL_Surface * surface, const char *text) {
// 	surface = TTF_RenderText_Solid(font, text, white_c); // TODO: SDL_Color make parameter/
// 	if (surface ==NULL) {
// 		printf("render surface error : %s\n", TTF_GetError());
// 	}
// }



// // void render_texture(SDL_Texture * target_texture, const char *text){
// // 	// SDL_Surface *surface = TTF_RenderText_Blended(font, text, color_white);
// // 	SDL_Surface *surface = TTF_RenderText_Solid(font, "hello there", color_white);
// // 	if (surface ==NULL) {
// // 		printf("surface null\n");
// // 	}
// // 	target_texture = SDL_CreateTextureFromSurface(renderer, surface);
// // 	if (target_texture ==NULL) {
// // 		printf("target_texture null\n");
// // 	}
// // 	SDL_FreeSurface(surface);
// // 	printf("loading text texture %s\n" ,text);
// // }

// void draw_text_message(int message_no, int posX, int posY);
// void draw_text_glyph(int glyph_no, int posX, int posY);


// void prerender_text(){
// 	TTF_Init();
// 	font = TTF_OpenFont("assets/Terminess_Mono.ttf", 30);
// 	if (font ==NULL) {
// 		printf("load font error : %s\n", TTF_GetError());
// 		return;
// 	}


// }

// void unload_prerendered_text(){
// 	int i;
// 	for (i=0; i<PRE_RENDERED_TEXT_GLYPHS; i++){
// 		if(text_glyph_surface[i]){ //TODO: check if this check is needed.
// 			SDL_FreeSurface(text_glyph_surface[i]);	
// 		}
// 	}
// 	for (i=0; i<PRE_RENDERED_TEXT_MESSAGES; i++){
// 		if(text_message_surface[i]){ //TODO: check if this check is needed.
// 			SDL_FreeSurface(text_glyph_surface[i]);	
// 		}
// 	}
// }


// void draw_text_message(int message_no, int posX, int posY);
// void draw_text_glyph(int glyph_no, int posX, int posY);

// void 