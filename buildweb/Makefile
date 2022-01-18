
CC = emcc
CFLAGS += -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1 -o game.html -I ../include/ -L ../lib/web/ -lraylib -lglfw
CFLAGS += --preload-file shaders/base_lighting.vs --preload-file shaders/lighting.fs --profiling
CFLAGS += -Wall -D_DEFAULT_SOURCE -Wno-missing-braces -Werror=pointer-arith -fno-strict-aliasing
CFLAGS += -Werror=implicit-function-declaration
CFLAGS += -DPLATFORM_WEB
CFLAGS+= --shell-file game.html

CPPFILES = $(wildcard ../*.cpp)

compile:
	${CC} ${CPPFILES} ${CFLAGS}
