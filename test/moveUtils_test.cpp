#include <iostream>
#include "moveUtils.h"

uint32_t move_in = 0;
int coordinateX_in = 0;
int coordinateY_in = 0;
int playerNumber_in = 1;
specialInfo specialInfo_in = normal;

int testPlayerNumber() {
  uint32_t move_out = 0;
  int playerNumber_test = 0;
  std::cout << "Testing player number handling...";
  for (playerNumber_in; playerNumber_in <= 8; playerNumber_in++) {
    move_out = setPlayerNumber(move_in, playerNumber_in);
    playerNumber_test = playerNumber_in & 0xFF;
    std::cout << std::hex << move_out << "\n";
    if (playerNumber_test = !getPlayerNumber(move_out)) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int coordinateX_out = 0;
  int coordinateY_out = 0;
  int playerNumber_out = 0;
  specialInfo specialInfo_out = normal;
  int testResults[8] = {0};
  testResults[0] = testPlayerNumber();

  int arrayElements = sizeof(testResults) / sizeof(testResults[0]);
  for (int i = 0; i < arrayElements; i++) {
    if (testResults[i] != 0) {
      return 1;
    }
  }
  return 0;
}
