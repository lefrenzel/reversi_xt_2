#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#include<cstdint>

int getCoordinateX(uint32_t move);
int getCoordinateY(uint32_t move);
int getPlayerNumber(uint32_t move);
int getSpecialInformation(uint32_t move);

#endif