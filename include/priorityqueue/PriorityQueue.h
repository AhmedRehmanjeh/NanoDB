#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../storage/CustomVector.h"
#include <algorithm>

template <typename T>
class PriorityQueue {
private:
    CustomVector<T> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                T temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.getSize();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) largest = left;
            if (right < size && heap[right] > heap[largest]) largest = right;

            if (largest != index) {
                T temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.getSize() - 1);
    }

    void pop() {
        if (heap.getSize() == 0) return;
        heap[0] = heap[heap.getSize() - 1];
        heap.pop_back();
        if (heap.getSize() > 0) heapifyDown(0);
    }

    T& top() {
        return heap[0];
    }

    bool isEmpty() const {
        return heap.getSize() == 0;
    }
};

#endif
