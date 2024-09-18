#include "moveUtils.h"
#include <iostream>

uint32_t move_in = 0;
int coordinateX_in = 0;
int coordinateY_in = 0;
int playerNumber_in = 1;
specialInfo specialInfo_in = normal;

int testPlayerNumber() {
  uint32_t move_out = 0;
  int playerNumber_correct = 0;
  for (playerNumber_in; playerNumber_in <= 8; playerNumber_in++) {
    move_out = setPlayerNumber(move_in, playerNumber_in);
    playerNumber_correct = playerNumber_in & 0xFF;
    if (playerNumber_correct != getPlayerNumber(move_out)) {
      return 1;
    }
  }
  return 0;
}

int testCoordinateX() {
  uint32_t move_out = 0;
  int coordinateX_correct = 0;
  for (coordinateX_in; coordinateX_in < 50; coordinateX_in++) {
    move_out = setCoordinateX(move_in, coordinateX_in);
    coordinateX_correct = move_in & 0xFF000000;
    if (coordinateX_correct != getCoordinateX(move_out)) {
      return 1;
    }
  }
  return 0;
}

int testCoordinateY() {
  uint32_t move_out = 0;
  int coordinateY_correct = 0;
  for (coordinateY_in; coordinateY_in < 50; coordinateY_in++) {
    move_out = setCoordinateX(move_in, coordinateY_in);
    coordinateY_correct = move_in & 0x00FF0000;
    if (coordinateY_correct != getCoordinateY(move_out)) {
      return 1;
    }
  }
  return 0;
}

int testSpecialInfo() {
  uint32_t move_out = 0;
  for (auto it = specialInfoLookup.begin(); it != specialInfoLookup.end();
       ++it) {
    int enumValue = it->first;
    specialInfo info = it->second;
    move_out = setSpecialInfo(move_in, info);
    if (info != getSpecialInfo(move_out)) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int coordinateY_out = 0;
  int playerNumber_out = 0;
  specialInfo specialInfo_out = normal;
  int testResults[8] = {0};
  testResults[0] = testPlayerNumber();
  testResults[1] = testCoordinateX();
  testResults[2] = testCoordinateY();

  int arrayElements = sizeof(testResults) / sizeof(testResults[0]);
  for (int i = 0; i < arrayElements; i++) {
    if (testResults[i] != 0) {
      return 1;
    }
  }
  return 0;
}
