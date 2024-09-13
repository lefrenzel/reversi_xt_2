#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#include<cstdint>

int getCoordinateX(uint32_t move);
int getCoordinateY(uint32_t move);
int getPlayerNumber(uint32_t move);
int getSpecialInformation(uint32_t move);
unsigned int setCoordinateX(uint32_t move, int coordinateX);
unsigned int setCoordinateY(uint32_t move, int coordinateY);
unsigned int setPlayerNumber(uint32_t move, int playerNumber);
unsigned int setSpecialInformation(uint32_t move, int specialInformation);
unsigned int setChoice(uint32_t move, int playerNumber);
unsigned int setBonus(uint32_t move, int bonusChoice);

#endif