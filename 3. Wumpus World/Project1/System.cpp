#include "System.h"

const unsigned int LAST_LINE_OF_CONSOLE = 24;

namespace System
{
	HANDLE hStdout;
	CONSOLE_CURSOR_INFO hCursorInfo;
	CONSOLE_SCREEN_BUFFER_INFO hBufferInfo;

	void Print(const int ac_iPosX, const int ac_iPosY, const char *ac_pcFormat, ...) // Broken function that attempted to set the console print line and then pass the remaining arguments to 'printf_s'
	{
		va_list arguments;
		va_start(arguments, ac_pcFormat);

		SetCursor(ac_iPosX, ac_iPosY, hCursorInfo.bVisible);
		printf_s(ac_pcFormat, arguments);
	}
	void Print(std::string ac_sTextToPrint, const int ac_iLength, const int ac_iPosX, const int ac_iPosY)
	{
		SetCursor(ac_iPosX, ac_iPosY, hCursorInfo.bVisible);

		if (ac_sTextToPrint.length() > ac_iLength)
		{
			int i = 0; // Will keep track of where in the 'substr' we've gone thus far
			std::vector<std::string> vsTextToPrint;

			bool bLoop = true;
			while (bLoop)
			{
				if (i + ac_iLength >= ac_sTextToPrint.length())
					bLoop = false;

				std::string sTemp = ac_sTextToPrint.substr(i, ac_iLength); // Holds the 'substr' of 'ac_sTextToPrint' that we're cutting into pieces.

				vsTextToPrint.push_back(ac_sTextToPrint.substr(i, i + sTemp.rfind(" "))); i += sTemp.rfind(" ") + 1;
			}

			for (i = 0; i < vsTextToPrint.size(); ++i)
			{
				SetCursor(ac_iPosX, ac_iPosY + i, hCursorInfo.bVisible);
				std::cout << vsTextToPrint[i];
			}
		}
		else
			std::cout << ac_sTextToPrint;
	}

	void ToLower(char * a_pcUppercaseWord, const int ac_iSize)
	{
		for (int i = 0; i < ac_iSize; ++i)
		{
			if (a_pcUppercaseWord[i] <= 90 && a_pcUppercaseWord[i] >= 65)
				a_pcUppercaseWord[i] += 32;
		}
	}

	void SetCursor(short a_iPosX, short a_iPosY, bool a_bShowCursor)
	{
		hCursorInfo.bVisible = a_bShowCursor;

		SetConsoleCursorPosition(hStdout, { a_iPosX, a_iPosY });
		SetConsoleCursorInfo(hStdout, &hCursorInfo);
	}
	void ShowCursor()
	{
		hCursorInfo.bVisible = true;

		SetConsoleCursorInfo(hStdout, &hCursorInfo);
	}
	void HideCursor()
	{
		hCursorInfo.bVisible = false;

		SetConsoleCursorInfo(hStdout, &hCursorInfo);
	}

	void Pause()
	{
		SetCursor(0, LAST_LINE_OF_CONSOLE, 0);
		printf_s("<Press Enter To Continue>");

		Sleep(300);
		while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) {}
	}

	int Round(float a_fNum)
	{
		return floor(a_fNum + 0.5f);
	}

	int Random(int a_fMin, int a_fMax)
	{
		return a_fMin + rand() % ((a_fMax + 1) - a_fMin);
	}
	float Random(float a_fMin, float a_fMax)
	{
		return a_fMin + (float)rand() / ((float)RAND_MAX / (a_fMax - a_fMin));
	}

	void Init(int a_ciColor)
	{
		srand(time(NULL));

		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleTextAttribute(hStdout, a_ciColor);

		hCursorInfo.dwSize = 10;
		hCursorInfo.bVisible = 1;

		SetConsoleCursorInfo(hStdout, &hCursorInfo);
	}
	void Quit()
	{

	}
}