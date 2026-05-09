#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

#include <iostream>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    CustomVector() : data(nullptr), capacity(0), size(0) {}
    
    ~CustomVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    T& back() {
        return data[size - 1];
    }

    const T& back() const {
        return data[size - 1];
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    void clear() {
        size = 0;
    }
};

#endif
