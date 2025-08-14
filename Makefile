all:
	g++ main.cpp player.cpp -o mazegame.exe -lmingw32 -lsdl2main -lsdl2 -static-libstdc++ -static-libgcc -Wall -mwindows