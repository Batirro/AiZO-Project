#pragma once

struct Node {
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node *head; // Pointer na pierwszy node
    int size;
    Node* getNode(int index) const;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    // Rule Of Three
    SinglyLinkedList(const SinglyLinkedList &other);
    SinglyLinkedList& operator=(const SinglyLinkedList &other);

    //Gettery i Settery
    int get(int index) const;
    void set(int index, int value);
    int getSize() const;

    Node* getHead() const { return head; }
    void setHead(Node* newHead) { head = newHead; }

    void pushFront(int value);
    void pushBack(int value);
    void remove(int index);
};
