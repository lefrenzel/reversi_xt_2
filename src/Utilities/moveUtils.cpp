#include "moveUtils.h"
#include <iostream>

/// @brief Returns the x-coordinate stored in a move
/// @param move The move which contains the wanted x-coordinate
/// @return X-coordinate of the given move
int getCoordinateX(uint32_t move) { return move >> 24; }

/// @brief Returns the y-coordinate stored in a move
/// @param move The move which contains the wanted y-coordinate
/// @return Y-coordinate of the given move
int getCoordinateY(uint32_t move) { return move >> 16 & 0xFF; }

/// @brief Returns the player number of the player who plays the given move
/// @param move The move which contains the wanted player number
/// @return Player number of the player who plays the move
int getPlayerNumber(uint32_t move) { return move & 0xFF; }

/// @brief Returns the type of action associated with the square the move was
/// played on
/// @param move The move which constains the action/square-type
/// @return Type of action associated with the square the move was played on
specialInfo getSpecialInfo(uint32_t move) {
  int temp = move >> 8 & 0xFF;
  return getSpecialInfoFrom(temp);
}

/// @brief Sets the x-coordinate in the given move
/// @param move The move that will be modified
/// @param coordinateX The x-coordinate that will be set
/// @return The move with the set x-coordinate
unsigned int setCoordinateX(uint32_t move, int coordinateX) {
  uint32_t info = coordinateX;
  uint32_t mask = 0x00FFFFFF;
  info << 24;
  return (move & mask) | info;
}

/// @brief Sets the y-coordinate in the given move
/// @param move The move that will be modified
/// @param coordinateX The y-coordinate that will be set
/// @return The move with the set y-coordinate
unsigned int setCoordinateY(uint32_t move, int coordinateY) {
  uint32_t info = coordinateY;
  uint32_t mask = 0xFF00FFFF;
  info << 16;
  return (move & mask) | info;
}

/// @brief Sets the player number of the player who plays the given move
/// @param move The move that will be modified
/// @param playerNumber The player number of the player who plays the move
/// @return The move with set player number
unsigned int setPlayerNumber(uint32_t move, int playerNumber) {
  uint32_t info = playerNumber;
  uint32_t mask = 0xFFFFFF00;
  return (move & mask) | info;
}

/// @brief Sets the special information of a move
/// @param move The move that will be modified
/// @param specialInformation The information that needs to be set
/// @return The move with set player number
unsigned int setSpecialInfo(uint32_t move, specialInfo specialInfo) {
  uint32_t info = specialInfo;
  uint32_t mask = 0xFFFF00FF;
  return (move & mask) | info;
}

specialInfo getSpecialInfoFrom(int temp) {
  auto it = specialInfoLookup.find(temp);
  if (it != specialInfoLookup.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid special information bits.");
  }
}