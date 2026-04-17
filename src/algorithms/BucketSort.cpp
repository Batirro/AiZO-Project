#include "algorithms/BucketSort.hpp"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"
#include "algorithms/InsertionSort.hpp"

// Metoda pomocnicza dla ułatwienia operacji na wiaderkach - bezpieczne rzutowanie i unikanie przepełnienia
static inline int getBucketIndex(int value, int min_val, int max_val, int num_buckets) {
    double range = static_cast<double>(max_val) - static_cast<double>(min_val);
    double offset = static_cast<double>(value) - static_cast<double>(min_val);
    return static_cast<int>((offset / range) * (num_buckets - 1));
}

void BucketSort::sort(Array& arr) {
    int n = arr.getSize();
    if (n <= 1) return;

    int min_val = arr.get(0);
    int max_val = arr.get(0);
    for (int i = 1; i < n; i++) {
        int val = arr.get(i);
        if (val < min_val) min_val = val;
        if (val > max_val) max_val = val;
    }

    if (min_val == max_val) return;

    int num_buckets = n;
    // Używamy naszej własnej, niedawno ulepszonej struktury jako kubełka!
    SinglyLinkedList* buckets = new SinglyLinkedList[num_buckets];

    for (int i = 0; i < n; i++) {
        int val = arr.get(i);
        int idx = getBucketIndex(val, min_val, max_val, num_buckets);
        buckets[idx].pushFront(val); // pushFront jest bardzo szybki (O(1))
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        InsertionSort::sort(buckets[i]); // Sortujemy kubełek
        
        Node* current = buckets[i].getHead();
        while (current != nullptr) {
            arr.set(index++, current->data);
            current = current->next;
        }
    }

    delete[] buckets; // Zwolnienie pamięci (destruktor SinglyLinkedList usunie węzły)
}

void BucketSort::sort(SinglyLinkedList& list) {
    Node* head = list.getHead();
    if (!head || !head->next) return;

    int n = 0;
    int min_val = head->data;
    int max_val = head->data;
    
    Node* curr = head;
    while (curr) {
        if (curr->data < min_val) min_val = curr->data;
        if (curr->data > max_val) max_val = curr->data;
        n++;
        curr = curr->next;
    }

    if (min_val == max_val) return;

    int num_buckets = n;
    SinglyLinkedList* buckets = new SinglyLinkedList[num_buckets];

    curr = head;
    while (curr) {
        int val = curr->data;
        int idx = getBucketIndex(val, min_val, max_val, num_buckets);
        buckets[idx].pushFront(val);
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < num_buckets; i++) {
        InsertionSort::sort(buckets[i]);
        Node* b_curr = buckets[i].getHead();
        while (b_curr != nullptr) {
            curr->data = b_curr->data; // Nadpisujemy wartości, wskaźników list nie ruszamy (szybciej)
            curr = curr->next;
            b_curr = b_curr->next;
        }
    }

    delete[] buckets;
}

void BucketSort::sort(DoublyLinkedList& list) {
    DNode* head = list.getHead();
    if (!head || !head->next) return;

    int n = 0;
    int min_val = head->data;
    int max_val = head->data;
    
    DNode* curr = head;
    while (curr) {
        if (curr->data < min_val) min_val = curr->data;
        if (curr->data > max_val) max_val = curr->data;
        n++;
        curr = curr->next;
    }

    if (min_val == max_val) return;

    int num_buckets = n;
    SinglyLinkedList* buckets = new SinglyLinkedList[num_buckets];

    curr = head;
    while (curr) {
        int val = curr->data;
        int idx = getBucketIndex(val, min_val, max_val, num_buckets);
        buckets[idx].pushFront(val);
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < num_buckets; i++) {
        InsertionSort::sort(buckets[i]);
        Node* b_curr = buckets[i].getHead();
        while (b_curr != nullptr) {
            curr->data = b_curr->data;
            curr = curr->next;
            b_curr = b_curr->next;
        }
    }

    delete[] buckets;
}
