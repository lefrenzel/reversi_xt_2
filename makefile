TMP_FOLDER = ./object_files
.DEFAULT_GOAL := all

all: start final 

start:
	mkdir -p $(TMP_FOLDER)

final: main.o constants.o
	@echo "Linking the client..."
	g++ $(TMP_FOLDER)/main.o $(TMP_FOLDER)/constants.o -o client02
	rm -rf $(TMP_FOLDER)

main.o: main.cpp
	@echo "Compiling main.cpp..."
	g++ -c main.cpp -o $(TMP_FOLDER)/main.o

constants.o: ressources/constants/constants.cpp
	@echo "Compiling constants.cpp..."
	g++ -c ressources/constants/constants.cpp -o $(TMP_FOLDER)/constants.o

launch: all
	./client02 -h

clean:
	@echo "Removing everything but the source files..."
	rm -rf $(TMP_FOLDER)

