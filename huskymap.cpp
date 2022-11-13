#include "DoublyLinkedList.h"
//#include "BigInteger.h"
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

void dllTest()
{
	DoublyLinkedList<int> list;
	cout << "01. check if the double linked list is empty after creating an instance" << endl;
	cout << "02. insert number from 0 to 9 to the first of the list" << endl;
	grade(list.isEmpty() == true, 1);
	for (int i = 0; i < 10; i++)
		list.insertFirst(i);

	cout << "03. check the length of the list" << endl;
	grade(list.getLength() == 10, 2);

	cout << "04. move iterator to the first" << endl;
	list.setIteratorFirst();
	cout << "05. check if the iterator has next element" << endl;
	grade(list.hasNext() == true, 2);

	cout << "06. check the data of the iterator" << endl;
	grade(list.getData() == 9, 1);

	cout << "07. move the iterator to the next element" << endl;
	list.next();
	cout << "08. check the data of the iterator" << endl;
	grade(list.getData() == 8, 2);

	cout << "09. move the iterator to the previous element" << endl;
	list.prev();
	cout << "10. check the data of the iterator" << endl;
	grade(list.getData() == 9, 2);

	cout << "11. move iterator to the last" << endl;
	list.setIteratorLast();
	cout << "12. check if the iterator has next element" << endl;
	grade(list.hasNext() == false, 2);

	cout << "13. check the data of the iterator" << endl;
	grade(list.getData() == 0, 1);

	cout << "14. insert 10 to first" << endl;
	list.insertFirst(10);
	cout << "15. move iterator to the first" << endl;
	list.setIteratorFirst();
	cout << "16. check the data of the iterator" << endl;
	grade(list.getData() == 10, 1);

	cout << "17. insert 40 to the last" << endl;
	list.insertLast(40);
	cout << "18. move iterator to the last" << endl;
	list.setIteratorLast();
	cout << "19. check the data of the iterator" << endl;
	grade(list.getData() == 40, 1);

	cout << "20. delete first element" << endl;
	list.deleteFirst();
	cout << "21. move iterator to the first" << endl;
	list.setIteratorFirst();
	cout << "22. check the data of the iterator" << endl;
	grade(list.getData() == 9, 2);

	cout << "23. delete last element" << endl;
	list.deleteLast();
	cout << "24. move iterator to the last" << endl;
	list.setIteratorLast();
	cout << "25. check the data of the iterator" << endl;
	grade(list.getData() == 0, 2);

	cout << "26. clear the list" << endl;
	list.clear();
	cout << "27. check the length" << endl;
	grade(list.getLength() == 0, 1);

}

// void bigIntegerTest()
// {
// 	cout << "28. create two big integers 19 and 300" << endl;
// 	BigInteger int1("19"), int2("300");
// 	cout << "29. subtract 19 by 300" << endl;
// 	BigInteger actual2 = int1 - int2;
// 	BigInteger expected2("-281");
// 	cout << "30. check if 19 - 300 = -281" << endl;
// 	grade(actual2 == expected2, 3);
// 	cout << "31. check if the result -281 is negative" << endl;
// 	grade(actual2.isNegative() == true, 2);

// 	cout << "32. create a big integer 55555556666666687888999" << endl;
// 	BigInteger bigInt1("55555556666666687888999");
// 	cout << "33. check the length of the big integer" << endl;
// 	grade(bigInt1.getLength() == 23, 2);

// 	BigInteger bigInt2, bigInt3;
// 	ifstream file;
// 	cout << "34. read two big integers from text file" << endl;
// 	file.open("test.txt");
// 	file >> bigInt2 >> bigInt3;
// 	cout << "35. check the length of the first one" << endl;
// 	grade(bigInt2.getLength() == 23, 2);
// 	cout << "36. check the length of the second one" << endl;
// 	grade(bigInt3.getLength() == 24, 2);

// 	cout << "37. add them together" << endl;
// 	BigInteger actual1 = bigInt2 + bigInt3;
// 	BigInteger expected1("234657681223242153555775");
// 	cout << "38. check if the result is 234657681223242153555775" << endl;
// 	grade(actual1 == expected1, 2);

// 	cout << "39. subtract two big integers that have same value" << endl;
// 	BigInteger actual3 = bigInt2 - bigInt2;
// 	BigInteger expected3("0");
// 	cout << "40. check if the result is 0" << endl;
// 	grade(actual3 == expected3, 2);

// 	cout << "41. subtract 55555556666666687888999 by 179102124556575465666776" << endl;
// 	BigInteger actual4 = bigInt2 - bigInt3;
// 	BigInteger expected4("-123546567889908777777777");
// 	cout << "42. check if the result is -123546567889908777777777" << endl;
// 	grade(actual4 == expected4, 2);

// 	cout << "43. check if 55555556666666687888999 < 179102124556575465666776" << endl;
// 	grade(bigInt2 < bigInt3 == true, 1);

// 	cout << "44. check if 55555556666666687888999 >= 179102124556575465666776" << endl;
// 	grade(bigInt3 >= bigInt2 == true, 1);

// 	cout << "45. create two big integers 12345678997654321 and 12345678997654321" << endl;
// 	BigInteger bigInt4("12345678997654321"), bigInt5("12345678997654321");
// 	cout << "46. check if 12345678997654321 <= 12345678997654321" << endl;
// 	grade((bigInt4 <= bigInt5 == true), 1);

// }

int main()
{
	dllTest();          //test cases for doubly linked list implementation
	//bigIntegerTest();   //test cases for big integer implementation
	cout << "Test Score:" << score << endl;

	return 0;
}