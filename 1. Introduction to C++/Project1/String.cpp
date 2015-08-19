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

void String::Replace(char p_string[256], char replace[256])
{
	char* found = strstr(string, p_string);

	if (found != NULL)
	{
		char hold[256];
		int i;

		for (i = (String::Length() - strlen(found)); i < String::Length() - strlen(replace); i++)
		{
			hold[i] = string[i + strlen(replace)];
		}
		hold[i] = 0;

		strcat_s(replace, sizeof(replace), hold);
		strcpy_s(string, hold);
	}
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

