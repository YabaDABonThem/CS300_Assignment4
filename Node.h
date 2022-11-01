#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;
};

#endif