#pragma once

class CharArray {
private:
    char *data;
    int size;
public:
    explicit CharArray(int size);
    ~CharArray();
    CharArray(const CharArray &other);
    CharArray &operator=(const CharArray &other);

    char get(int index) const;
    void set(int index, char value);
    int getSize() const;

    void fillRandom();
    void fillSorted(bool ascending);
    void fillPartiallySorted(int percent);
};
