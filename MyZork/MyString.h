#ifndef _MYSTRING_
#define _MYSTRING_

#include<string.h>
#include<stdio.h>
#include"vector.h"


typedef unsigned int uint;

class MyString
{
private:

	//PROPERTIES
	char *buffer = nullptr;
	uint max_size;

public:

	/*---CONSTRUCTORS-DESTRUCTOR---*/
	MyString();
	MyString(const char *string);
	MyString(const MyString &other);
	~MyString();


	/*---MEMBER FUNCTIONS---*/

	//returns the string
	const char *c_str() const;

	//returns the string size
	uint length()const;

	//returns the memory allocated
	const uint capacity() const;

	//checks if the string is empty
	bool empty()const;

	//compare 2 string classes
	bool operator==(const MyString &other) const;

	//compare string(class) - string
	bool operator==(const char *string) const;

	//equals a string class to another one
	void operator=(const MyString &other);

	//equals a string class to a string
	void operator=(const char *other);

	//concatenates two string classes
	void operator+=(const MyString &other);

	//string_class1 = string_class2 + string_class3
	MyString operator+(const MyString &other) const;

	//leaves a string class without characters
	void clear();

	//fits the allocated memory to the size of the string(+1)
	void shrink_to_fit();

	//split a string word by word
	Vector<MyString> SplitString(const char *symbol, char* command);

	//void set(char *command);

};


#endif //MYSTRING