/*  Oluwatimilehin Dayo-Kayode
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharSequence.h
 *  Complete SequenceA Class Header and Declaration
 *  Modified By (UTLN): odayok01
 *           On       :1/30/2017
 *
 */

#ifndef CHARSEQUENCE_H
#define CHARSEQUENCE_H
#include <iostream>
using namespace std;
class CharSequence
{

public:

	//should i use thye same name for all constructors?
	CharSequence();		/*constructor1*/

	CharSequence(char x);	/*constructor 2*/

	CharSequence(char array[], int length); /*constructor 3*/

	~CharSequence(); /*destructor*/
	
	bool isEmpty();

	void clear();

	int size();

	char first();

	char last();

	char elementAt(int x);

	void print();

	void pushAtBack(char x);

	void pushAtFront(char x);

	void insertAt(char x, int y);

	void insertInOrder(char x);

	void popFromFront();

	void popFromBack();

	void expand();

	void removeAt(int x);

	void replaceAt(char x, int y);

	void concatenate(CharSequence* ptr);

	void shrink();

	


private:

int count(char* ptr);

char* sequenceptr;

int currentSize;

int capacity;

void throwexception(string exceptiontype);

};

#endif

