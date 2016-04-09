#ifndef _MYSTRING_
#define _MYSTRING_

#include<string.h>
#include<stdio.h>

typedef unsigned int uint;

class MyString
{
private:

	//PROPERTIES
	char *buffer = nullptr;
	uint max_size;

public:

	//CONSTRUCTORS-DESTRUCTOR
	MyString()
	{
		max_size = 1;
		buffer = new char[max_size];
		strcpy_s(buffer, max_size, "");
		printf("EMPTY CONSTRUCTOR\n");
	}
	MyString(const char *string)
	{
		uint len = strlen(string);
		buffer = new char[len + 1];
		max_size = len + 1;
		strcpy_s(buffer, max_size, string);
		printf("CONSTRUCTOR with %s\n", buffer);
	}
	MyString(const MyString &other)
	{
		max_size = other.max_size;
		buffer = new char[max_size];
		strcpy_s(buffer, max_size, other.buffer);
		printf("COPY CONSTRUCTOR with %s\n", buffer);
	}
	~MyString()
	{
		printf("DESTRUCTOR\n");
		delete[] buffer;
	}

	//MEMBER FUNCTIONS

	//returns the string
	const char *c_str() const
	{
		return buffer;
	}

	//returns the string size
	uint length()const
	{
		return strlen(buffer);
	}

	//returns the memory allocated
	const uint capacity() const
	{
		return max_size;
	}

	//checks if the string is empty
	bool empty()const
	{
		return buffer[0] == 0;
	}

	//compare 2 string classes
	bool operator==(const MyString &other) const
	{
		return strcmp(buffer, other.buffer) == 0;
	}

	//compare string(class) - string
	bool operator==(const char *string) const
	{
		return strcmp(buffer, string) == 0;
	}

	//iguala una classe a una altra
	void operator=(const MyString &other)
	{
		if (max_size < other.length() + 1)
		{
			delete[] buffer;
			max_size = other.length() + 1;
			buffer = new char[max_size];
		}
		strcpy_s(buffer, max_size, other.buffer);
	}

	//concatena dues cadenes
	void operator+=(const MyString &other)
	{
		char *temp = nullptr;

		if (max_size < other.length() + length() + 1)
		{
			max_size = other.length() + length() + 1;
			temp = new char[max_size];
			strcpy_s(temp, max_size, buffer);
			delete[]buffer;
			strcat_s(temp, max_size, other.buffer);
			buffer = temp;
		}
		else
		{
			strcat_s(buffer, max_size, other.buffer);
		}
	}

	//cadena1 = cadena2 + cadena3
	MyString operator+(const MyString &other) const
	{
		MyString newstring;
		newstring.max_size = length() + other.length() + 1;
		newstring.buffer = new char[newstring.max_size];
		strcpy_s(newstring.buffer, newstring.max_size, buffer);
		strcat_s(newstring.buffer, newstring.max_size, other.buffer);
		return newstring;
	}

	//deixa la cadena sense caràcters
	void clear()
	{
		strcpy_s(buffer, max_size, "");
	}

	//la memòria alocatada s'iguala al nombre de caràcters de la cadena (+1)
	void shrink_to_fit()
	{
		if (max_size != length() + 1)
		{
			char *temp = nullptr;
			max_size = length() + 1;
			temp = new char[max_size];
			strcpy_s(temp, max_size, buffer);
			delete[] buffer;
			buffer = temp;
		}
	}
};


#endif //MYSTRING