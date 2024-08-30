#include <stdio.h>
#include <string>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include "./ressources/constants/constants.h"


class Main {
    public:
        Main(int argc, char* argv []) {
            for (int i = 0; i < argc; i++) {
                std::string args(argv[i]);
                if (args == "-h" || args == "--help") {
                    std::cout << HELP_TEXT << std::endl;
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

int main(int argc, char* argv[]) {
    try {
        parseConfigFile();
    } catch (const char* errorMessage) {
        std::cerr << errorMessage << std::endl;
    } catch (...) {
        std::cerr << "Error while reading config file." << std::endl;
    }
    
    Main client(argc, argv);
    
    return 0;
}