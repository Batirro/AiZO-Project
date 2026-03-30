#include "structures/DoublyLinkedList.hpp"
#include <stdexcept>


DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    DNode* current = head;

    while (current != nullptr) {
        DNode* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
    : head(nullptr), tail(nullptr), size(0)
{
    DNode* current = other.head;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other) {
    if (this == &other) {
        return *this;
    }

    this->~DoublyLinkedList();

    DNode* current = other.head;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }

    return *this;
}

DNode* DoublyLinkedList::getNode(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("DoublyLinkedList – indeks poza zakresem");
    }

    // Jeśli indeks bliżej końca – idź od tail, będzie szybciej
    if (index < size / 2) {
        // Szukamy od head do przodu
        DNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    } else {
        // Szukamy od tail do tyłu
        DNode* current = tail;
        for (int i = size - 1; i > index; i--) {
            current = current->prev;
        }
        return current;
    }
}

void DoublyLinkedList::pushFront(int value) {
    DNode* newNode = new DNode(value);

    // Przypadek szczególny – lista pusta
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        size++;
        return;
    }

    newNode->next = head;   // nowy węzeł wskazuje na stary head
    head->prev    = newNode; // stary head wskazuje prev na nowy węzeł
    head          = newNode; // head przesuwa się na nowy węzeł
    size++;
}

void DoublyLinkedList::pushBack(int value) {
    DNode* newNode = new DNode(value);

    // Przypadek szczególny – lista pusta
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
        size++;
        return;
    }

    newNode->prev = tail;    // nowy węzeł wskazuje prev na stary tail
    tail->next    = newNode; // stary tail wskazuje next na nowy węzeł
    tail          = newNode; // tail przesuwa się na nowy węzeł
    size++;
}

int DoublyLinkedList::get(int index) const {
    return getNode(index)->data;
}

void DoublyLinkedList::set(int index, int value) {
    getNode(index)->data = value;
}

int DoublyLinkedList::getSize() const {
    return size;
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("DoublyLinkedList::remove – indeks poza zakresem");
    }

    DNode* toDelete = getNode(index);

    // Napraw wskaźnik węzła poprzedniego
    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    } else {
        // Usuwamy head – przesuń head na następny
        head = toDelete->next;
    }

    // Napraw wskaźnik węzła następnego
    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
    } else {
        // Usuwamy tail – przesuń tail na poprzedni
        tail = toDelete->prev;
    }

    delete toDelete;
    size--;
}
