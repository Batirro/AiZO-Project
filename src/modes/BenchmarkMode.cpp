#include "modes/BenchmarkMode.hpp"
#include "Parameters.h"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"
#include "algorithms/InsertionSort.hpp"
#include "algorithms/QuickSort.hpp"
#include "algorithms/BucketSort.hpp"
#include "utils/Timer.hpp"
#include "utils/Validator.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>

static std::string getAlgoName(Parameters::Algorithms algo) {
    switch(algo) {
        case Parameters::Algorithms::insertion: return "InsertionSort";
        case Parameters::Algorithms::quick: return "QuickSort";
        case Parameters::Algorithms::bucket: return "BucketSort";
        default: return "Unsupported/Unknown";
    }
}

static std::string getStructName(Parameters::Structures str) {
    switch(str) {
        case Parameters::Structures::array: return "Array";
        case Parameters::Structures::singleList: return "SinglyLinkedList";
        case Parameters::Structures::doubleList: return "DoublyLinkedList";
        default: return "Unsupported/Unknown";
    }
}

static std::string getDistName(Parameters::Distribution dist) {
    switch(dist) {
        case Parameters::Distribution::random: return "Random";
        case Parameters::Distribution::ascending: return "Ascending";
        case Parameters::Distribution::descending: return "Descending";
        case Parameters::Distribution::ascending50Per: return "Ascending 50%";
        default: return "Random/Unknown";
    }
}

void BenchmarkMode::run() {
    if (Parameters::structureSize <= 0 || Parameters::iterations <= 0 || Parameters::resultsFile.empty()) {
        std::cerr << "Błąd: Brak wymaganych parametrów! (rozmiar struktury, liczba iteracji, plik wyjściowy)" << std::endl;
        return;
    }

    std::cout << "Rozpoczynam badania (Benchmark Mode)..." << std::endl;
    std::cout << "Algorytm: " << getAlgoName(Parameters::algorithm) << std::endl;
    std::cout << "Struktura: " << getStructName(Parameters::structure) << std::endl;
    std::cout << "Rozkład: " << getDistName(Parameters::distribution) << std::endl;
    std::cout << "Rozmiar instancji: " << Parameters::structureSize << std::endl;
    std::cout << "Liczba iteracji: " << Parameters::iterations << std::endl;

    // Generujemy wspólną bazę danych dla wszystkich iteracji
    Array baseArray(Parameters::structureSize);
    
    // Wpływ rozkładu (Badanie B)
    if (Parameters::distribution == Parameters::Distribution::ascending) {
        baseArray.fillSorted(true);
    } else if (Parameters::distribution == Parameters::Distribution::descending) {
        baseArray.fillSorted(false);
    } else if (Parameters::distribution == Parameters::Distribution::ascending50Per) {
        baseArray.fillPartiallySorted(50);
    } else {
        baseArray.fillRandom();
    }

    std::vector<long long> times;
    times.reserve(Parameters::iterations);

    for (int i = 0; i < Parameters::iterations; ++i) {
        Timer timer;
        bool isSorted = false;

        if (Parameters::structure == Parameters::Structures::array) {
            Array copy = baseArray; // Zwykła kopia
            
            timer.start();
            if (Parameters::algorithm == Parameters::Algorithms::insertion) InsertionSort::sort(copy);
            else if (Parameters::algorithm == Parameters::Algorithms::quick) QuickSort::sort(copy);
            else if (Parameters::algorithm == Parameters::Algorithms::bucket) BucketSort::sort(copy);
            timer.stop();
            
            isSorted = Validator::isSorted(copy);
        } 
        else if (Parameters::structure == Parameters::Structures::singleList) {
            SinglyLinkedList copy;
            for (int j = Parameters::structureSize - 1; j >= 0; --j) {
                copy.pushFront(baseArray.get(j));
            }
            
            timer.start();
            if (Parameters::algorithm == Parameters::Algorithms::insertion) InsertionSort::sort(copy);
            else if (Parameters::algorithm == Parameters::Algorithms::quick) QuickSort::sort(copy);
            else if (Parameters::algorithm == Parameters::Algorithms::bucket) BucketSort::sort(copy);
            timer.stop();
            
            isSorted = Validator::isSorted(copy);
        } 
        else if (Parameters::structure == Parameters::Structures::doubleList) {
            DoubleLinkedList copy;
            for (int j = Parameters::structureSize - 1; j >= 0; --j) {
                copy.pushFront(baseArray.get(j));
            }
            
            timer.start();
            if (Parameters::algorithm == Parameters::Algorithms::insertion) InsertionSort::sort(copy);
            else if (Parameters::algorithm == Parameters::Algorithms::quick) QuickSort::sort(copy);
            else if (Parameters::algorithm == Parameters::Algorithms::bucket) BucketSort::sort(copy);
            timer.stop();
            
            isSorted = Validator::isSorted(copy);
        }

        if (!isSorted) {
            std::cerr << "\nBłąd weryfikacji w iteracji " << i << "! Struktura nie została poprawnie posortowana." << std::endl;
        }

        times.push_back(timer.getMicroseconds());

        if ((i + 1) % 10 == 0 || i == Parameters::iterations - 1) {
            std::cout << "Ukończono iterację: " << (i + 1) << " / " << Parameters::iterations << "\r" << std::flush;
        }
    }
    std::cout << std::endl;

    long long minTime = *std::min_element(times.begin(), times.end());
    long long maxTime = *std::max_element(times.begin(), times.end());
    long long sumTime = 0;
    for (long long t : times) sumTime += t;
    double avgTime = static_cast<double>(sumTime) / Parameters::iterations;

    std::ofstream csv(Parameters::resultsFile, std::ios::app);
    if (csv.is_open()) {
        csv.seekp(0, std::ios::end);
        if (csv.tellp() == 0) {
            csv << "Date,Algorithm,Structure,Distribution,Size,Iterations,MinTime_us,MaxTime_us,AvgTime_us\n";
        }

        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        csv << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S") << ","
            << getAlgoName(Parameters::algorithm) << ","
            << getStructName(Parameters::structure) << ","
            << getDistName(Parameters::distribution) << ","
            << Parameters::structureSize << ","
            << Parameters::iterations << ","
            << minTime << ","
            << maxTime << ","
            << avgTime << "\n";
        
        csv.close();
        std::cout << "Zapisano wyniki do pliku: " << Parameters::resultsFile << std::endl;
    } else {
        std::cerr << "Błąd: Nie można otworzyć pliku " << Parameters::resultsFile << " do zapisu!" << std::endl;
    }
}
