#include "structures/Stack.hpp"
#include "utils/FileIO.hpp"
#include "structures/Array.hpp"
#include "structures/SinglyLinkedList.hpp"
#include "structures/DoublyLinkedList.hpp"
#include <fstream>
#include <iostream>

Array* FileIO::readArray(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return nullptr;
    
    int size;
    if (!(file >> size)) return nullptr;
    
    Array* arr = new Array(size);
    int value;
    for (int i = 0; i < size; ++i) {
        if (file >> value) {
            arr->set(i, value);
        }
    }
    file.close();
    return arr;
}

SinglyLinkedList* FileIO::readSinglyLinkedList(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return nullptr;
    
    int size;
    if (!(file >> size)) return nullptr;
    
    SinglyLinkedList* list = new SinglyLinkedList();
    int value;
    for (int i = 0; i < size; ++i) {
        if (file >> value) {
            list->pushBack(value);
        }
    }
    file.close();
    return list;
}

DoublyLinkedList* FileIO::readDoublyLinkedList(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return nullptr;
    
    int size;
    if (!(file >> size)) return nullptr;
    
    DoublyLinkedList* list = new DoublyLinkedList();
    int value;
    for (int i = 0; i < size; ++i) {
        if (file >> value) {
            list->pushBack(value); // pushBack musi być w implementacji DLL
        }
    }
    file.close();
    return list;
}

bool FileIO::writeArray(const std::string& filename, const Array& arr) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    int size = arr.getSize();
    file << size << "\n";
    for (int i = 0; i < size; ++i) {
        file << arr.get(i) << "\n";
    }
    file.close();
    return true;
}

bool FileIO::writeSinglyLinkedList(const std::string& filename, const SinglyLinkedList& list) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    file << list.getSize() << "\n";
    Node* curr = list.getHead();
    while (curr) {
        file << curr->data << "\n";
        curr = curr->next;
    }
    file.close();
    return true;
}

bool FileIO::writeDoublyLinkedList(const std::string& filename, const DoublyLinkedList& list) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    file << list.getSize() << "\n";
    DNode* curr = list.getHead();
    while (curr) {
        file << curr->data << "\n";
        curr = curr->next;
    }
    file.close();
    return true;
}

Stack* FileIO::readStack(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return nullptr;
    int size; if (!(file >> size)) return nullptr;
    Stack* stack = new Stack();
    int value;
    Array temp(size);
    for (int i = 0; i < size; ++i) {
        if (file >> value) temp.set(i, value);
    }
    for (int i = size - 1; i >= 0; --i) stack->push(temp.get(i));
    file.close();
    return stack;
}
bool FileIO::writeStack(const std::string& filename, Stack& stack) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    file << stack.getSize() << "\n";
    Stack temp;
    while (!stack.isEmpty()) { temp.push(stack.top()); stack.pop(); }
    while (!temp.isEmpty()) {
        file << temp.top() << "\n";
        stack.push(temp.top());
        temp.pop();
    }
    file.close();
    return true;
}
