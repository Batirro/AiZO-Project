#include "modes/SingleFileMode.hpp"
#include "Parameters.h"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"
#include "algorithms/InsertionSort.hpp"
#include "algorithms/QuickSort.hpp"
#include "algorithms/BucketSort.hpp"
#include "utils/FileIO.hpp"
#include "utils/Timer.hpp"
#include "utils/Validator.hpp"
#include <iostream>

void SingleFileMode::run() {
    if (Parameters::inputFile.empty()) {
        std::cerr << "Błąd: Nie podano pliku wejściowego!" << std::endl;
        return;
    }

    Timer timer;
    bool isSorted = false;

    if (Parameters::structure == Parameters::Structures::array) {
        Array* arr = FileIO::readArray(Parameters::inputFile);
        if (!arr) {
            std::cerr << "Błąd: Nie można wczytać pliku do tablicy!" << std::endl;
            return;
        }

        timer.start();
        if (Parameters::algorithm == Parameters::Algorithms::insertion) {
            InsertionSort::sort(*arr);
        } else if (Parameters::algorithm == Parameters::Algorithms::quick) {
            QuickSort::sort(*arr);
        } else if (Parameters::algorithm == Parameters::Algorithms::bucket) {
            BucketSort::sort(*arr);
        } else {
            std::cerr << "Błąd: Nieznany lub nieobsługiwany algorytm!" << std::endl;
            delete arr;
            return;
        }
        timer.stop();

        isSorted = Validator::isSorted(*arr);
        if (!Parameters::outputFile.empty()) {
            FileIO::writeArray(Parameters::outputFile, *arr);
        }
        delete arr;

    } else if (Parameters::structure == Parameters::Structures::singleList) {
        SinglyLinkedList* list = FileIO::readSinglyLinkedList(Parameters::inputFile);
        if (!list) {
            std::cerr << "Błąd: Nie można wczytać pliku do listy jednokierunkowej!" << std::endl;
            return;
        }

        timer.start();
        if (Parameters::algorithm == Parameters::Algorithms::insertion) {
            InsertionSort::sort(*list);
        } else if (Parameters::algorithm == Parameters::Algorithms::quick) {
            QuickSort::sort(*list);
        } else if (Parameters::algorithm == Parameters::Algorithms::bucket) {
            BucketSort::sort(*list);
        } else {
            std::cerr << "Błąd: Nieznany lub nieobsługiwany algorytm!" << std::endl;
            delete list;
            return;
        }
        timer.stop();

        isSorted = Validator::isSorted(*list);
        if (!Parameters::outputFile.empty()) {
            FileIO::writeSinglyLinkedList(Parameters::outputFile, *list);
        }
        delete list;

    } else if (Parameters::structure == Parameters::Structures::doubleList) {
        DoubleLinkedList* list = FileIO::readDoubleLinkedList(Parameters::inputFile);
        if (!list) {
            std::cerr << "Błąd: Nie można wczytać pliku do listy dwukierunkowej!" << std::endl;
            return;
        }

        timer.start();
        if (Parameters::algorithm == Parameters::Algorithms::insertion) {
            InsertionSort::sort(*list);
        } else if (Parameters::algorithm == Parameters::Algorithms::quick) {
            QuickSort::sort(*list);
        } else if (Parameters::algorithm == Parameters::Algorithms::bucket) {
            BucketSort::sort(*list);
        } else {
            std::cerr << "Błąd: Nieznany lub nieobsługiwany algorytm!" << std::endl;
            delete list;
            return;
        }
        timer.stop();

        isSorted = Validator::isSorted(*list);
        if (!Parameters::outputFile.empty()) {
            FileIO::writeDoubleLinkedList(Parameters::outputFile, *list);
        }
        delete list;

    } else {
        std::cerr << "Błąd: Nieznana lub nieobsługiwana struktura danych!" << std::endl;
        return;
    }

    std::cout << "Sortowanie zakończone." << std::endl;
    std::cout << "Czas sortowania: " << timer.getMicroseconds() << " mikrosekund." << std::endl;
    std::cout << "Poprawność sortowania: " << (isSorted ? "TAK (Rosnąco)" : "NIE") << std::endl;
}
