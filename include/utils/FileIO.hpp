#pragma once
#include <string>

class Array;
class SinglyLinkedList;
class DoubleLinkedList;

class FileIO {
public:
    static Array* readArray(const std::string& filename);
    static SinglyLinkedList* readSinglyLinkedList(const std::string& filename);
    static DoubleLinkedList* readDoubleLinkedList(const std::string& filename);

    static bool writeArray(const std::string& filename, const Array& arr);
    static bool writeSinglyLinkedList(const std::string& filename, const SinglyLinkedList& list);
    static bool writeDoubleLinkedList(const std::string& filename, const DoubleLinkedList& list);
};
