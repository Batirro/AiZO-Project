#include "structures/SinglyLinkedList.hpp"
#include <stdexcept>


SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {} // Konstruktor domyślny

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;  // zapamiętaj następny przed usunięciem
        delete current;              // usuń bieżący węzeł
        current = next;              // przejdź do następnego
    }

    head = nullptr;
    size = 0;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
    : head(nullptr), size(0)
{
    // Przejdź przez wszystkie węzły oryginału i dodaj je do nowej listy
    Node* current = other.head;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other) {
    if (this == &other) {
        return *this;
    }

    // Zniszcz obecną zawartość
    this->~SinglyLinkedList();

    // Skopiuj węzły z other
    Node* current = other.head;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }

    return *this;
}

void SinglyLinkedList::pushFront(int value) {
    Node* newNode   = new Node(value);  // stwórz nowy węzeł
    newNode->next   = head;             // nowy węzeł wskazuje na stary head
    head            = newNode;          // head przesuwa się na nowy węzeł
    size++;
}

void SinglyLinkedList::pushBack(int value) {
    Node* newNode = new Node(value);

    // Przypadek szczególny – lista jest pusta
    if (head == nullptr) {
        head = newNode;
        size++;
        return;
    }

    // Przejdź do ostatniego węzła
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;  // ostatni węzeł wskazuje na nowy
    size++;
}

// Pomocnicza – zwraca wskaźnik na węzeł o danym indeksie
Node* SinglyLinkedList::getNode(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("SinglyLinkedList – indeks poza zakresem");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

int SinglyLinkedList::get(int index) const {
    return getNode(index)->data;
}

void SinglyLinkedList::set(int index, int value) {
    getNode(index)->data = value;
}

int SinglyLinkedList::getSize() const {
    return size;
}

void SinglyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("SinglyLinkedList::remove – indeks poza zakresem");
    }

    Node* toDelete = nullptr;

    // Przypadek szczególny – usuwamy pierwszy element
    if (index == 0) {
        toDelete = head;
        head     = head->next;
    } else {
        // Znajdź węzeł przed tym który usuwamy
        Node* prev = getNode(index - 1);
        toDelete   = prev->next;
        prev->next = toDelete->next;  // przeskocz usuwany węzeł
    }

    delete toDelete;
    size--;
}
