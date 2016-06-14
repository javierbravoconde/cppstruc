//============================================================================
// Name        : cppstruc.cpp
// Author      : Javier
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "list/List.h"

using namespace std;

int main() {

	structs::List<int> aList;

	aList.push_back(1);
	aList.push_back(3);


	aList.push_front(2);
	aList.push_front(4);


	structs::List<int>::iterator begin = aList.begin();
	structs::List<int>::iterator end = aList.end();
	while (begin != end) {

		std::cout << *begin << std::endl;
		++begin;
	}
	return 0;
}
