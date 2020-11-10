// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SET_H
#define SDDS_SET_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

namespace sdds
{
	template <typename T, int N>

	class Set
	{
		T m_array[N];
		size_t m_numOfElements = 0;

	public:
		size_t size() const
		{
			return m_numOfElements;
		}

		const T& operator[](size_t i) const
		{
			return m_array[i];
		}

		void operator += (const T& item)
		{
			if (m_numOfElements < N)
			{
				m_array[m_numOfElements] = item;
				m_numOfElements++;
			}
		}
	};
}

#endif