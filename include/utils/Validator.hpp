#pragma once

class Array;
class SinglyLinkedList;
class DoublyLinkedList;

class Validator {
public:
    static bool isSorted(const Array& arr);
    static bool isSorted(const SinglyLinkedList& list);
    static bool isSorted(const DoublyLinkedList& list);
};
class FloatArray;
class UnsignedArray;
class CharArray;

class ValidatorMultiType {
public:
    static bool isSorted(const FloatArray& arr);
    static bool isSorted(const UnsignedArray& arr);
    static bool isSorted(const CharArray& arr);
};
