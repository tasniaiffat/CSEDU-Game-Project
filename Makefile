build:
	g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o "Saving-the-wild" -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

play:
	./"Saving-the-wild"
clean:
	rm "Saving-the-wild"
release:
	g++ -c src/*.cpp -std=c++14 -m64 -O3 -Wall -ftrapv -I include && g++ *.o -o "Saving-the-wild" -s -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
game:
	g++ -c src/*.cpp -std=c++14 -m64 -O3 -ftrapv -I include && g++ *.o -o "Saving-the-wild" -s -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf && ./"Saving-the-wild"
