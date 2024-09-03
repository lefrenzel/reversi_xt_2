#include "moveUtils.h"

int getCoordinateX(uint32_t move) { return move >> 24; }
int getCoordinateY(uint32_t move) { return move >> 16 & 0xFF; }
int getPlayerNumber(uint32_t move) { return move & 0xFF; }
int getSpecialInformation(uint32_t move) { return move >> 8 & 0xFF; }