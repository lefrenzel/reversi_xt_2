#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

#include "./ressources/constants/constants.h"

class Main {
public:
  Main(int argc, char *argv[]) {};
  void setServerIp(std::string ip) {
    // todo check for correct Ipv4 address
    this->serverIp = ip;
  }
  void setServerPort(std::string port) { this->serverPort = std::stoi(port); }
  void setAlgorithmChoice(std::string algorithmChoice) {
    // todo check for correct algorithmChoice
    this->algorithmChoice = std::stoi(algorithmChoice);
  }
  void setDepthLimit(std::string depthLimit) {
    // todo check for correct depthLimit
    this->depthLimit = std::stoi(depthLimit);
  }
  void setTimeLimit(std::string timeLimit) {
    // todo check for correct timeLimit
    this->timeLimit = std::stod(timeLimit);
  }

private:
  std::string serverIp;
  int serverPort;
  int algorithmChoice;
  int depthLimit;
  double timeLimit;
};

int main(int argc, char *argv[]) {
  try {
    parseConfigFile();
  } catch (const char *errorMessage) {
    std::cerr << errorMessage << std::endl;
  } catch (...) {
    std::cerr << "Error while reading config file." << std::endl;
  }

  Main client(argc, argv);
  try {
    if (argc == 1) {
      throw(0);
      return;
    }

    if ((argc % 2 == 0) && (argv[1] != "-h" || argv[1] != "--help")) {
      throw(1);
      return;
    }

    for (int i = 0; i < argc; i++) {
      std::string args(argv[i]);
      if (args == "-h" || args == "--help") {
        std::cout << HELP_TEXT << std::endl;
        return;
      } else if (args == "-i" || args == "--ip") {
        client.setServerIp(argv[i + 1]);
      } else if (args == "-p" || args == "--port") {
        client.setServerPort(argv[i + 1]);
      } else if (args == "-d" || args == "--depth") {
        client.setDepthLimit(argv[i + 1]);
      } else if (args == "-t" || args == "--time") {
        client.setTimeLimit(argv[i + 1]);
      }
    }

  } catch (int exception) {
    switch (exception) {
    case 1:
      std::cerr << "Invalid command line arguments\n";
      std::cout << HELP_TEXT << "\n";
      break;

    default:
      break;
    }
  } catch (std::invalid_argument) {
    std::cerr << "Invalid datatype for parameter setter\n";
  }

  return 0;
}