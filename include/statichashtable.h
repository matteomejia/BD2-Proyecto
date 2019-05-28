#ifndef STATIC_HASH_TABLE_H_
#define STATIC_HASH_TABLE_H_

#include "statichashtablenode.h"

//Unused file, meant for a more complex implementation

template <typename K, typename V>
class Hash
{
private:
    int capacity;
    int size;
    Node<K,V>** arr;
    Node<K,V>* ayuwoki;

public:
    Hash();

    int findKey(K key);
    void insertNode(K key, V value);
    V findValue(int key);
    void display();
};

#endif
