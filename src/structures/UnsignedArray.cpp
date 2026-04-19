#include "structures/UnsignedArray.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <limits>

UnsignedArray::UnsignedArray(int size) : size(size) { data = new unsigned int[size]; }
UnsignedArray::~UnsignedArray() { delete[] data; }
UnsignedArray::UnsignedArray(const UnsignedArray& other) : size(other.size) {
    data = new unsigned int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
}
UnsignedArray& UnsignedArray::operator=(const UnsignedArray& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new unsigned int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    return *this;
}
unsigned int UnsignedArray::get(int index) const { return data[index]; }
void UnsignedArray::set(int index, unsigned int value) { data[index] = value; }
int UnsignedArray::getSize() const { return size; }

void UnsignedArray::fillRandom() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<unsigned int> dist(0, 4000000000u);
    for (int i = 0; i < size; i++) data[i] = static_cast<unsigned int>(dist(rng));
}
void UnsignedArray::fillSorted(bool ascending) {
    fillRandom();
    if (ascending) std::sort(data, data + size);
    else std::sort(data, data + size, std::greater<unsigned int>());
}
void UnsignedArray::fillPartiallySorted(int percent) {
    fillRandom();
    int sortedCount = (size * percent) / 100;
    std::sort(data, data + sortedCount);
}
