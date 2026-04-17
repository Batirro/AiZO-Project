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
