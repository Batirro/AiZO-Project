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

void InsertionSort::sort(SinglyLinkedList& list) {
    Node* current = list.getHead();
    Node* sorted = nullptr;

    while (current != nullptr) {
        Node* next = current->next;

        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next != nullptr && search->next->data < current->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }
    list.setHead(sorted);
}

void InsertionSort::sort(DoubleLinkedList& list) {
    DNode* head = list.getHead();
    if (!head || !head->next) return;

    DNode* current = head->next;
    while (current != nullptr) {
        int key = current->data;
        DNode* search = current->prev;

        while (search != nullptr && search->data > key) {
            search->next->data = search->data;
            search = search->prev;
        }
        
        if (search == nullptr) {
            head->data = key;
        } else {
            search->next->data = key;
        }
        current = current->next;
    }
}
