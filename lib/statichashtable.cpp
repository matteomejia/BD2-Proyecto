#include <iostream>

#include "statichashtablenode.h"
#include "statichashtable.h"

template <typename K, typename V>
Hash<K, V>::Hash()
{
    capacity = 20;
    size = 0;
    arr = new Node<K,V>*[capacity];

    for (int i = 0 ; i < capacity ; i++)
	{
        arr[i] = nullptr;
	}

    ayuwoki = new Node<K,V>(-1, -1);
}



template <typename K, typename V>
int Hash<K, V>::findKey(K key)
{
    return key % capacity;
}

template <typename K, typename V>
void Hash<K, V>::insertNode(K key, V value)
{
    auto temp = new Node<K,V>(key, value);
    int hashIndex = findKey(key);

    while (arr[hashIndex] != nullptr &&
		arr[hashIndex]->key != key &&
		arr[hashIndex]->key != -1)
	{
        hashIndex++;
        hashIndex %= capacity;
    }

    if (arr[hashIndex] == nullptr || arr[hashIndex]->key == -1)
	{
        size++;
	}

    arr[hashIndex] = temp;
}

template <typename K, typename V>
V Hash<K, V>::findValue(int key)
{
    int hashIndex = findKey(key);
    int origIndex = hashIndex;
	
    while (arr[hashIndex] != nullptr && hashIndex != origIndex)
    {
        if (arr[hashIndex]->key == key)
		{
            return arr[hashIndex]->value;
		}

        hashIndex++;
        hashIndex %= capacity;
    }

	// What is the return value of this?
    return (V) nullptr;
}

template <typename K, typename V>
void Hash<K, V>::display()
{
    for (int i = 0 ; i < capacity ; i++)
	{
        if (arr[i] != nullptr && arr[i]->key != -1)
		{
            std::cout << "key = " << arr[i]->key
                 << "  value = "<< arr[i]->value << std::endl;
		}
    }
}
