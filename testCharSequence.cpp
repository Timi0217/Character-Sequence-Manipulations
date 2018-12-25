/*  Oluwatimilehin Dayo-Kayode
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  testCharSequence.cpp
 *  Testing File for your sequence CharSequence class
 *
 *  Written by:
 *        UTLN:
 *          on:
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "CharSequence.h"

int main()
{
	char test[] = "fifteen";

	CharSequence sequence(test, 7);

	
	//cerr << "gets here" << endl;

	//check if isEmpty() function works properly
	if(sequence.isEmpty() == true){
		cout << "Tis Empty" << endl;
	}
	else{
		cout << "It is not empty" << endl;
	}

	int size = sequence.size();
	cout << "Current size is " << size << endl;

	//test clearing out the sequence	
	//CharSequence.clear();

	//exception was thrown if I cleared which is a-ok!
	char firstxter = sequence.first();
	cout << "The first character is " << firstxter << endl;

	char lastxter = sequence.last();
	cout << "The last character is " << lastxter << endl;

	char sniper = sequence.elementAt(4);
	cout << "The character at the requested index is " << sniper << endl;

	sequence.expand();

	sequence.print();

	sequence.pushAtBack('f');

	sequence.print();

	sequence.pushAtFront('f');

	sequence.print();

	sequence.insertAt('p', 5);

	sequence.print();

	sequence.insertInOrder('d');

	sequence.print();

	sequence.popFromFront();

	sequence.print();

	sequence.popFromBack();

	sequence.print();

	sequence.removeAt(5);

	sequence.print();

	sequence.replaceAt('x', 2);

	sequence.print();

	char* two = new char[3];
	two[0] = 'c';
	two[1] = 'a';
	two[2] = 't';

	CharSequence concat(two, 3);

	sequence.concatenate(&concat);

	//sequence.print();

	delete [] two;


return 0;
}
