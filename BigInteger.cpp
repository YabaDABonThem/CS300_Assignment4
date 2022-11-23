#include "BigInteger.h"
#include <string>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

// create a BigInteger baseed off the number passed in
BigInteger::BigInteger(const string& numString) {
    std::string::const_iterator it = numString.begin();
    if (*it == '-') {
        isPositive = false;
        ++it;
    }
    // this supports trimming zeroes in front
    while (*it) {
        insertLast(static_cast<int>(*it-'0'));
        ++it;
    }

    trimLeadingZeroes();
}

BigInteger::~BigInteger() {
    clear();
}

// empty the DLL and reset the sign
void BigInteger::clear() { 
    isPositive = true;
    DoublyLinkedList<int>::clear();
}

// we're forced to include this method for some reason
bool BigInteger::isNegative() {
    return !isPositive;
}

BigInteger& BigInteger::operator= (const BigInteger& rightNum) {
    this->isPositive = rightNum.isPositive;
    this->length = rightNum.length;
    DoublyLinkedList<int>::operator=(rightNum);
    return *this; // we need to convert from doublylinkedlist to biginteger
}

BigInteger BigInteger::operator+ (const BigInteger& rightNum) const {
    // If the signs are different, the answer becomes a rearranged subtraction problem
    if (this->isPositive != rightNum.isPositive) {
        // determine which number is positive
        if (this->isPositive) { // a-b
            return *this - (-rightNum);
        } else { // b-a
            return rightNum - (-*this);
        }

    } else if (!this->isPositive) {
        // you're going to return -(a+b)
        return -((-*this) + (-rightNum));
    }
    // Now we can gurantee that all numbers are positive
    IntNode *leftNumIter = this->last; 
    IntNode *rightNumIter = rightNum.last;
    BigInteger sum;
    int carryOver = 0; // represents whether or not there was a carry over digit (being 1)
    int columnSum = 0; // represents the sum of all items in the column
    while (leftNumIter || rightNumIter) { // while there are numbers left, keep adding
        columnSum = carryOver;
        carryOver = 0; // set the carryOver to 0 after you use it 
        if (rightNumIter) {
            columnSum += rightNumIter->data;
            rightNumIter = rightNumIter->prev;
        }
        if (leftNumIter) {
            columnSum += leftNumIter->data;
            leftNumIter = leftNumIter->prev;
        } 
        
        sum.insertFirst(columnSum % 10); // insert the number in the one's place
        if (columnSum >= 10) {
            carryOver = 1;
        }
        
    }
    return sum;
}

// How to implement subtraction? (How do negative numbers work?)
// the tests expect you to support negative numbers
BigInteger BigInteger::operator- (const BigInteger& rightNum) const {
    // if the signs are different, it basically becomes a rearranged addition equation
    BigInteger difference;
    if (this->isPositive != rightNum.isPositive) {
        // determine which number is positive
        if (this->isPositive) {
            return *this + (-rightNum);
        } else {
            return -(rightNum + (-*this));
        }

    } else if (!this->isPositive) {
        // you're going to return -(a-b)
        return -((-*this) - (-rightNum));
    }
    // now it's guranteed that they have the same sign, need to check which is absolutely bigger
    if (*this < rightNum) {
        return -(rightNum - *this);
    }

    // You must first decide which number is larger and determine which number subtracted by the other based off that
    BigInteger leftNumCopy = *this; // We need to make a copy of the left number because we modify the values of some nodes
    IntNode *leftNumIter = leftNumCopy.last; 
    IntNode *rightNumIter = rightNum.last;

    bool carry = false; // represents whether or not you should carry a number from previous digit
    int columnDiff = 0; 
    while (leftNumIter) { // length of left num is always greater than or equal to the length of the right num
        if (carry) { // this means if the LAST number carried
            leftNumIter->data--;
            carry = false;
        }
        // if right number ran out of numbers
        if (!rightNumIter) {
            difference.insertFirst(leftNumIter->data);
            leftNumIter = leftNumIter->prev;
            continue;
        } 
        if (leftNumIter->data - rightNumIter->data < 0) { // check if you need to carry over a number from the left
            carry = true;
            leftNumIter->data += 10;
        }
        difference.insertFirst(leftNumIter->data - rightNumIter->data);
        leftNumIter = leftNumIter->prev;
        rightNumIter = rightNumIter->prev;
    }
    
    // We need to trim the zeroes at the beginning or else the length of the result will be inaccurate
    difference.trimLeadingZeroes();
    return difference;
}

void BigInteger::trimLeadingZeroes() {
    while (length > 1 && first->data == 0) {
        deleteFirst();
    }
}

// unary operator, just negates the sign
BigInteger BigInteger::operator- () const {
    BigInteger negation = *this;
    negation.isPositive = !this->isPositive;
    return negation;
}

// we first implement the > and ==, everything else can be written in terms of those two
bool BigInteger::operator> (const BigInteger& rightNum) const {
    // is there a difference between a positive and a negative zero?
    // scenario: they have different signs
    if (this->isPositive != rightNum.isPositive) {
        return this->isPositive;
    }
    // scenario: they have he same signs
    bool isLeftAbsBigger = this->isPositive; // we compare the absolute value, if they have the same sign,
    if (this->length > rightNum.length) {    // then the absolute value is larger
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
    
bool BigInteger::operator== (const BigInteger& rightNum) const {
    if (this->isPositive != rightNum.isPositive) {
        return false; // if the signs aren't equal, then they aren't equal
    }

    // signs are the same, so now you have to check if the absolute values are the same
    // first we check the lengths
    if (this->length != rightNum.length) {
        return false;
    }
    // lengths are the same, now we check the values
    IntNode *leftNumIter = this->first; 
    IntNode *rightNumIter = rightNum.first;
    while (leftNumIter) {
        if (leftNumIter->data != rightNumIter->data) {
            return false;
        }
        leftNumIter = leftNumIter->next;
        rightNumIter = rightNumIter->next;
    }
    return true;
}

bool BigInteger::operator>= (const BigInteger& rightNum) const {
    return (*this == rightNum) || (*this > rightNum);
}

bool BigInteger::operator< (const BigInteger& rightNum) const {
    return !(*this >= rightNum);
}

bool BigInteger::operator<= (const BigInteger& rightNum) const {
    return (*this < rightNum) || (*this == rightNum);
}

// input/output functions
ostream& operator<<(ostream& out, const BigInteger &inputNum) {
    // we don't need to check if the output number is empty bc the parent will
    // all we have to do is print out the negative if there is one.
    if (!inputNum.isPositive) {
        out << '-';
    }
    // Note: we don't have to call the << of the super class because they don't wan't the arrows
    // we just need to print out the number itself
    BigInteger::IntNode *temp = inputNum.first;
    while (temp) {
        out << temp->data;
        temp = temp->next;
    }
    return out;
}

istream& operator>>(istream& in, BigInteger &result) {
    // we check the first char to determine the sign of the number
    result.clear();
    if (in.peek() == '-') {
        result.isPositive = false;
        char c;
        in >> c;
    }

    // go through the stream and add in a character at a time
    string line;
    std::getline(in, line); 
    for (auto c : line) {
        int a = static_cast<int>(c-'0');
        result.insertLast(static_cast<int>(c-'0'));
    }
    result.trimLeadingZeroes();
    return in;

    
}
