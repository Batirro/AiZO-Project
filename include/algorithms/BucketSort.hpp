#pragma once

class Array;
class SinglyLinkedList;
class DoublyLinkedList;

class BucketSort {
public:
    static void sort(Array& arr);
    static void sort(SinglyLinkedList& list);
    static void sort(DoublyLinkedList& list);
};
