
CC = emcc
CFLAGS += -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -o game.html -I ../include/ -L ../lib/web/ -lraylib -lglfw
CFLAGS += --preload-file shaders/base_lighting.vs --preload-file shaders/lighting.fs
CFLAGS += -Wall -D_DEFAULT_SOURCE -Wno-missing-braces -Werror=pointer-arith -fno-strict-aliasing
CFLAGS += -Werror=implicit-function-declaration
CFLAGS += -s -O1
CFLAGS += -Os

CPPFILES = $(wildcard ../*.cpp)

compile:
	${CC} ${CPPFILES} ${CFLAGS}
