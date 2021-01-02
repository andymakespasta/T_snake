// handles the rendering and display
#ifndef TSNAKE_DISPLAY_H
#define TSNAKE_DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define BLOCK_SIZE 18
#define MAX_HOR_BLOCKS 30
#define MAX_VER_BLOCKS 15

#define SCREEN_WIDTH (MAX_HOR_BLOCKS * BLOCK_SIZE) + 10
#define SCREEN_HEIGHT (MAX_HOR_BLOCKS * BLOCK_SIZE) + 10

TTF_Font *font;

#define PRE_RENDERED_TEXT_GLYPHS 50
SDL_Surface * text_glyph_surface[PRE_RENDERED_TEXT_GLYPHS];

#define PRE_RENDERED_TEXT_MESSAGES 10
SDL_Surface * text_message_surface[PRE_RENDERED_TEXT_MESSAGES];
SDL_Rect text_message_rect[PRE_RENDERED_TEXT_MESSAGES];

void prerender_text();
void unload_prerendered_text();
void draw_text_message(int message_no, int posX, int posY);
void draw_text_glyph(int glyph_no, int posX, int posY);

#endif