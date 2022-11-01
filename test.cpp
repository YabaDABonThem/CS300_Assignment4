#include "DoublyLinkedList.h"
#include "BigInteger.h"
#include <iostream>
#include <fstream>

using namespace std;

int score = 0;

void grade(bool condition, int points)
{
    if (condition)
    {
        cout << "Pass" << endl;
        score += points;
    }
    else
    {
        cout << "Fail" << endl;
    }
}

void dllTest(){
    DoublyLinkedList<int> list;
    grade(list.isEmpty() == true, 1);
    for(int i=0; i<10; i++){
        list.insertFirst(i);
    }
    grade(list.getLength() == 10, 2);

    list.setIteratorFirst();
    grade(list.hasNext() == false, 2);
    
    grade(list.getData() == 9, 1);

    list.next();
    grade(list.getData() == 8, 2);

    list.prev();
    grade(list.getData() == 9, 2);

    list.setIteratorLast();
    grade(list.hasNext() == true, 2);

    grade(list.getData() == 0, 1);

    list.insertFirst(10);
    list.setIteratorFirst();
    grade(list.getData() == 10, 1);

    list.insertLast(40);
    list.setIteratorLast();
    grade(list.getData() == 40, 1);

    list.deleteFirst();
    list.setIteratorFirst();
    grade(list.getData() == 9, 2);

    list.deleteLast();
    list.setIteratorLast();
    grade(list.getData() == 0, 2);

    list.clear();
    grade(list.getLength() == 0, 1);


}

void bigIntegerTest(){
    BigInteger int1("19"), int2("300");
    BigInteger actual2 = int1 - int2;
    BigInteger expected2("-281");
    grade(actual2 == expected2, 3);
    grade(actual2.isNegative() == true, 2);

    BigInteger bigInt1("55555556666666687888999");
    grade(bigInt1.getLength() == 23, 2);

    BigInteger bigInt2, bigInt3;
    ifstream file;
    file.open("test.txt");
    file>>bigInt2>>bigInt3;
    grade(bigInt2.getLength() == 23, 2);
    grade(bigInt3.getLength()==24, 2);

    BigInteger actual1 = bigInt2 + bigInt3;
    BigInteger expected1("234657681223242153555775");
    grade(actual1 == expected1, 2);

    BigInteger actual3 = bigInt2 - bigInt2;
    BigInteger expected3("0");
    grade(actual3 == expected3, 2);

    BigInteger actual4 = bigInt2 - bigInt3;
    BigInteger expected4("-123546567889908777777777");
    grade(actual4 == expected4, 2);

    grade(bigInt2<bigInt3 == true, 1);

    grade(bigInt3>=bigInt2 == true, 1);

    BigInteger bigInt4("12345678997654321"),bigInt5("12345678997654321");
    grade((bigInt4<=bigInt5 == true), 1);


}
int main(){
    dllTest();          //test cases for doubly linked list implementation

    bigIntegerTest();   //test cases for big integer implementation

    cout<<"Test Score:"<<score<<endl;

    return 0;
}