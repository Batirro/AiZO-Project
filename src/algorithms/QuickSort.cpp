#include "algorithms/QuickSort.hpp"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"
#include <algorithm>

// --- Array ---
// Zastosowanie schematu Hoare'a z pivotem na środku (najlepsze dla częściowo posortowanych tablic)
static void quickSortArray(Array& arr, int low, int high) {
    if (low < high) {
        int pivot = arr.get((low + high) / 2);
        int i = low - 1;
        int j = high + 1;
        while (true) {
            do { i++; } while (arr.get(i) < pivot);
            do { j--; } while (arr.get(j) > pivot);
            if (i >= j) break;
            
            // Swap
            int temp = arr.get(i);
            arr.set(i, arr.get(j));
            arr.set(j, temp);
        }
        quickSortArray(arr, low, j);
        quickSortArray(arr, j + 1, high);
    }
}

void QuickSort::sort(Array& arr) {
    if (arr.getSize() > 0) {
        quickSortArray(arr, 0, arr.getSize() - 1);
    }
}

// --- SinglyLinkedList ---
// Pobieranie ostatniego elementu
static Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

// Schemat Lomuto (podział względem ostatniego elementu) ze swapowaniem wartości
static Node* partitionSLL(Node* head, Node* end) {
    int pivot = end->data;
    Node* i = head;
    for (Node* j = head; j != end; j = j->next) {
        if (j->data < pivot) {
            std::swap(i->data, j->data);
            i = i->next;
        }
    }
    std::swap(i->data, end->data);
    return i;
}

static void quickSortSLL(Node* head, Node* end) {
    if (head == nullptr || head == end || head == end->next) {
        return;
    }
    
    Node* pivotNode = partitionSLL(head, end);
    
    // Sortowanie lewej części
    if (pivotNode != head) {
        Node* temp = head;
        while (temp != nullptr && temp->next != pivotNode) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            quickSortSLL(head, temp);
        }
    }
    
    // Sortowanie prawej części
    if (pivotNode != nullptr && pivotNode != end) {
        quickSortSLL(pivotNode->next, end);
    }
}

void QuickSort::sort(SinglyLinkedList& list) {
    Node* head = list.getHead();
    if (head) {
        quickSortSLL(head, getTail(head));
    }
}

// --- DoublyLinkedList ---
// Schemat Lomuto
static DNode* partitionDLL(DNode* low, DNode* high) {
    int pivot = high->data;
    DNode* i = low;
    for (DNode* j = low; j != high; j = j->next) {
        if (j->data < pivot) {
            std::swap(i->data, j->data);
            i = i->next;
        }
    }
    std::swap(i->data, high->data);
    return i;
}

static void quickSortDLL(DNode* low, DNode* high) {
    if (high != nullptr && low != high && low != high->next) {
        DNode* pivotNode = partitionDLL(low, high);
        
        if (pivotNode != nullptr && pivotNode->prev != nullptr) {
            quickSortDLL(low, pivotNode->prev);
        }
        if (pivotNode != nullptr && pivotNode->next != nullptr) {
            quickSortDLL(pivotNode->next, high);
        }
    }
}

void QuickSort::sort(DoublyLinkedList& list) {
    DNode* head = list.getHead();
    DNode* tail = list.getTail();
    
    // Zabezpieczenie na wypadek, gdyby tail z jakiegoś powodu nie był zaktualizowany
    if (head != nullptr && tail == nullptr) {
        tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }

    if (head && tail) {
        quickSortDLL(head, tail);
    }
}
