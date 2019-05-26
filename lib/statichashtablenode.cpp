#include "statichashtablenode.h"

template <typename K, typename V>
Node<K, V>::Node(K key, V value)
{
    this->value = value;
    this->key = key;
}
