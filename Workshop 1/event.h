// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/16/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

extern unsigned g_sysClock;
using namespace std;

namespace sdds
{
	class Event
	{
		char * m_desc;
		size_t m_start;

	public:
		Event();
		Event(const Event& cpy);
		void display();
		void setDescription(const char * word);
		Event& operator=(const Event& cpy);
	};
}

#endif