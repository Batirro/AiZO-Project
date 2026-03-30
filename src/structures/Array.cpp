#include "structures/Array.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <limits>



Array::Array(int size) : size(size) {
    data = new int[size];
}

Array::~Array() {
    delete[] data;
    data = nullptr;
}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

Array& Array::operator=(const Array& other) {
    // Zabezpieczenie przed self-assignment: a = a
    if (this == &other) {
        return *this;
    }

    // Zwolnij starą pamięć
    delete[] data;

    // Skopiuj nowe dane
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

int Array::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Array::get – indeks poza zakresem");
    }
    return data[index];
}

void Array::set(int index, int value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Array::set – indeks poza zakresem");
    }
    data[index] = value;
}

int Array::getSize() const {
    return size;
}

void Array::fillRandom() {
    // Mersenne Twister – lepszy generator niż rand()
    std::mt19937 rng(std::random_device{}());

    // Pełny zakres int: od INT_MIN do INT_MAX
    std::uniform_int_distribution<int> dist(
        std::numeric_limits<int>::min(),
        std::numeric_limits<int>::max()
    );

    for (int i = 0; i < size; i++) {
        data[i] = dist(rng);
    }
}

void Array::fillSorted(bool ascending) {
    
    fillRandom();

    if (ascending) {
        std::sort(data, data + size);
    } else {
        std::sort(data, data + size, std::greater<int>());
    }
}

void Array::fillPartiallySorted(int percent) {
    // Wypełnij losowo całą tablicę
    fillRandom();

    // Oblicz ile elementów ma być posortowanych
    int sortedCount = (size * percent) / 100;

    // Posortuj tylko pierwszy fragment
    std::sort(data, data + sortedCount);
}
