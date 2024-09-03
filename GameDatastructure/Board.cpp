class Board {
public:
  Board() {}
  int* getValidMoves(int playerNumber);
  int* getValidMoves();
  void executeMove(int move);
private:
  unsigned int *board;
  void parseBoardString(char *boardString);
};

int* Board::getValidMoves(int playerNumber) {

}

int* Board::getValidMoves() {

}

void Board::executeMove(int move) {

}

