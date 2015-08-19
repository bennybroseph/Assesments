#include "String.h"

int main()
{
	String string("Benjamin");
	std::cout << string.CStr();

	std::cout << std::endl << std::endl;

	std::cout << "string.Length() = " << string.Length() << std::endl;
	std::cout << "string.CharacterAt(2) = " << string.CharacterAt(2) << std::endl;
	std::cout << "string.EqualTo(\"Benjamin\") = " << string.EqualTo("Benjamin") << std::endl;
	string.ToUpper();
	std::cout << "string.ToUpper() = " << string.CStr() << std::endl;
	string.ToLower();
	std::cout << "string.ToUpper() = " << string.CStr() << std::endl;
	std::cout << "string.Find(\"jam\") = " << string.Find("jam") << std::endl;
	std::cout << "string.Find(3,\"am\") = " << string.Find(3,"am") << std::endl;
	string.Replace("ben", "I'm");
	std::cout << "string.Replace(\"ben\",\"I'm \") = " << string.CStr();

	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}
