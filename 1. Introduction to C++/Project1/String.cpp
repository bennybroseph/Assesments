#include "String.h"

String::String(char p_string[256]) //called when the object of 'String' class is created
{
	strcpy_s(string, p_string); //sets the internal string to a value on creation of the object
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
	strncat_s(string, p_string, strlen(p_string));
}

char * String::CStr()
{
	return string;
}

void String::ToLower()
{
	for (short i = 0; i < String::Length(); i++)
	{
		if ((string[i] >= 65) && (string[i] <= 90))
			string[i] += 32;
	}
}

void String::ToUpper()
{
	for (short i = 0; i < String::Length(); i++)
	{
		if ((string[i] >= 97) && (string[i] <= 122))
			string[i] -= 32;
	}
}

int String::Find(char p_string[256])
{
	char* found = strstr(string, p_string);

	if (found != NULL)
		return String::Length() - strlen(found);
	return -1;
}

int String::Find(int index, char p_string[256])
{
	char hold[256];
	int i;

	for (i = 0; i < String::Length() - index; i++)
	{
		hold[i] = string[i+index];
	}
	hold[i] = 0;

	char* found = strstr(hold, p_string);

	if (found != NULL)
		return String::Length() - strlen(found);
	return -1;
}

int String::Replace(char p_string[256], char p_replace[256]) //accepts 2 arguments: The string to look for in 'String::string', The string to replace p_string in 'String::string'
{
	char* found = strstr(string, p_string); //look for 'p_string' in 'String::string'
	char replace[256]; //strcat_s is unable to handle char* as the first parameter for some reason, so we'll just create this to hold 'p_replace' for us in a type char [256]
	strcpy_s(replace, p_replace); //now 'replace' is exactly the same as 'p_replace'

	if (found != NULL) //as long as the 'p_string' was found in 'String::string'
	{
		char hold[256]; //will hold onto the rest of 'String::string' after the 'p_string' was found
		int i; //loop var

		//'i' begins at where 'found' begins inside of 'String::string'. Runs until it reaches the end of 'String::string' after considering the length of 'p_string'. 'i' += 1
		for (i = (String::Length() - strlen(found)); i < String::Length() - strlen(p_string); i++) 
		{
			hold[i] = string[i + strlen(p_string)]; //begin after 'p_string' and put the rest of 'String::string' into hold
		}
		hold[i] = 0; //add a terminating character to the end of 'hold'

		strcat_s(replace, hold); //add 'hold' to the end of 'replace'
		strcpy_s(string, replace); //finish the replace by setting 'String::string' to 'replace'

		return 0;
	}
	return -1;
}

char* String::ReadFromConsole()
{
	std::cin >> input;

	return input;
}

void String::WriteToConsole()
{
	std::cout << string;
}

String::~String()
{
}

