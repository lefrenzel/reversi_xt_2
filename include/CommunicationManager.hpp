#ifndef COMMUNICATION_MANAGER
#define COMMUNICATION_MANAGER
#include <string>

class CommunicationManager {
public:
  CommunicationManager(const CommunicationManager &obj) = delete;
  static CommunicationManager* getInstance();

private:
  CommunicationManager(std::string, std::string) {}
  static std::string serverIp;
  static std::string serverPort;
  static CommunicationManager* instancePtr;
};

#endif