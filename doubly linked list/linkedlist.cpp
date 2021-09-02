#include <iostream>
#include "linkedlist.h"



template <typename T>
linkedList<T>::linkedList() {
    head = tail = NULL;
};


template <typename T>
linkedList<T>::~linkedList() {
    /* MUST TO AVOID MEMORY LEAK */
    node <T> *curr = head;
    node <T> *next = curr->next;
    
    //load around all list and delete all items
    while(curr != NULL) {
        delete curr;
        curr = next;
        next = curr->next != NULL ? curr->next : NULL;
    }
};

template <typename T>
bool linkedList<T>::is_empty() {return !size;} 

template <typename T>
int linkedList<T>::get_size() {return size;}

template <typename T>
T &linkedList<T>::operator[](int index) {
    if(index == 0 && head != NULL) return head->data;
    else if(index == size - 1 && tail != NULL) return tail->data;
    else if(index < size) {
        node<T> *curr = head;
        for(int i = 0;i < index;i++)curr = curr->next;

        return curr->data;
    }
}

template <typename T>
void linkedList<T>::print() {
    node <T> *curr = head; 
    
    while(curr != NULL) {
        std::cout << curr->data << " ";

        //loop until the next = NULL then stop
        if(curr->next != NULL) curr = curr->next;
        else break;
    }
    std::cout << '\n';

    
}

template <typename T>
void linkedList<T>::add_first(T value) {

    node <T> *newNode = new node<T>(value); // make new node at heap
    
    newNode->next = head; // assign the next to the previous head (if the list empty then to null)
    if(head != NULL) head->prev = newNode;
    
    head = newNode; //make it the head
    
    if(tail == NULL) tail = newNode; //if the list was empty make tail point to it

    size++; //increase size
    
}

template <typename T>
void linkedList<T>::add_last(T value) {

    node<T> *newNode = new node<T>(value);// make new node at heap

    newNode->prev = tail; //assign prev to previous tail

    if(tail != NULL) tail->next = newNode; //assign previos tail to new tail

    tail = newNode; //make it tail

    if(head == NULL) head = newNode; //if the list was empty make head point to it

    size++; //increase size
}

template <typename T>
void linkedList<T>::add(T value, int index) {
    if(index == 0) add_first(value);

    else if(index == size) add_last(value);

    else if(index < size) {

        node<T> *newNode = new node<T>(value);
        node<T> *prev = head;

        for(int i = 1; i < index;i++)  prev = prev->next;//loop till previous index

        newNode->next = prev->next; //assing the direction to the new node
        newNode->prev = prev;

        prev->next = newNode;//linked the new node to list by the previous item
        newNode->next->prev = newNode;
        size++;//increase size
        
    }
}

template <typename T>
void linkedList<T>::delete_first() {
    if(head != NULL) {
        node<T> *next = head->next;//store next item address

        delete head;

        head = next;//make the next head of list
        head->prev = NULL;
    }
}

template <typename T>
void linkedList<T>::delete_last() {
    node<T> *prev = tail->prev; //store prev item address

    delete tail;

    tail = prev;//make the previous item tail of list
    tail->next = NULL; /* IMPORTANT: to avoid infinty errors */
}

template <typename T>
void linkedList<T>::del(int index) {
    
    if(index == 0) delete_first();

    else if(index == size - 1) delete_last();

    else if(index < size) {

        /* get previous item */
        node<T> *prev = head;
        for(int i = 1;i < index ;i++) prev = prev->next; 

        node <T>*curr = prev->next; //srote the item to delete
        node <T>*next = curr->next; //store the next item

        prev->next = next;
        next->prev = prev;

        delete curr;
    }
    
}

template <typename T>
void linkedList<T>::reverse() {
    node<T> *curr = tail;
    node<T> *prev = tail->prev;
    /* loop backward and change links between nodes so previous become next */
    while(prev != NULL) {
        curr->next = prev;
        curr = prev;
        prev = curr->prev;
    }
    /* setup the head and tail */
    head = tail;
    tail = curr;
    tail->next = NULL; // IMPORTAN: to avoid infinty error

}
