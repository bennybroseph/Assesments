#include "String.h"

String::String(char p_string[256]) //called when the object of 'String' class is created
{
	strcpy(string, p_string); //sets the internal string to a value on creation of the object
}

int String::Length()
{
	return strlen(string);
}

char String::CharacterAt(int index)
{
	return string[index];
}

int String::EqualTo(char p_string[256])
{
	return strcmp(string,p_string);
}

void String::Append(char p_string[256])
{
	strncat(string, p_string, strlen(p_string));
}

char * String::CStr()
{
	return string;
}

void String::ToLower()
{
	int length = String::Length();

	for (short i = 0; i < length; i++)
	{
		if ((string[i] >= 65) && (string[i] <= 90))
			string[i] += 32;
	}
}

void String::ToUpper()
{
	int length = String::Length();

	for (short i = 0; i < length; i++)
	{
		if ((string[i] >= 97) && (string[i] <= 122))
			string[i] -= 32;
	}
}

int String::Find(char[256])
{
	return 0;
}

int String::Find(int, char[256])
{
	return 0;
}

void String::Replace(char[256], char[256])
{
}

std::string String::ReadFromConsole()
{
	return std::string();
}

void String::WriteToConsole()
{
}

String::~String()
{
}

