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
class FloatArray;
class UnsignedArray;
class CharArray;

class QuickSortMultiType {
public:
    static void sort(FloatArray& arr);
    static void sort(UnsignedArray& arr);
    static void sort(CharArray& arr);
};
