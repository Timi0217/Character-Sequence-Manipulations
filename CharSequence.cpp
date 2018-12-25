/*  Oluwatimilehin Dayo-Kayode
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharSequence.cpp
 *  Complete SequenceA Class Implementation
 *  Modified By (UTLN): odayok01
 *           On       : 01/30/2017
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "CharSequence.h"

/*CharSequence()
 *purpose:declares and initializes an empty sequence
 *with an initial capacity of zero.
 *parameters: none
 *return: nothing
 */ 
CharSequence::CharSequence(){
	sequenceptr = new char[1];
	currentSize = 0;
	capacity = 1;
}



/*CharSequence(char x)
 *purpose:declares and initializes a one element
 *sequence with an initial capacity of 1
 *parameters: a character variable
 *return: nothing
 */
CharSequence::CharSequence(char x){
	sequenceptr = new char[1];
	sequenceptr[0] = x;
	capacity = 1;
	currentSize = 1;
	
}

	

/*CharSequence(char array[], int x)
 *purpose: declares and initializes a sequence with a given set of characters
 *and capacity that is the length of the array
 *parameters: a character array and an integer length of the array
 *return: nothing
 */
CharSequence::CharSequence(char array[], int x){
	sequenceptr = new char[x];
	for(int i = 0; i < x; i++)
	{
		sequenceptr[i] = array[i];
	}
	currentSize = x;
	capacity = currentSize;
}

/*~CharSequence()
 *purpose: recycles heap-allocated data in the sequence in the constructor 
 *parameters: none
 *return: nothing
 */
CharSequence::~CharSequence(){
	delete [] sequenceptr;
}


/*isEmpty()
 *purpose: checks whether a sequence is empty or not
 *parameters: none
 *return: a boolean value
 */
bool CharSequence::isEmpty(){
	if (currentSize < 1){
		return true;
	}
	else{
		return false;
	}
}


/*clear()
 *purpose: converts a given sequence into an empty sequence
 *parameters: nothing
 */
void CharSequence::clear(){
	char* temp = new char[NULL];
	cout << "sequence cleared" << endl;
	currentSize = 0;
	delete [] sequenceptr;
	sequenceptr = temp;
}


//function to check size of the sequence
/*size()
 *purpose: returns an integer value that is the number of characters
 *in a given sequence
 *parameters: none
 *return: nothing
 */
int CharSequence::size(){
	return currentSize;
}


/*throwexception(string exceptiontype)
 *purpose: throw exceptions for given errors
 *parameters: a string that lets it know what exception to throw
 *return: nothing
 */
void CharSequence::throwexception(string exceptiontype){
	if (exceptiontype == "range"){
		throw range_error("index_out_of_range");
	}
	if (exceptiontype == "empty"){
		throw runtime_error("sequence_is_empty");
	}
}


/*first()
 *purpose: To return the first element in a given sequence
 *parameters: none
 *return: character that is the first in the given sequence
 */
char CharSequence::first(){
	if (isEmpty() == true)
	{
		throwexception("empty");
	}
		
		return sequenceptr[0];
}

/*last()
 *purpose: To return the last character in a sequence
 *parameters: none
 *return: character that is at the last position in the sequence
 */
char CharSequence::last(){
	if (isEmpty() == true)
	{
		throwexception("empty");
	}

		int x = size();
		return sequenceptr[x - 1];	
}


/*elementAt()
 *purpose: to return the character at a given index
 *parameters: an integer that is the index of the desired character
 *return: the character at the given index
 */
char CharSequence::elementAt(int x){
	if (currentSize < x){
		throwexception("range");

	}
		return sequenceptr[x];
}


/*expand()
 *purpose: to expand the capacity of a sequence
 *parameters: none
 *return: none
 */
void CharSequence::expand(){
	capacity = (capacity * 2) + 2;
	char* temp = new char[capacity];
	for (int i = 0; i < currentSize; i++){
		temp[i] = sequenceptr[i];
	}
	delete [] sequenceptr;
	sequenceptr = temp;
}


/*print()
 *purpose: to print out the characters in a given sequence
 *parameters: none
 *return: none
 */
