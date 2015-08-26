#include <iostream>

void Function1();
void ASCII(char*);
void Smiley(char*);

void Function2();

void New(char*);
void End();

int main()
{
	New("1a");
	Function1();
	End();

	New("2");
	Function2();
	End();
}

void Function1()
{
	char input[256];

	std::cout << "Enter a string of text: ";
	std::cin.getline(input, 256);
	ASCII(input);
	End();

	New("1b");
	Smiley(input);
}
void ASCII(char* p_array)
{
	int ASCII[256];

	int i;
	std::cout << std::endl << "'" << p_array << "' in ASCII is represented as: " << std::endl;
	for (i = 0; p_array[i - 1] != 0; i++)
	{
		ASCII[i] = (int)p_array[i];
		if (p_array[i] != 0)
			std::cout << ASCII[i] << ", ";
		else
			std::cout << ASCII[i] << ";";
	}
}
void Smiley(char* p_array)
{
	int i;

	for (i = 0; p_array[i - 1] != 0; i++)
	{
		if (((i > 0) && (p_array[i - 1] != 1)) && ((p_array[i] == 32) || (p_array[i] == 0)))
			p_array[i - 1] = 1;
		if(i > 0)
			std::cout << p_array[i - 1];
	}
}

void Function2()
{
	char name[3][256];

	std::cout << "Enter your first, middle and last name: ";
	std::cin >> name[0]; std::cin >> name[1]; std::cin >> name[2];

	std::cout << std::endl << "I'll convert your first name now..." << std::endl;
	ASCII(name[0]);

	std::cout << std::endl << std::endl << "Now the middle name..." << std::endl;
	ASCII(name[1]);

	std::cout << std::endl << std::endl << "Finally, your last name..." << std::endl;
	ASCII(name[2]);
}

void New(char* i)
{
	system("cls");
	std::cout << "Exercise " << i << std::endl;

	if (strlen(i) < 2)
		std::cout << "----------";
	else
		std::cout << "-----------";

	std::cout << std::endl << std::endl;
}
void End()
{
	std::cout << std::endl << std::endl;
	system("pause");
}