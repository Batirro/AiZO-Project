#pragma once

class Array {
    private:
        int *data;
        int size;
    public:
        explicit Array(int size);
        ~Array();

        // Kopiowanie i przypisanie (Rule Of Three) / Bez tego będzie tylko kopia wskaźnika
        Array(const Array &other);
        Array &operator=(const Array &other);

        // Gettery i settery
        int get(int index) const;
        void set(int index, int value);
        int getSize() const;

        // Funkcje pomocnicze
        void fillRandom();
        void fillSorted(bool ascending);
        void fillPartiallySorted(int percent); // Do badania B
};
