#ifndef CUSTOM_STACK_H
#define CUSTOM_STACK_H

#include "storage/CustomVector.h"

template <typename T>
class CustomStack {
private:
    CustomVector<T> container;

public:
    void push(const T& value) {
        container.push_back(value);
    }

    void pop() {
        container.pop_back();
    }

    T& top() {
        return container[container.getSize() - 1];
    }

    bool isEmpty() const {
        return container.getSize() == 0;
    }

    size_t size() const {
        return container.getSize();
    }
};

#endif
