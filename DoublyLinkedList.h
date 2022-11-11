#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include <string>
#include <iostream>
using namespace std;


template <class T>
class DoublyLinkedList {
    
protected:
    Node<T> *first = nullptr;      //a pointer to the first of the linked list
    Node<T> *last = nullptr;       //a pointer to the last node of the linked list
    Node<T> *iterator = nullptr;   //an internal iterator for the linked list object
    int length = 0;          //number of items in the linked list
                                                                    
public:
    //default no-argument constructor
    DoublyLinkedList() = default;

    //destructor  
    ~DoublyLinkedList() {
        clear();
    }
    
    //copy constructor
    DoublyLinkedList(const DoublyLinkedList<T> &other) {
        *this = other;
    }

    //copy assignment operator
    DoublyLinkedList operator=(const DoublyLinkedList<T> &other) {
        if (this == other) { // we don't need to do anything if they're the same thing
            return *this;
        }
        
        clear();

        if (!other.first) { // don't need to copy any elements over if it's empty
            return *this;
        }
        
        // create the first node
        Node *otherNode = other.first;
        first = new Node();
        first->data = otherNode->data;
        last = first;
        otherNode = otherNode->next;

        // add in all the other Nodes
        while(otherNode) {
            last->next = new Node();
            last->next->data = otherNode->data;
            last->next->prev = last; // make the links work the other way. 
            last = last->next;
            otherNode = otherNode->next;
        }
        return *this;
    }

    //initializes an empty list
    // void init(); // why would we need this when we can just new an item?

    //returns true if the list is empty, false otherwise
    bool isEmpty() {
        return !first; // there has to be a first Node in order for the list to not be empty
    }
    
    //returns the number of items in the list
    int getLength() {
        return length;
    }
    
    //inserts a new item to the beginning of the list
    void insertFirst(const T &data) {
        Node *temp = new Node();
        temp->data = data;
        temp->next = first;
        first->prev = temp;
        first = temp;

    }
    
    //inserts a new item at the end of the list
    void insertLast(const T &data) {
        Node *temp = new Node();
        temp->data = data;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    
    //deletes the first item from the list
    void deleteFirst() {
        Node *temp = first;
        first = first->next;
        // temp->next = nullptr; // you shouldn't need to reassign the pointers in temp
        first->prev = nullptr;
        delete temp;
    }
    
    //deletes the last item in the list
    void deleteLast() {
        Node *temp = last;
        last = last->prev;
        last->next = nullptr;
        delete temp;
    }     
    
    //destroys the list and makes it empty
    void clear() {
        // iterate through all items and delete them
        if (isEmpty()) return;

        iterator = first;
        Node *temp = iterator->next;
        while (temp) {
            delete iterator;
            iterator = temp;
            temp = temp->next;
        }
        delete iterator; // without this the last item wouldn't get deleted

    }

    //iterator functions
    //sets the iterator to the beginning of the linked list
    void setIteratorFirst() {
        iterator = first;
    }
    
    //sets the iterator to the beginning of the linked list
    void setIteratorLast() {
        iterator = last;
    }
    
    //checks if the iterator has next
    bool hasNext() {
        return iterator->next;
    }

    //checks if the iterator has prev
    bool hasPrev() {
        return iterator->prev;
    }
    
    //sets the iterator to the next node
    void next() {
        iterator = iterator->next;
    }
    
    //sets the iterator to the previous node
    void prev() {
        iterator = iterator->prev;
    }
    
    //returns true if the iterator is null
    bool isIteratorNULL() {
        return !iterator;
    }
    
    //gets the data the iterator pointing at 
    T getData() {
        return iterator->data;
    }

    //friend functions
    //overloading operator<<
    template <class U>
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<U> &outputList) {
        
    }

    //overloading operator>>
    // create doubly linked list based of text file
    template <class U>
    friend istream& operator>>(istream& in, DoublyLinkedList<U> &inputList) {
        
    }

};

#endif 
