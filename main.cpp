#include <stdio.h>
#include <string>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <map>

// Global variables
std::string CONFIG_PATH = "./ressources/config/client_globals.rc";
std::map<std::string, std::string> CONFIG;

class Main {
    public:
        Main(int argc, char* argv []) {
            for (int i = 0; i < argc; i++) {
                std::string args(argv[i]);
                if (args == "-h" || args == "--help") {
                    
                }
            }
        }

    private: 
        std::string serverIp;
        int serverPort;
        int algorithmChoice;
        int maxDepth;
        double timeLimit;

};

/// @brief Parses the config file and stores the read variables in a map
/// @return returns 1 if an error occured while reading the file
int parseConfigFile() {
    std::ifstream configFile(CONFIG_PATH);
    if(!configFile.is_open()) {
        std::cerr << "Unable to open config file at " << CONFIG_PATH << " ." << std::endl;
        return 1;
    }

    std::string line;
    std::string currentKey;
    std::string currentValue;

    while(std::getline(configFile, line)) {
    
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        // skip commented lines
        if(line.size() > 0 && line[0] == '#'){
            continue;
        }

        size_t equalsPos = line.find('=');
        if(equalsPos == std::string::npos) {
            continue;
        }

        currentKey = line.substr(0, equalsPos);
        currentValue = line.substr(equalsPos + 1);

        // Replaces all Escape characters in the config file with reals escape characters
        equalsPos = 0;
        while ((equalsPos = currentValue.find("\\n", equalsPos)) != std::string::npos) {
            currentValue.replace(equalsPos, 2, "\n");
            equalsPos++;
        }
        equalsPos = 0;
        while ((equalsPos = currentValue.find("\\t", equalsPos)) != std::string::npos) {
            currentValue.replace(equalsPos, 2, "\t");
            equalsPos++;
        }

        CONFIG[currentKey] = currentValue;
    }
    configFile.close();
    return 0;
}

int main(int argc, char* argv[]) {
    int errCode = 0;
    errCode = parseConfigFile();
    if(errCode != 0) {
        return 1;
    }
    Main client(argc, argv);
    
    return 0;
}