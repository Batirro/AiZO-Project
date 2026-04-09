#include "utils/Validator.hpp"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"

bool Validator::isSorted(const Array& arr) {
    int n = arr.getSize();
    for (int i = 1; i < n; ++i) {
        if (arr.get(i - 1) > arr.get(i)) {
            return false;
        }
    }
    return true;
}

bool Validator::isSorted(const SinglyLinkedList& list) {
    Node* head = list.getHead();
    if (!head || !head->next) return true;
    
    Node* curr = head;
    while (curr->next) {
        if (curr->data > curr->next->data) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

bool Validator::isSorted(const DoubleLinkedList& list) {
    DNode* head = list.getHead();
    if (!head || !head->next) return true;
    
    DNode* curr = head;
    while (curr->next) {
        if (curr->data > curr->next->data) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}
