#include "utils/Validator.hpp"
#include "structures/FloatArray.hpp"
#include "structures/UnsignedArray.hpp"
#include "structures/CharArray.hpp"

bool ValidatorMultiType::isSorted(const FloatArray& arr) {
    for (int i = 1; i < arr.getSize(); ++i) if (arr.get(i - 1) > arr.get(i)) return false;
    return true;
}
bool ValidatorMultiType::isSorted(const UnsignedArray& arr) {
    for (int i = 1; i < arr.getSize(); ++i) if (arr.get(i - 1) > arr.get(i)) return false;
    return true;
}
bool ValidatorMultiType::isSorted(const CharArray& arr) {
    for (int i = 1; i < arr.getSize(); ++i) if (arr.get(i - 1) > arr.get(i)) return false;
    return true;
}
