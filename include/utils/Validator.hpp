#pragma once

class Array;
class SinglyLinkedList;
class DoubleLinkedList;

class Validator {
public:
    static bool isSorted(const Array& arr);
    static bool isSorted(const SinglyLinkedList& list);
    static bool isSorted(const DoubleLinkedList& list);
};
