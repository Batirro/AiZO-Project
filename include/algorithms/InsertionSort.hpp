#pragma once

class Array;
class SinglyLinkedList;
class DoubleLinkedList;

class InsertionSort {
public:
    static void sort(Array& arr);
    static void sort(SinglyLinkedList& list);
    static void sort(DoubleLinkedList& list);
};
