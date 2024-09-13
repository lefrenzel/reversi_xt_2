#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

#include "./src/ConstantsHandling/constants.h"

class Main {
public:
  Main() {
    this->serverIp = STANDARD_IP;
    this->serverPort = std::stoi(STANDARD_PORT);
    this->algorithmChoice = std::stoi(STANDARD_ALGORITHM);
    this->depthLimit = std::stoi(STANDARD_DEPTH);
    this->timeLimit = std::stod(STANDARD_TIME);
  };

  void setServerIp(std::string ip) { this->serverIp = ip; }
  void setServerPort(std::string port) { this->serverPort = std::stoi(port); }
  void setAlgorithmChoice(std::string algorithmChoice) {
    int algorithm = std::stoi(algorithmChoice);
    if (algorithm < 0) {
      throw("Invalid algorithm choice: " + algorithmChoice);
    }
    this->algorithmChoice = algorithm;
  }
  void setDepthLimit(std::string depthLimit) {
    int depth = std::stoi(depthLimit);
    if (depth < 0) {
      throw("Invalid depth limit: " + depthLimit);
    }
    this->depthLimit = depth;
  }
  void setTimeLimit(std::string timeLimit) {
    int time = std::stoi(timeLimit);
    if (time < 0) {
      throw("Invalid time limit: " + timeLimit);
    }
    this->timeLimit = time;
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

  Main client;
  try {
    if (argc == 1) {
      throw(0);
    }

    if ((argc % 2 == 0) && (argv[1] != "-h" || argv[1] != "--help")) {
      throw(1);
    }

    for (int i = 0; i < argc; i++) {
      std::string args(argv[i]);
      if (args == "-h" || args == "--help") {
        std::cout << HELP_TEXT << std::endl;
        return 0;
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

  } catch (int invalid_cl_argument) {
    switch (invalid_cl_argument) {
    case 1:
      std::cerr << "Invalid command line arguments\n";
      std::cout << HELP_TEXT << "\n";
      break;

    default:
      break;
    }
  } catch (std::string invalid_argument_range) {
    std::cerr << invalid_argument_range;
  } catch (std::invalid_argument) {
    std::cerr << "Invalid datatype for parameter setter\n";
  }
  return 0;
}