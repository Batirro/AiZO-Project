#include "algorithms/InsertionSort.hpp"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"

void InsertionSort::sort(Array& arr) {
    int n = arr.getSize();
    for (int i = 1; i < n; ++i) {
        int key = arr.get(i);
        int j = i - 1;

        while (j >= 0 && arr.get(j) > key) {
            arr.set(j + 1, arr.get(j));
            j = j - 1;
        }
        arr.set(j + 1, key);
    }
}

// TODO: Implementacja dla SinglyLinkedList
void InsertionSort::sort(SinglyLinkedList& list) {
    // Implementacja wkrótce
}

// TODO: Implementacja dla DoubleLinkedList
void InsertionSort::sort(DoubleLinkedList& list) {
    // Implementacja wkrótce
}
