#include "structures/Stack.hpp"
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

bool Validator::isSorted(const DoublyLinkedList& list) {
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

bool Validator::isSorted(Stack& stack) {
    if (stack.isEmpty()) return true;
    
    int prev = stack.top();
    stack.pop();
    
    Stack temp;
    temp.push(prev);
    
    bool sorted = true;
    while (!stack.isEmpty()) {
        int curr = stack.top();
        stack.pop();
        temp.push(curr);
        
        if (prev > curr) {
            sorted = false;
            break;
        }
        prev = curr;
    }
    
    while (!temp.isEmpty()) {
        stack.push(temp.top());
        temp.pop();
    }
    return sorted;
}
