#include "EventHandle.h"

const unsigned int KEY_REPEAT_PRESS_DELAY = 60;
const unsigned int KEY_PRESS_DELAY = 200;

const unsigned int MAX_KEYS = 8;

void EventHandle::ParseInput()
{
	if (m_vKeys.size() < m_vPrevKeys.size())
	{
		for (int i = m_vKeys.size(); i < m_vPrevKeys.size(); ++i)
			OnKeyRelease(m_vPrevKeys[i]);
	}
	for (int i = 0; i < m_vKeys.size(); ++i)
	{
		if ((i >= m_vPrevKeys.size()) || (m_vKeys[i] != m_vPrevKeys[i]))
		{
			if (i >= m_vPrevKeys.size())
			{
				m_vSincePressed.push_back(clock() + KEY_PRESS_DELAY);
				m_vSinceRepeat.push_back(clock() + KEY_PRESS_DELAY + KEY_REPEAT_PRESS_DELAY);

			}
			OnKeyPress(m_vKeys[i]);
		}
		else if ((m_vKeys[i] == m_vPrevKeys[i]) && (clock() > m_vSinceRepeat[i]) && (clock() > m_vSincePressed[i]))
		{
			m_vSinceRepeat[i] = clock() + KEY_REPEAT_PRESS_DELAY;
			OnKeyRepeat(m_vKeys[i]);
		}
	}
	m_vPrevKeys = m_vKeys;
	m_vKeys.clear();
}
void EventHandle::OrderInput()
{
	for (int i = 0; i < m_vKeys.size(); ++i)
	{
		for (int j = 0; j < m_vPrevKeys.size(); ++j)
		{
			if ((i < m_vPrevKeys.size()) && (m_vKeys[i] == m_vPrevKeys[j]))
			{
				iter_swap(m_vPrevKeys.begin() + i, m_vPrevKeys.begin() + j);
				iter_swap(m_vSinceRepeat.begin() + i, m_vSinceRepeat.begin() + j);
				iter_swap(m_vSincePressed.begin() + i, m_vSincePressed.begin() + j);
			}
			else if ((j < m_vKeys.size()) && (m_vKeys[i] == m_vPrevKeys[j]))
				iter_swap(m_vKeys.begin() + i, m_vKeys.begin() + j);
		}
	}
}
void EventHandle::PollInput()
{
	int i = 0;
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) { m_vKeys.push_back(VK_LEFT); ++i; }
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { m_vKeys.push_back(VK_RIGHT); ++i; }
	if (GetAsyncKeyState(VK_UP) & 0x8000) { m_vKeys.push_back(VK_UP); ++i; }
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) { m_vKeys.push_back(VK_DOWN);  ++i; }

	if (GetAsyncKeyState('W') & 0x8000)	{ m_vKeys.push_back(0x57);  ++i; } // W Key
	if (GetAsyncKeyState('A') & 0x8000) { m_vKeys.push_back(0x41);  ++i; } // A Key
	if (GetAsyncKeyState('S') & 0x8000) { m_vKeys.push_back(0x53);  ++i; } // S Key
	if (GetAsyncKeyState('D') & 0x8000) { m_vKeys.push_back(0x44);  ++i; } // D Key

	if (GetAsyncKeyState('P') & 0x8000) { m_vKeys.push_back(0x50);  ++i; } // P Key
	if (GetAsyncKeyState('G') & 0x8000) { m_vKeys.push_back(0x47);  ++i; } // G Key
	if (GetAsyncKeyState('X') & 0x8000) { m_vKeys.push_back(0x58);  ++i; } // X Key

	if (GetAsyncKeyState('F') & 0x8000) { m_vKeys.push_back(0x46);  ++i; } // F Key

	if (GetAsyncKeyState(VK_RETURN) & 0x8000) { m_vKeys.push_back(VK_RETURN);  ++i; }

	if (GetAsyncKeyState(VK_PRIOR) & 0x8000) { m_vKeys.push_back(VK_PRIOR); ++i; }
	if (GetAsyncKeyState(VK_NEXT) & 0x8000) { m_vKeys.push_back(VK_NEXT); ++i; }

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { m_vKeys.push_back(VK_ESCAPE); ++i; }

	OrderInput();
	ParseInput();
	if (!i)
	{
		m_vPrevKeys.clear();
		m_vSincePressed.clear();
		m_vSinceRepeat.clear();
	}
}

void EventHandle::OnKeyPress(int a_iKey)
{
	// Virtual, Do Nothing...
}
void EventHandle::OnKeyRepeat(int a_iKey)
{
	// Virtual, Do Nothing...
}
void EventHandle::OnKeyRelease(int a_iKey)
{
	// Virtual, Do Nothing...
}

EventHandle::EventHandle()
{
	//m_vKeys.assign(8,0);
}


EventHandle::~EventHandle()
{
}
