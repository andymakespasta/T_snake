
void render_drawobj_snake_echo(const struct SnakeEcho * echo, const SDL_Color color){
	SDL_SetRenderDrawColor( renderer, 0x80, 0x80, 0x40, 0x40 );
	SDL_Rect rect;
	for (int i=0; i<(snake->length); i++){
		rect = point_to_rect(&snake->body[i]);
		// SDL_RenderDrawRect(renderer, &rect); 
		SDL_RenderFillRect(renderer, &rect);//TODO: possible optimization using SDL_RenderFillRects	
	}
}