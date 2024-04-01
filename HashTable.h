template <class T>
class HashTable{
    int SIZE = 100;
    T table[];
    int status[];

    //Default constructor
    HashTable(){
        table = T[SIZE];
        status = int[SIZE];
    }

    //Counstructor that allows for a different size
    HashTable(int size){
        SIZE = size;
        table = T[SIZE];
        status = int[SIZE];
    }
    int Hash(T value){
        //TODO
    }

    void insert(T value){
        int hashValue = Hash(value);
        if(table[hashValue] == NULL){
            table[hashValue] = value;
            return;
        }

        while(table[hashValue+1 % SIZE] != NULL){
            hashValue = (hashValue + 1) % SIZE;
        }
        table[hashValue] = value;
        status[hashValue] = 1;
    }

    T* getItem(T key){
        int index = Hash(key);
        while(table[index] != key && table[index] != NULL && status != 0){
            index++;
        }
        if (table[index] == NULL){
            //throw not found?
        }
        return &table[index];
    }

    T* remove(T key){
        int hashValue = Hash(key);
        T* temp;
        while(table[hashValue] != key && table[hashValue] != NULL && status != 0){
            hashValue++;
        }
        if (table[hashValue] == NULL){
            //throw not found?
        }
        temp = new T(table[hashValue]);
        table[hashValue] = NULL;
        status[hashValue] = -1;
        return temp;
    }
};