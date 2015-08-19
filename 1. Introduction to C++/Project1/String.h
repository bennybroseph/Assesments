#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>
#include <cstring>

class String
{
private:
	char string[256], input[256]; //the string that gets manipulated, input from 'ReadFromConsole'

public:
	int Length();
	char CharacterAt(int);
	int EqualTo(char[256]);
	void Append(char[256]);
	char* CStr();
	void ToLower();
	void ToUpper();
	int Find(char[256]);
	int Find(int, char[256]);
	int Replace(char[256], char[256]);
	char* ReadFromConsole();
	void WriteToConsole();

	String(char[256]); //constructor
	~String(); //deconstructor
};

#endif
