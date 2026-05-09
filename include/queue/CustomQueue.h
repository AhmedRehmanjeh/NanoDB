#ifndef CUSTOM_QUEUE_H
#define CUSTOM_QUEUE_H

#include "../storage/CustomVector.h"

template <typename T>
class CustomQueue {
private:
    CustomVector<T> container;
    size_t frontIndex;

public:
    CustomQueue() : frontIndex(0) {}

    void push(const T& value) {
        container.push_back(value);
    }

    void pop() {
        if (frontIndex < container.getSize()) {
            frontIndex++;
        }
    }

    T& front() {
        return container[frontIndex];
    }

    bool isEmpty() const {
        return frontIndex >= container.getSize();
    }

    size_t size() const {
        return container.getSize() - frontIndex;
    }
};

#endif
