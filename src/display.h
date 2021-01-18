// handles the rendering and display. Hides everything
// API in header file is really simple: Init -> draw -> repeat -> close
// Implementation is dependent on game.
#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

// TTF_Font *font;

// #define PRE_RENDERED_TEXT_GLYPHS 50
// SDL_Surface * text_glyph_surface[PRE_RENDERED_TEXT_GLYPHS];

// #define PRE_RENDERED_TEXT_MESSAGES 10
// SDL_Surface * text_message_surface[PRE_RENDERED_TEXT_MESSAGES];
// SDL_Rect text_message_rect[PRE_RENDERED_TEXT_MESSAGES];

// void prerender_text();
// void unload_prerendered_text();


void display_init();
void display_close();

// draw will overwrite previous draw in undefined ways.
// void draw_UI
// void draw_menu
void display_draw_gamestate();
void display_draw_snapshot(const struct Snapshot* snapshot);
// void update_window();

// exposing drawing related util functions for objects to use
extern SDL_Renderer *renderer;
SDL_Rect point_to_rect(const struct Point * point);

#endif