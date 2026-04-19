#include "structures/FloatArray.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <limits>

FloatArray::FloatArray(int size) : size(size) { data = new float[size]; }
FloatArray::~FloatArray() { delete[] data; }
FloatArray::FloatArray(const FloatArray& other) : size(other.size) {
    data = new float[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
}
FloatArray& FloatArray::operator=(const FloatArray& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new float[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    return *this;
}
float FloatArray::get(int index) const { return data[index]; }
void FloatArray::set(int index, float value) { data[index] = value; }
int FloatArray::getSize() const { return size; }

void FloatArray::fillRandom() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<float> dist(-1000.0f, 1000.0f);
    for (int i = 0; i < size; i++) data[i] = static_cast<float>(dist(rng));
}
void FloatArray::fillSorted(bool ascending) {
    fillRandom();
    if (ascending) std::sort(data, data + size);
    else std::sort(data, data + size, std::greater<float>());
}
void FloatArray::fillPartiallySorted(int percent) {
    fillRandom();
    int sortedCount = (size * percent) / 100;
    std::sort(data, data + sortedCount);
}
