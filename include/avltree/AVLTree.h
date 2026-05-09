#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>

template <typename K, typename V>
class AVLNode {
public:
    K key;
    V value;
    AVLNode *left, *right;
    int height;

    AVLNode(K k, V v) : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
};

template <typename K, typename V>
class AVLTree {
private:
    AVLNode<K, V>* root;

    int height(AVLNode<K, V>* n) { return n ? n->height : 0; }

    int getBalance(AVLNode<K, V>* n) { return n ? height(n->left) - height(n->right) : 0; }

    AVLNode<K, V>* rotateRight(AVLNode<K, V>* y) {
        AVLNode<K, V>* x = y->left;
        AVLNode<K, V>* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode<K, V>* rotateLeft(AVLNode<K, V>* x) {
        AVLNode<K, V>* y = x->right;
        AVLNode<K, V>* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode<K, V>* insert(AVLNode<K, V>* node, K key, V value) {
        if (!node) return new AVLNode<K, V>(key, value);

        if (key < node->key) node->left = insert(node->left, key, value);
        else if (key > node->key) node->right = insert(node->right, key, value);
        else return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) return rotateRight(node);
        if (balance < -1 && key > node->right->key) return rotateLeft(node);
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool search(AVLNode<K, V>* node, K key, V& value) {
        if (!node) return false;
        if (node->key == key) {
            value = node->value;
            return true;
        }
        if (key < node->key) return search(node->left, key, value);
        return search(node->right, key, value);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(K key, V value) {
        root = insert(root, key, value);
    }

    bool search(K key, V& value) {
        return search(root, key, value);
    }
};

#endif
