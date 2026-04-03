# pragma once

struct DNode {
  int data;
  DNode* next;
  DNode* prev;

  explicit DNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
    DNode* head;
    DNode* tail;
    int size;

    DNode* getNode(int index) const;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    // Rule of Three
    DoubleLinkedList(const DoubleLinkedList& other);
    DoubleLinkedList& operator=(const DoubleLinkedList& other);

    // Gettery i Settery
    int get(int index) const;
    void set(int index, int value);
    int getSize() const;

    DNode* getHead() const { return head; }
    DNode* getTail() const { return tail; }
    void setHead(DNode* newHead) { head = newHead; }
    void setTail(DNode* newTail) { tail = newTail; }

    void pushFront(int value);
    void pushBack(int value);
    void remove(int index);
};
