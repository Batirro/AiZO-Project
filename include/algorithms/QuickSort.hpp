#pragma once

class Array;
class SinglyLinkedList;
class DoublyLinkedList;

class QuickSort {
public:
    static void sort(Array& arr);
    static void sort(SinglyLinkedList& list);
    static void sort(DoublyLinkedList& list);
};
