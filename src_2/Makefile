################################
# Common environment variables #
################################
NAME=T_snake

export SOURCES = $(wildcard *.cpp)
export INCLUDES = $(wildcard *.h)
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
EMCC_FLAGS += --preload-file assets
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
export LDFLAGS= -lSDL2 -lSDL2_ttf

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


##############################
test: $(SOURCES) $(INCLUDES)
	make -C test/

clean:
	@echo "removing output folder"
	rm -r output/

.PHONY: clean all web linux test