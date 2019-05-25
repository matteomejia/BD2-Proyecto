#ifndef STATIC_HASHING_H_
#define STATIC_HASHING_H_

#include "register.h"
#include "fileorganizer.h"
#include <list>

template <typename K, typename V>
class Node{
public:
    V value;
    K key;
    Node(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

template <typename K, typename V>
class Hash{
    int capacity;
    int size;
    Node<K,V>** arr;
    Node<K,V>* ayuwoki;

public:
    Hash(){
        capacity = 20;
        size=0;
        arr = new Node<K,V>*[capacity];
        for(int i=0 ; i < capacity ; i++)
            arr[i] = nullptr;
        ayuwoki = new Node<K,V>(-1, -1);
    };



    int findKey(K key){
        return key % capacity;
    };

    void insertNode(K key, V value){

        auto temp = new Node<K,V>(key, value);
        int hashIndex = findKey(key);

        while(arr[hashIndex] != nullptr && arr[hashIndex]->key != key && arr[hashIndex]->key != -1){
            hashIndex++;
            hashIndex %= capacity;
        }

        if(arr[hashIndex] == nullptr || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    };

    V findValue(int key){
        int hashIndex = findKey(key);
        int origIndex = hashIndex;
        while(arr[hashIndex] != nullptr && hashIndex != origIndex)
        {
            if(arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }
        return (V) nullptr;

    };

    void display(){
        for(int i=0 ; i<capacity ; i++){
            if(arr[i] != nullptr && arr[i]->key != -1)
                std::cout << "key = " << arr[i]->key
                     <<"  value = "<< arr[i]->value << "\n";
        }
    };


};


#endif
