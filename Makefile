all:
	g++ main.cpp -o build.exe -lmingw32 -lsdl2main -lsdl2 -static-libstdc++ -static-libgcc -Wall