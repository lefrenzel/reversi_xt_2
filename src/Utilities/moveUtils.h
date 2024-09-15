#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#include <cstdint>
#include <map>

enum specialInfo {
  normal = 0,
  choicePlayer1,
  choicePlayer2,
  choicePlayer3,
  choicePlayer4,
  choicePlayer5,
  choicePlayer6,
  choicePlayer7,
  choicePlayer8,
  newBomb = 20,
  newOverride = 21
};

const std::map<int, specialInfo> specialInfoLookup = {
  {0, normal},
  {1, choicePlayer1},
  {2, choicePlayer2},
  {3, choicePlayer3},
  {4, choicePlayer4},
  {5, choicePlayer5},
  {6, choicePlayer6},
  {7, choicePlayer7},
  {8, choicePlayer8},
  {20, newBomb},
  {21, newOverride}
};

int getCoordinateX(uint32_t move);
int getCoordinateY(uint32_t move);
int getPlayerNumber(uint32_t move);
specialInfo getSpecialInfo(uint32_t move);
unsigned int setCoordinateX(uint32_t move, int coordinateX);
unsigned int setCoordinateY(uint32_t move, int coordinateY);
unsigned int setPlayerNumber(uint32_t move, int playerNumber);
unsigned int setSpecialInfo(uint32_t move, specialInfo specialInfo);
specialInfo getSpecialInfoFrom(int info);

#endif