void CharSequence::print(){
	cout << "[CharSequence of size " << currentSize <<" "
	<<"<<";

	for (int i = 0; i < currentSize; i++){
		cout << sequenceptr[i];	
	}
	
	cout << ">>]" << endl;

}


/*pushAtBack(char x)
 *purpose: insert a character after the last character in a sequence
 *parameters: a character
 *return: none
 */
void CharSequence::pushAtBack(char x){
	if (currentSize == capacity){
		expand();
	}
	sequenceptr[currentSize] = x;
	currentSize +=1;
}


/*pushAtFront(char x)
 *purpose: insert a character before the first character in a sequence
 *parameters: a character
 *return: none
 */
void CharSequence::pushAtFront(char x){
	if (currentSize == capacity){
		expand();
	}
	for (int i = currentSize; i > 0; i--){
		sequenceptr[i] = sequenceptr[i - 1];	
	}
	sequenceptr[0] = x;
	currentSize +=1;
}

/*insertAt(char x, int y)
 *purpose: inserts a given character at a given index
 *parameters: a character and an integer
 *return: none
 */
void CharSequence::insertAt(char x, int y){
	if (y > currentSize || y < 0){
		throwexception("range");
	}
	else{
		if (currentSize == capacity){
		expand();
		}
		for(int i = currentSize; i > y; i--){
			sequenceptr[i] = sequenceptr[i - 1];
		}
		sequenceptr[y] = x;
		currentSize += 1;
	}
}


/*insertInOrder(char x)
 *purpose: inserts a given character in the sequence in alphabetical order
 *parameters: a character
 *return: none
 */
void CharSequence::insertInOrder(char x){
	if (currentSize == capacity){
		expand();
		}
	for ( int i = 0; i < currentSize; i++){
		if (sequenceptr[i] >= x){
			insertAt(x, i);
			break;
		}

		if(sequenceptr[i] == '\0'){
			sequenceptr[i] = x;
			break;
		}
	}
}


/*popFromFront()
 *purpose: removes the first character in a sequence
 *parameters: none
 *return: none
 */
void CharSequence::popFromFront(){
	if (isEmpty() == true){
	throwexception("empty");
	}
	for(int i = 0; i < currentSize; i++){
		sequenceptr[i] = sequenceptr[i + 1];
	}
	currentSize -=1;
}


/*popFromBack()
 *purpose:removes the last character in a sequence
 *parameters: none
 *return: none
 */
void CharSequence::popFromBack(){
	if (isEmpty()){
		throwexception("empty");
	}
	currentSize -=1;
}


/*removeAt(int x)
 *purpose: removes the character at a given index
 *parameters: an integer value of the index
 *return: none
 */
void CharSequence::removeAt(int x){
	
	if (x > currentSize){
		throwexception("range");
	}	
	for (int i = x; i < currentSize - 1; i++){
	sequenceptr[i] = sequenceptr[i + 1];
	}
	currentSize -= 1;
}


/*replaceAt()
 *purpose: replaces the character at a given index with a given character
 *parameters: an integer value of an index and a character
 *return: none
 */
void CharSequence::replaceAt(char x, int y){
	if (y > currentSize || y == 0){
		throwexception("range");
	}
	
	sequenceptr[y] = x;
}


/*concatenate(CharSequence* ptr)
 *purpose: concatenate a given sequence to another one
 *parameters: a pointer to a sequence
 *return: none
 */
void CharSequence::concatenate(CharSequence* ptr){
		int secondsize = ptr -> size();
		int concatsize = currentSize + secondsize;
		while(concatsize >= capacity){
			expand();
		}
		for(int i = 0; i < secondsize; i++){
			sequenceptr[i + currentSize] = ptr -> elementAt(i);
		}
		currentSize = concatsize;
}


/*shrink()
 *purpose:reduces the capacity of a sequence to the bare minimum required 
 *to store its characters
 *parameters: none
 *return: none
 */
void CharSequence::shrink(){
	char* temp = new char [currentSize];
	for (int i = 0; i < currentSize; i++){
		temp[i] = sequenceptr[i];
	}	
}

	

