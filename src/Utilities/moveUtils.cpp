#include "moveUtils.h"

int getCoordinateX(uint32_t move) { return move >> 24; }
int getCoordinateY(uint32_t move) { return move >> 16 & 0xFF; }
int getPlayerNumber(uint32_t move) { return move & 0xFF; }
int getSpecialInformation(uint32_t move) { return move >> 8 & 0xFF; }
unsigned int setCoordinateX(uint32_t move, int coordinateX) {
  uint32_t info = coordinateX;
  uint32_t mask = 0xFFFFFF;
  info << 24;
  return (move & mask) | info;
}
unsigned int setCoordinateY(uint32_t move, int coordinateY) {
  uint32_t info = coordinateY;
  uint32_t mask = 0xFF00FFFF;
  info << 16;
  return (move & mask) | info;
}
unsigned int setPlayerNumber(uint32_t move, int playerNumber) {
  uint32_t info = playerNumber;
  uint32_t mask = 0xFFFFFF00;
  return (move & mask) | info;
}
unsigned int setSpecialInformation(uint32_t move, int specialInformation) {
  uint32_t info = specialInformation;
  uint32_t mask = 0xFFFF00FF;
  return (move & mask) | info;
}
unsigned int setChoice(uint32_t move, int playerNumber) {
  uint32_t info = playerNumber;
  uint32_t mask = 0xFFFF00FF;
  return (move & mask) | info;
}
unsigned int setBonus(uint32_t move, bool bomb) {
  uint32_t info = 0;
  if (bomb) {
    info = 20;
  } else {
    info = 21;
  }
  uint32_t mask = 0xFFFF00FF;
  return (move & mask) | info;
}