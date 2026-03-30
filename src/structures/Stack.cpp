#include "structures/Stack.hpp"
#include <stdexcept>


void Stack::push(int value) {
    list.pushFront(value);
}


void Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack::pop – stos jest pusty");
    }
    list.remove(0);  // usuwamy pierwszy element listy = szczyt stosu
}

// Podejrzyj szczyt bez usuwania
int Stack::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack::top – stos jest pusty");
    }
    return list.get(0);  // pierwszy element listy = szczyt stosu
}

bool Stack::isEmpty() const {
    return list.getSize() == 0;
}

int Stack::getSize() const {
    return list.getSize();
}
