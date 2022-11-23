#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <string>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

class BigInteger : public DoublyLinkedList<int> {
    
protected:
    bool isPositive = true; // a field that determines the sign of the BigInteger

public:
    // reduces the amount of typing we have to do
    typedef Node<int> IntNode;

    // default constructor: creates an empty BigInteger. 
    BigInteger() = default;

    // create a BigInteger baseed off the number passed in
    BigInteger(const string& numString);

    ~BigInteger();

    // empty the DLL and reset the sign
    void clear() override;

    // we're forced to include this method for some reason
    bool isNegative();

    BigInteger& operator= (const BigInteger& rightNum);

    BigInteger operator+ (const BigInteger& rightNum) const;

    // How to implement subtraction? (How do negative numbers work?)
    // the tests expect you to support negative numbers
    BigInteger operator- (const BigInteger& rightNum) const;

    void trimLeadingZeroes();

    // unary operator, just negates the sign
    BigInteger operator- () const;

    // we first implement the > and ==, everything else can be written in terms of those two
    bool operator> (const BigInteger& rightNum) const;
    
    bool operator== (const BigInteger& rightNum) const;

    bool operator>= (const BigInteger& rightNum) const;

    bool operator< (const BigInteger& rightNum) const;

    bool operator<= (const BigInteger& rightNum) const;

    // friend functions
    friend ostream& operator<<(ostream& out, const BigInteger &inputNum);

    friend istream& operator>>(istream& in, BigInteger &result);
};
#endif