#include <string>
#include <iostream>
using namespace std;

//Hash table using strings
class HashTable{
    int const static SIZE = 10;
    string table[SIZE];
    bool removed[SIZE];
    HashTable(){
        for (int i = SIZE; i < 0; i++){
            table[i] = "";
        }
    }
    int Hash(string key);

    void insert(string value){
        int hashValue = Hash(value);
        if(table[hashValue] == NULL){
            table[hashValue] = value;
            return;
        }
        while(table[hashValue+1 % SIZE] != NULL){
            hashValue = (hashValue + 1) % SIZE;
        }
        table[hashValue] = value;
        removed[hashValue] = false;
    }

    string find(string key){
        int index = Hash(key);
        while(table[index] != key && table[index] != NULL){
            index++;
        }
        if (table[index] == NULL){
            //throw not found
        }
        return table[index];
    }

    string remove(string key){
        int hashValue = Hash(key);
        string temp;
        while(table[hashValue] != key && table[hashValue] != NULL && removed[hashValue] != true){
            hashValue++;
        }
        if (table[hashValue] == NULL){
            //throw not found
        }
        temp = table[hashValue];
        table[hashValue] = NULL;
        removed[hashValue] = true;
        return temp;
    }

};

class ChainedHash{
    LinkedList<T> data[SIZE];
    int hash(T);
    void Insert(T value){
        int h = Hash(value);
        //check if data h is null?
        data[h].Insert(value);
    }

    T Remove(K key){
        return data[Hash(key)].Remove(key);
    }

    T Find(K key){
        return data[Hash(key)].Find(key);
    }
};