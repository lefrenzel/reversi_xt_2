#include "constants.h"
#include <fstream>
#include <iostream>

// Global variables
std::string HELP_TEXT;
std::string STANDARD_IP;
std::string STANDARD_PORT;
std::string STANDARD_DEPTH;
std::string STANDARD_TIME;
std::string STANDARD_ALGORITHM;
std::string CONFIG_PATH = "../../ressources/config/client_globals.rc";

/// @brief Parses the config file and stores variables as global variables.
void parseConfigFile() {
  std::ifstream configFile(CONFIG_PATH);
  if (!configFile.is_open()) {
    std::string errorMessage =
        "Unable to open config file at " + CONFIG_PATH + ".";
    throw errorMessage;
    return;
  }

  std::string line;
  std::string currentKey;
  std::string currentValue;

  while (std::getline(configFile, line)) {

    line.erase(0, line.find_first_not_of(" \t"));
    line.erase(line.find_last_not_of(" \t") + 1);

    // skip commented lines
    if (line.size() > 0 && line[0] == '#') {
      continue;
    }

    // skip lines without '='
    size_t equalsPos = line.find('=');
    if (equalsPos == std::string::npos) {
      continue;
    }

    currentKey = line.substr(0, equalsPos);
    currentValue = line.substr(equalsPos + 1);

    // Replaces all Escape characters in the config file with reals escape
    // characters
    equalsPos = 0;
    while ((equalsPos = currentValue.find("\\n", equalsPos)) !=
           std::string::npos) {
      currentValue.replace(equalsPos, 2, "\n");
      equalsPos++;
    }
    equalsPos = 0;
    while ((equalsPos = currentValue.find("\\t", equalsPos)) !=
           std::string::npos) {
      currentValue.replace(equalsPos, 2, "\t");
      equalsPos++;
    }

    if (currentKey == "help_text") {
      HELP_TEXT = currentValue;
    } else if (currentKey == "standard_ip") {
      STANDARD_IP = currentValue;
    } else if (currentKey == "standard_port") {
      STANDARD_PORT = currentValue;
    } else if (currentKey == "standard_time") {
      STANDARD_TIME = currentValue;
    } else if (currentKey == "standard_depth") {
      STANDARD_DEPTH = currentValue;
    } else if (currentKey == "standard_algorithm") {
      STANDARD_ALGORITHM = currentValue;
    }
  }
  configFile.close();
  return;
}