
CC = emcc
CFLAGS += -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -o game.html -O2 -I ../include/ -L ../lib/web/ -lraylib -lglfw
CFLAGS += --preload-file shaders/base_lighting.vs --preload-file shaders/lighting.fs
CFLAGS += -Wall -D_DEFAULT_SOURCE -Wno-missing-braces -Werror=pointer-arith -fno-strict-aliasing
CFLAGS += -Werror=implicit-function-declaration
# CFLAGS += -std=gnu99
# CFLAGS += -std=c99
CFLAGS += -s -O1
CFLAGS += -Os

CPPFILES = $(wildcard ../*.cpp)

compile:
	${CC} ${CPPFILES} ${CFLAGS}

# default:
# 	emcc ../Block.cpp ../Bullet.cpp ../Enemy.cpp ../Entity.cpp ../Gravity.cpp ../main.cpp ../Object.cpp ../Player.cpp -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -o game.html -O2 -Wall -Wno-missing-braces -I ../include/ -L ../lib/web/ -lraylib -lglfw --preload-file shaders/base_lighting.vs --preload-file shaders/lighting.fs
