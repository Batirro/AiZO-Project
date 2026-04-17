#pragma once
#include <string>

class Array;
class SinglyLinkedList;
class DoublyLinkedList;

class FileIO {
public:
    static Array* readArray(const std::string& filename);
    static SinglyLinkedList* readSinglyLinkedList(const std::string& filename);
    static DoublyLinkedList* readDoublyLinkedList(const std::string& filename);

    static bool writeArray(const std::string& filename, const Array& arr);
    static bool writeSinglyLinkedList(const std::string& filename, const SinglyLinkedList& list);
    static bool writeDoublyLinkedList(const std::string& filename, const DoublyLinkedList& list);
};
