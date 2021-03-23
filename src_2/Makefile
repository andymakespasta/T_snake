################################
# Common environment variables #
################################
NAME=T_snake

export SOURCES = $(abspath $(wildcard *.cpp))
export INCLUDES = $(abspath $(wildcard *.hpp))
export THIRD_PARTY_INCLUDES = -I../output/SDL2_gfx/include/SDL2/ -I/usr/include/SDL2/
export THIRD_PARTY_LIBRARIES = -L../output/SDL2_gfx/lib -lSDL2_gfx
# export LD_RUN_PATH= $LD_RUN_PATH:
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/programming/T_snake/output/SDL2_gfx/lib

ASSETS = 

all: web linux

################################
# emscripten web version       #
################################
export EMCC = emcc

export BROWSER = firefox
# export BROWSER = chrome

export EMRUM = emrun --browser $(BROWSER)

EMCC_FLAGS += -s WASM=1
EMCC_FLAGS += -s USE_SDL=2 -s USE_SDL_TTF=2
# EMCC_FLAGS += -s TOTAL_MEMORY=6710886400
EMCC_FLAGS += -s ALLOW_MEMORY_GROWTH=1
# EMCC_FLAGS += -s TOTAL_MEMORY=1342177280
EMCC_FLAGS += --emrun
ifdef $(ASSETS)
EMCC_FLAGS += --preload-file $(ASSETS)
endif
# EMCC_FLAGS += -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'
export EMCC_FLAGS

web: output/web/$(NAME).html output/web/$(NAME).js output/web/$(NAME).wasm
	@echo "created web version"

web-run: web
	@echo "running in $(BROWSER)"
	$(EMRUM) ./output/web/$(NAME).html

output/web/$(NAME).html output/web/$(NAME).js output/web/$(NAME).wasm &: $(SOURCES) $(INCLUDES)
	@echo "building $(@)"
	@mkdir -p ./output/web
	emcc $(SOURCES) $(EMCC_FLAGS) \
			 -o output/web/$(NAME).html


##############################
# linux version
##############################

export CXX=g++
export CXXFLAGS= -I${CURDIR}
export LDFLAGS= -lSDL2 -lSDL2_ttf -lstdc++

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
	$(CC) $(CFLAGS) $(LDFLAGS) $(THIRD_PARTY_INCLUDES) $(THIRD_PARTY_LIBRARIES) \
	$(SOURCES) \
	-Wall -Wextra -g \
	-o output/linux/$(NAME)


##############################
test: $(SOURCES) $(INCLUDES)
	make -C test/

clean:
	@echo "removing output folder"
	rm -r output/

.PHONY: clean all web linux test
