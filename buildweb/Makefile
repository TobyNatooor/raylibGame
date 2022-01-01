default:
	emcc ../Block.cpp ../Bullet.cpp ../Enemy.cpp ../Entity.cpp ../Gravity.cpp ../main.cpp ../Object.cpp ../Player.cpp -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -o game.html -O2 -Wall -Wno-missing-braces -I ../include/ -L ../lib/web/ -lraylib -lglfw --preload-file shaders/base_lighting.vs --preload-file shaders/lighting.fs
