#include <iostream>
#include "CommunicationManager.hpp"
#include <constants.h>
#include <asio.hpp>

CommunicationManager::CommunicationManager(std::string ip, std::string port) {
  serverIp = ip;
  serverPort = port;
}

/// @brief Returns the CommunicationManager object if it exists, otherwise it is instantiated
/// @param ip The ip of the server to which a connection will be established.
/// @param port The port of the server to which a connection will be established.
/// @return Returns the CommunicationManager object
CommunicationManager* CommunicationManager::getInstance() {
  if(instancePtr == nullptr) {
    instancePtr = new CommunicationManager(STANDARD_IP, STANDARD_PORT);
  }
  return instancePtr;
}