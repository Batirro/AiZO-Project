#pragma once

class FloatArray {
private:
    float *data;
    int size;
public:
    explicit FloatArray(int size);
    ~FloatArray();
    FloatArray(const FloatArray &other);
    FloatArray &operator=(const FloatArray &other);

    float get(int index) const;
    void set(int index, float value);
    int getSize() const;

    void fillRandom();
    void fillSorted(bool ascending);
    void fillPartiallySorted(int percent);
};
