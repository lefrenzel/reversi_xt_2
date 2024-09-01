.DEFAULT_GOAL = client02
OBJ_DIR = object_files
CXX = g++
CXXFLAGS = 
CONST_PATH = ressources/constants
object_files = $(OBJ_DIR)/main.o $(OBJ_DIR)/constants.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

client02: $(OBJ_DIR) $(object_files)
	@echo "Linking the client..."
	$(CXX) -o client02 $(object_files)

$(OBJ_DIR)/main.o: main.cpp $(CONST_PATH)/constants.h
	@echo "Compiling main.cpp..."
	$(CXX) -c -o $(OBJ_DIR)/main.o main.cpp

$(OBJ_DIR)/constants.o: $(CONST_PATH)/constants.cpp $(CONST_PATH)/constants.h
	@echo "Compiling constants.cpp..."
	$(CXX) -c -o $(OBJ_DIR)/constants.o $(CONST_PATH)/constants.cpp

launch: client02
	./client02 -h

clean:
	@echo "Removing everything but the source files..."
	rm -rf $(OBJ_DIR)

