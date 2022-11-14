#include <string>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"


class BigInteger : public DoublyLinkedList<int> {
    
protected:
    bool isNegative = false;

public:
    BigInteger() {

    }

    ~BigInteger() {

    }

    // how should adding negative numbers work? should you do it here, or in the substraction operator?
    typedef Node<int> IntNode;
    BigInteger BigInteger::operator+ (const BigInteger& rightNum) const {
        IntNode *leftNumIter = this->last; 
        IntNode *rightNumIter = rightNum.last;
        BigInteger sum;
        int carryOver = 0; // represents whether or not there was a carry over digit (being 1)
        int columnSum = 0; // represents the sum of all items in the column
        while (true) { // we do different things depending on whether leftNumIter or rightNumIter is null
            if (leftNumIter && rightNumIter) {
                columnSum = leftNumIter->data + rightNumIter->data + carryOver;
                carryOver = 0; // set the carryOver to 0 after you use it
                sum.insertFirst(columnSum % 10); // insert the number in the one's place
                if (columnSum >= 10) {
                    carryOver = 1;
                }
            } else if (leftNumIter) { // If left number is longer than the right
                columnSum = leftNumIter->data + carryOver;
                carryOver = 0; // set the carryOver to 0 after you use it
                sum.insertFirst(columnSum % 10); // insert the number in the one's place
                if (columnSum >= 10) {
                    carryOver = 1; // need this check bc 9 + carry over 1 is still possible
                }
            } else if (rightNumIter) { // If right number is longer than the left
                columnSum = rightNumIter->data + carryOver;
                carryOver = 0; // set the carryOver to 0 after you use it
                sum.insertFirst(columnSum % 10); // insert the number in the one's place
                if (columnSum >= 10) {
                    carryOver = 1;
                }
            } else {
                return sum;
            }
        }
    }

    // How to implement subtraction? (How do negative numbers work?)
    // the tests expect you to support negative numbers
    typedef Node<int> IntNode;
    BigInteger BigInteger::operator- (const BigInteger& rightNum) const {
        
    }
    
};