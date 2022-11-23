build:
	g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o "Saving-the-wild" -lSDL2main -lSDL2 -lSDL2_image

play:
	./"Saving-the-wild"
clean:
	rm "Saving-the-wild"
release:
	g++ -c src/*.cpp -std=c++14 -m64 -O3 -Wall -I include && g++ *.o -o "Saving-the-wild" -s -lSDL2main -lSDL2 -lSDL2_image
