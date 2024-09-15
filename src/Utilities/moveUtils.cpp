#include "moveUtils.h"

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

/// @brief
/// @param move
/// @return
/// @todo should return an enum datatype which contains the type of special
/// move/stone
/// @todo add another function that returns the player number if this move is on
/// a choice square
int getSpecialInformation(uint32_t move) { return move >> 8 & 0xFF; }

/// @brief Sets the x-coordinate in the given move
/// @param move The move that will be modified
/// @param coordinateX The x-coordinate that will be set
/// @return The move with the set x-coordinate
unsigned int setCoordinateX(uint32_t move, int coordinateX) {
  uint32_t info = coordinateX;
  uint32_t mask = 0xFFFFFF;
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

/// @brief
/// @param move
/// @param specialInformation
/// @return
/// @todo change function to enable the information reading from an enum
/// datatype
unsigned int setSpecialInformation(uint32_t move, int specialInformation) {
  uint32_t info = specialInformation;
  uint32_t mask = 0xFFFF00FF;
  return (move & mask) | info;
}

/// @brief
/// @param move
/// @param playerNumber
/// @return
/// @todo setChoice and setBonus may be irrelevant or need to be adjusted
/// according to changes to set/getSpecialInformation function
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