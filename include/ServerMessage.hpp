#include <cstdint>

class ServerMessage {
private:
  uint8_t messageType;
  uint32_t messageLength;
  uint8_t* messageContent;

public:
  ServerMessage();
  ~ServerMessage();
  uint8_t getMessageType();
  uint32_t getMessageLength();
  uint8_t* getMessageContent();
  void setMessageType(uint8_t messageType);
  void setMessageLength(uint32_t messageLength);
  void setMessageContent(uint8_t* messageContent);
};
