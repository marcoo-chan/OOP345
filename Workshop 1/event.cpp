// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;
unsigned g_sysClock = 0;

namespace sdds
{
	Event::Event()
	{
		m_desc = nullptr;
		m_start = 0;
	}

	void Event::display()
	{
		static size_t COUNTER = 1;

		if (m_desc != nullptr && m_desc[0] != '\0')
		{
			unsigned m_hour, m_minute, m_seconds;

			m_hour = m_start / 3600;
			m_minute = (m_start % 3600) / 60;
			m_seconds = m_start % 60;

			cout << setw(3) << COUNTER << ". ";
			cout << setfill('0') << setw(2) << m_hour << ":" << setw(2) << m_minute << ":" << setw(2) << m_seconds;
			cout << setfill(' ') << " -> " << m_desc << endl;

			COUNTER++;
		}

		else
		{
			cout << setw(3) << COUNTER << ". " << "[ No Event ]" << endl;

			COUNTER++;
		}
	}

	void Event::setDescription(const char * word)
	{
		if (word == nullptr || word[0] == '\0')
		{
			m_desc[0] = '\0';
		}

		else
		{
			m_desc = new char[g_sysClock];
			strncpy(m_desc, word, g_sysClock);
			m_start = g_sysClock;
		}
	}

	Event& Event::operator=(const Event& cpy)
	{ 
		if (this != &cpy)
		{
			m_desc = new char[g_sysClock];
			strncpy(m_desc, cpy.m_desc, g_sysClock);
			m_start = cpy.m_start;
		}

		else
		{
			m_desc = nullptr;
			m_start = 0;
		}

		return *this;
	}

	Event::Event(const Event& cpy)
	{
		*this = cpy;
	}

}