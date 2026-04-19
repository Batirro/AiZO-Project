#include "algorithms/QuickSort.hpp"
#include "structures/FloatArray.hpp"
#include "structures/UnsignedArray.hpp"
#include "structures/CharArray.hpp"
#include <algorithm>

template <typename ArrType, typename T>
static void quickSortBase(ArrType& arr, int low, int high) {
    if (low < high) {
        T pivot = arr.get((low + high) / 2);
        int i = low - 1;
        int j = high + 1;
        while (true) {
            do { i++; } while (arr.get(i) < pivot);
            do { j--; } while (arr.get(j) > pivot);
            if (i >= j) break;
            T temp = arr.get(i);
            arr.set(i, arr.get(j));
            arr.set(j, temp);
        }
        quickSortBase<ArrType, T>(arr, low, j);
        quickSortBase<ArrType, T>(arr, j + 1, high);
    }
}

void QuickSortMultiType::sort(FloatArray& arr) { if (arr.getSize() > 0) quickSortBase<FloatArray, float>(arr, 0, arr.getSize() - 1); }
void QuickSortMultiType::sort(UnsignedArray& arr) { if (arr.getSize() > 0) quickSortBase<UnsignedArray, unsigned int>(arr, 0, arr.getSize() - 1); }
void QuickSortMultiType::sort(CharArray& arr) { if (arr.getSize() > 0) quickSortBase<CharArray, char>(arr, 0, arr.getSize() - 1); }
