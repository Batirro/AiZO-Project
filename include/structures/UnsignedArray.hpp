#pragma once

class UnsignedArray {
private:
    unsigned int *data;
    int size;
public:
    explicit UnsignedArray(int size);
    ~UnsignedArray();
    UnsignedArray(const UnsignedArray &other);
    UnsignedArray &operator=(const UnsignedArray &other);

    unsigned int get(int index) const;
    void set(int index, unsigned int value);
    int getSize() const;

    void fillRandom();
    void fillSorted(bool ascending);
    void fillPartiallySorted(int percent);
};
