NAME=T_snake


SOURCES = src/main.c src/display.c src/engine.c src/snake_obj.c src/pellet_obj.c src/timeline_manager.c
INCLUDES = src/display.h src/gamestate.h src/engine.h src/snake_obj.h src/pellet_obj.h src/timeline_manager.h
ASSETS = assets/FreeSans.ttf assets/Terminess_Mono.ttf

all: web linux

# web is based on emscripten.
EMCC = emcc
BROWSER = firefox
# BROWSER = chrome
EMRUM = emrun --browser $(BROWSER)
EMCC_FLAGS += -s WASM=1
EMCC_FLAGS += -s USE_SDL=2 -s USE_SDL_TTF=2
# EMCC_FLAGS += -s TOTAL_MEMORY=6710886400
EMCC_FLAGS += -s ALLOW_MEMORY_GROWTH=1
# EMCC_FLAGS += -s TOTAL_MEMORY=1342177280
EMCC_FLAGS += --emrun
EMCC_FLAGS += --preload-file assets
# EMCC_FLAGS += -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'

web: output/web/$(NAME).html output/web/$(NAME).js output/web/$(NAME).wasm
	@echo "created web version"

web-run: web
	@echo "running in $(BROWSER)"
	$(EMRUM) ./output/web/$(NAME).html

output/web/$(NAME).html output/web/$(NAME).js output/web/$(NAME).wasm &: $(SOURCES) $(INCLUDES)
	@echo "making $(@)"
	@mkdir -p ./output/web
	emcc $(SOURCES) $(EMCC_FLAGS) \
	-o output/web/$(NAME).html
# 	-o output/web/$(NAME).js



CC=gcc
CFLAGS=
LDFLAGS=-lSDL2 -lSDL2_ttf

linux: output/linux/$(NAME)
	@echo "created linux version"
	@mkdir -p ./output/linux/assets
	for file in $(ASSETS); do \
		echo $$file; \
		cp $$file output/linux/assets/ ; \
	done

linux-run: linux
	./output/linux/$(NAME)

output/linux/$(NAME): $(SOURCES) $(INCLUDES)
	@mkdir -p ./output/linux
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o output/linux/$(NAME)



clean:
	@echo "attempting to clean"
	rm -r output/

.PHONY: clean all web linux




# example of multistep emcc build:
# 	 emcc -Oz -DSCOREFILE=\"greed.hs\" -DRELEASE=\"1.0\" greed.c -o out\greed.bc -I dist-cursesjs\
# 	emcc -s ASYNCIFY=1 --emrun -O3 ..\out\greed.bc ..\dist-cursesjs\libcurses.o -o greedjs.html --preload-file pdcfont.bmp --preload-file pdcicon.bmp --shell-file ../template.html
