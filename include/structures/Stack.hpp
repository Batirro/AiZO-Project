#pragma once
#include "DoublyLinkedList.hpp"

class Stack {
private:
    DoublyLinkedList list;
    // getSize() delegujemy do listy
public:
    Stack() = default;
    ~Stack() = default;

    Stack(const Stack& other) = default;
    Stack& operator=(const Stack& other) = default;

    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    int getSize() const;
};
