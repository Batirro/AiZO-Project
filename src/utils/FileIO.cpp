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

DoubleLinkedList* FileIO::readDoubleLinkedList(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return nullptr;
    
    int size;
    if (!(file >> size)) return nullptr;
    
    DoubleLinkedList* list = new DoubleLinkedList();
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

bool FileIO::writeDoubleLinkedList(const std::string& filename, const DoubleLinkedList& list) {
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
