#include "structures/CharArray.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <limits>

CharArray::CharArray(int size) : size(size) { data = new char[size]; }
CharArray::~CharArray() { delete[] data; }
CharArray::CharArray(const CharArray& other) : size(other.size) {
    data = new char[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
}
CharArray& CharArray::operator=(const CharArray& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new char[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    return *this;
}
char CharArray::get(int index) const { return data[index]; }
void CharArray::set(int index, char value) { data[index] = value; }
int CharArray::getSize() const { return size; }

void CharArray::fillRandom() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<short> dist(32, 126);
    for (int i = 0; i < size; i++) data[i] = static_cast<char>(dist(rng));
}
void CharArray::fillSorted(bool ascending) {
    fillRandom();
    if (ascending) std::sort(data, data + size);
    else std::sort(data, data + size, std::greater<char>());
}
void CharArray::fillPartiallySorted(int percent) {
    fillRandom();
    int sortedCount = (size * percent) / 100;
    std::sort(data, data + sortedCount);
}
