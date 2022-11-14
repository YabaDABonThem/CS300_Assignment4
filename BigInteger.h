#include <string>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"


class BigInteger : public DoublyLinkedList<int> {
    
protected:
    bool isPositive = true;

public:
    BigInteger(String num) {
        if (charAt(0) == '-') {
            this.isPositive = false;
        }
    }

    ~BigInteger() {

    }



    // how should adding negative numbers work? should you do it here, or in the substraction operator?
    typedef Node<int> IntNode;
    BigInteger BigInteger::operator+ (const BigInteger& rightNum) const {
        // If the signs are different, the answer becomes a rearranged subtraction problem
        if (this->isPositive != rightNum.isPositive) {
            // determine which number is positive
            if (this->isPositive) {
                return *this - (-rightNum);
            } else {
                return rightNum - (-*this);
            }

        } else if (!this->isPositive) {
            // you're going to return -(a+b)
            // how do you do add a negative of a number without changing the number's value?
            return -((-*this) + (-rightNum));
        }
        // Now we can gurantee that all numbers are positive
        IntNode *leftNumIter = this->last; 
        IntNode *rightNumIter = rightNum.last;
        BigInteger sum;
        int carryOver = 0; // represents whether or not there was a carry over digit (being 1)
        int columnSum = 0; // represents the sum of all items in the column
        while (leftNumIter || rightNumIter) { // while there are numbers left, keep adding
            if (!rightNumIter) {
                columnSum = leftNumIter->data + carryOver;
            } else if (!leftNumIter) {
                columnSum = rightNumIter->data + carryOver;
            } else {
                columnSum = leftNumIter->data + rightNumIter->data + carryOver;
            }
            carryOver = 0; // set the carryOver to 0 after you use it
            sum.insertFirst(columnSum % 10); // insert the number in the one's place
            if (columnSum >= 10) {
                carryOver = 1;
            }
            leftNumIter = leftNumIter->prev;
            rightNumIter = rightNumIter->prev;
        }
        return sum;
    }

    // How to implement subtraction? (How do negative numbers work?)
    // the tests expect you to support negative numbers
    typedef Node<int> IntNode;
    BigInteger BigInteger::operator- (const BigInteger& rightNum) const {
        // if the signs are different, it basically becomes a rearranged addition equation
        if (this->isPositive != rightNum.isPositive) {
            // determine which number is positive
            if (!this->isPositive) {
                isPositive = !isPositive;
            }
            return this + rightNum; // if second is positive, return the negative of left + right
        }

        // You must first decide which number is larger and determine which number subtracted by the other based off that
        IntNode *leftNumIter = this->last; 
        IntNode *rightNumIter = rightNum.last;
        BigInteger difference;
        int borrowedDigit = 0; // represents whether or not there was a borrowed 1 from the previous digit (being 10)
        int columnDiff = 0; 
        while (leftNumIter || rightNumIter) {
            // first scenario: being to subtract normally
            if (leftNumIter->data >= rightNumIter->data) {
                columnDiff = leftNumIter->data + borrowedDigit - rightNumIter->data;
                borrowedDigit = 0;
                // Note: there is no need to check if you need to change the borrowed digit or not
                difference.insertFirst(columnDiff);
            }

            // second scenario: need to borrow a digit from the next avilable number
        }
        return difference;
    }

    BigInteger BigInteger::operator- () const {}
        BigInteger negation = *this;
        negation.isPositive = !this->isPositive;
        return negation;
    }

    bool BigInteger::operator> (const BigInteger& rightNum) const {
        // is there a difference between a positive and a negative zero?
        // scenario: they have different signs
        if (this->isPositive != rightNum.isPositive) {
            if (this->isPositive) {
                return true; 
            }
            return false;
        }
        // scenario: they have he same signs
        bool isLeftAbsBigger = this->isPositive; // we compare the absolute value, if they have the same sign then
        if (this->length > rightNum.length) { // the absolute value is larger
            return isLeftAbsBigger;
        } else if (rightNum.length > this->length) {
            return !isLeftAbsBigger;
        } else { // numbers are the same length, we need to iterate through both linked lists
            IntNode *leftNumIter = this->first; 
            IntNode *rightNumIter = rightNum.first;
            while (leftNumIter) {
                if (leftNumIter->data > rightNumIter->data) {
                    return isLeftAbsBigger; // left number is absolutely bigger
                } else if (leftNumIter->data < rightNumIter->data) {
                    return !isLeftAbsBigger; // right number is absolutely bigger
                }
                leftNumIter = leftNumIter->next;
                rightNumIter = rightNumIter->next;
            }
            return false; // they are equal to each other
        }
    } 
    
    bool BigInteger::operator< (const BigInteger& rightNum) const {
        
    }

};