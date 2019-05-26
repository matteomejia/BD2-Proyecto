#ifndef STATIC_HASH_TABLE_NODE_H_
#define STATIC_HASH_TABLE_NODE_H_

template <typename K, typename V>
struct Node
{
public:
    V value;
    K key;
    Node(K key, V value);
};

#endif