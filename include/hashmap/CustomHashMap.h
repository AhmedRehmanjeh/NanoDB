#ifndef CUSTOM_HASHMAP_H
#define CUSTOM_HASHMAP_H

#include <iostream>

template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    HashNode* next;

    HashNode(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

template <typename K, typename V>
class CustomHashMap {
private:
    HashNode<K, V>** table;
    size_t capacity;
    size_t size;

    size_t hash(const K& key) const {
        // Simple hash for integers
        return (size_t)key % capacity;
    }

public:
    CustomHashMap(size_t cap = 101) : capacity(cap), size(0) {
        table = new HashNode<K, V>*[capacity]();
    }

    ~CustomHashMap() {
        for (size_t i = 0; i < capacity; ++i) {
            HashNode<K, V>* entry = table[i];
            while (entry != nullptr) {
                HashNode<K, V>* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void put(const K& key, const V& value) {
        size_t index = hash(key);
        HashNode<K, V>* prev = nullptr;
        HashNode<K, V>* entry = table[index];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new HashNode<K, V>(key, value);
            if (prev == nullptr) {
                table[index] = entry;
            } else {
                prev->next = entry;
            }
            size++;
        } else {
            entry->value = value;
        }
    }

    bool get(const K& key, V& value) const {
        size_t index = hash(key);
        HashNode<K, V>* entry = table[index];

        while (entry != nullptr) {
            if (entry->key == key) {
                value = entry->value;
                return true;
            }
            entry = entry->next;
        }
        return false;
    }

    bool remove(const K& key) {
        size_t index = hash(key);
        HashNode<K, V>* prev = nullptr;
        HashNode<K, V>* entry = table[index];

        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            return false;
        } else {
            if (prev == nullptr) {
                table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            size--;
            return true;
        }
    }

    size_t getSize() const { return size; }
};

#endif
