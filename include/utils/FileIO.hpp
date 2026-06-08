#pragma once
#include <string>

class Array;
class SinglyLinkedList;
class DoublyLinkedList;
class Stack;
class FloatArray;
class UnsignedArray;
class CharArray;

class FileIO {
public:
    static Array* readArray(const std::string& filename);
    static SinglyLinkedList* readSinglyLinkedList(const std::string& filename);
    static DoublyLinkedList* readDoublyLinkedList(const std::string& filename);
    static Stack* readStack(const std::string& filename);
    static FloatArray* readFloatArray(const std::string& filename);
    static UnsignedArray* readUnsignedArray(const std::string& filename);
    static CharArray* readCharArray(const std::string& filename);

    static bool writeArray(const std::string& filename, const Array& arr);
    static bool writeSinglyLinkedList(const std::string& filename, const SinglyLinkedList& list);
    static bool writeDoublyLinkedList(const std::string& filename, const DoublyLinkedList& list);
    static bool writeStack(const std::string& filename, Stack& stack);
    static bool writeFloatArray(const std::string& filename, const FloatArray& arr);
    static bool writeUnsignedArray(const std::string& filename, const UnsignedArray& arr);
    static bool writeCharArray(const std::string& filename, const CharArray& arr);
};
