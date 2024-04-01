#pragma once
#include<iostream>

template <class T>
class Node{
public:
    Node* next;
    Node* prev;
    T data;
    Node(T value){
        prev = nullptr;
        data = value;
        next = nullptr;
    };
};

template <class T>
class LinkedList{
    Node<T>* Head;
    Node<T>* current;
    Node<T>* SeeNextPtr;
    bool SeeNextHead;
public:

    LinkedList(){
        Head = nullptr;
        current = nullptr;
        SeeNextPtr = nullptr;
        SeeNextHead = false;
    }

    ~LinkedList() {
        current = Head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        Head = nullptr;
        SeeNextPtr = nullptr;
    }

    // Function to check if the list is empty
    bool isEmpty() const {
         return Head == NULL;
     }

    // Function to return the size of the list
    int Size() const {
        Node<T>* temp = Head;
        int count = 0;
        temp = Head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    // This insert function has a big O of O(n) bc there is n comparisons.
    void AddItem(T value){
        Node<T>* temp = Head;
        if(Head == NULL){
            Head = new Node<T>(value);
            Head->next = nullptr;
            SeeNextPtr = Head;
            SeeNextPtr = Head;
            return;
        }

        if (value < Head->data){
            Head = new Node<T>(value);
            Head->next = temp;
            temp->prev = Head;
            SeeNextPtr = Head;
            SeeNextPtr = Head;
            return;
        }
        temp = Head;
        while(temp->next != nullptr && value > temp->data){
            temp = temp->next;
        }
        Node<T>* newNode = new Node<T>(value);
        if(value < temp->data){
            temp=temp->prev;
            temp->next->prev = newNode;
            newNode->next = temp->next;
        }
        if(value < temp->data){
            temp=temp->prev;
            temp->next->prev = newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        else{
            temp->next = newNode;
            newNode->prev = temp;
        }
        
    }

    T* GetItem(T item){
        Node<T>* temp = Head;
        if(isEmpty()) return nullptr;
        // if linked list list empty write code
        if (temp->next == nullptr) {
            if(Head->data == item){
                temp = Head;
                Head = NULL;
                return &temp->data;
            }
        }
        while(temp->next != nullptr && !(item == temp->data)){
            temp = temp->next;
        }

        if (temp == nullptr) {
            return nullptr;
        }
        if(temp->prev == nullptr){
            T* t = &temp->data;
            Head = temp->next;
            Head->prev = nullptr;
            Head->prev = nullptr;
            return t;   
        }
        else if (temp->next == nullptr){
            temp->prev->next = nullptr;
            T* t = &temp->data;
            return t;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            T* t = &temp->data;
            return t;
        }
    }

    void display(){
        Node<T>* temp = Head;
        std::cout << temp->data << " ";
        while(temp->next!= nullptr){
            temp = temp->next;
            std::cout << temp->data << " ";
        }
    }

        // check if an item is in the list
        bool IsInList(const T& item) const {
            Node<T>* temp = Head;
            while (temp != nullptr) {
                if (temp->data == item) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

    T* SeeNext() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot see next item, list is empty.");
        }
        if(SeeNextPtr == nullptr) return nullptr;
        else if(SeeNextPtr == Head && !(SeeNextHead)){
            SeeNextHead = true;
            return &Head->data;
        } 
        else{
            SeeNextPtr = SeeNextPtr->next;
            return &SeeNextPtr->data;
        }
    }

    T* SeePrev() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot see next item, list is empty.");
        }
        if(SeeNextPtr == nullptr) return nullptr;
        else{
            SeeNextPtr = SeeNextPtr->prev;
            return &SeeNextPtr->data;
        }
    }

    T SeeAt(int position){
        if (isEmpty()) throw std::runtime_error("Cannot see any item, list is empty.");
        Node<T>* temp = Head;
        SeeNextPtr = Head;
        if(position == 1) return temp->data;
        while(position > 1){
            if(temp->next == nullptr) throw std::runtime_error("Cannot see any item, list is empty.");
            temp = temp->next;
            SeeNextPtr = SeeNextPtr->next;
            position--;
        }
        return temp->data;
    }

    void Reset(){
        SeeNextPtr = Head;
        SeeNextHead = false;
    }

};