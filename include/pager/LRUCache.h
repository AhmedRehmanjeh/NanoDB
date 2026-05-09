#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include "linkedlist/DoublyLinkedList.h"
#include "hashmap/CustomHashMap.h"

class LRUCache {
private:
    DoublyLinkedList<int> list;
    CustomHashMap<int, Node<int>*> map;
    size_t capacity;

public:
    LRUCache(size_t cap) : capacity(cap) {}

    void refer(int pageId) {
        Node<int>* node;
        if (map.get(pageId, node)) {
            list.move_to_front(node);
        } else {
            if (list.getSize() == capacity) {
                int last = list.pop_back();
                map.remove(last);
            }
            Node<int>* newNode = list.push_front(pageId);
            map.put(pageId, newNode);
        }
    }

    int evict() {
        if (list.getSize() == 0) return -1;
        int last = list.pop_back();
        map.remove(last);
        return last;
    }

    size_t getSize() const { return list.getSize(); }
};

#endif
