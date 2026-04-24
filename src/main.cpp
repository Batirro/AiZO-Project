#include <iostream>
#include "Parameters.h"
#include "modes/SingleFileMode.hpp"
#include "modes/BenchmarkMode.hpp"

int main(int argc, char **argv) {
    int result = Parameters::readParameters(argc - 1, argv + 1);
    if (result != 0) {
        std::cerr << "Błąd wczytywania parametrów." << std::endl;
        return 1;
    }

    switch (Parameters::runMode) {
        case Parameters::RunModes::help:
            Parameters::help();
            break;
            
        case Parameters::RunModes::singleFile:
            SingleFileMode::run();
            break;
            
        case Parameters::RunModes::benchmark:
            BenchmarkMode::run();
            break;

        case Parameters::RunModes::undefined:
        default:
            std::cerr << "Nie podano trybu działania. Użyj --help." << std::endl;
            return 1;
    }
    return 0;
}
