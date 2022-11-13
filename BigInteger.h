#include <string>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"


class BigInteger : public DoublyLinkedList<int> {
    typedef Node<int> IntNode;
    BigInteger BigInteger::operator+ (const BigInteger& rightNum) const {
        IntNode *leftNumIter = this->last; 
        IntNode *rightNumIter = rightNum.last;
        BigInteger sum;
        while (true) { // we do different things depending on whether leftNumIter or rightNumIter is null
            if (leftNumIter && rightNumIter) {
                
            } else if (leftNumIter) {

            } else if (rightNumIter) {
                
            } else {
                return sum;
            }
        }
    }
    
};