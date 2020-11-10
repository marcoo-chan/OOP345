// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds
{
	Restaurant::Restaurant()
	{
		m_res = nullptr;
		m_COUNT = 0;
	}

	Restaurant::~Restaurant()
	{
		delete[] m_res;
	}

	Restaurant::Restaurant(Reservation * reservations[], size_t cnt)
	{
		m_COUNT = cnt;
		m_res = new Reservation[cnt];

		for (size_t i = 0; i < cnt; i++) //iterate through each array of pointers from object of type Reservation
		{
			m_res[i] = *reservations[i]; //arg "Reservation * reservations[]"
		}
	}

	Restaurant & Restaurant::operator=(const Restaurant & cpy) //cpy operator
	{
		if (this != &cpy)
		{
			m_COUNT = cpy.m_COUNT;
			m_res = new Reservation[m_COUNT];

			for (size_t i = 0; i < cpy.m_COUNT; i++)
			{
				m_res[i] = cpy.m_res[i];
			}
		}

		return *this;
	}
	

	Restaurant::Restaurant(const Restaurant & cpy) //cpy constructor
	{
		*this = cpy;
	}

	Restaurant & Restaurant::operator=(Restaurant && src) //move operator
	{
		if (this != &src)
		{
			m_res = src.m_res;
			m_COUNT = src.m_COUNT;
			src.m_COUNT = 0;
			src.m_res = nullptr;
		}

		return *this;
	}

	Restaurant::Restaurant(Restaurant && src) //move constructor
	{
		*this = std::move(src);
	}

	size_t Restaurant::size() const
	{
		return m_COUNT;
	}

	std::ostream & operator<<(std::ostream & os, const Restaurant & obj)
	{
		if (obj.m_COUNT == 0 || obj.m_res == nullptr)
		{
			os << "--------------------------" << std::endl;
			os << "Fancy Restaurant" << std::endl;
			os << "--------------------------" << std::endl;
			os << "The object is empty!" << std::endl;
			os << "--------------------------" << std::endl;
		}

		else
		{
			os << "--------------------------" << std::endl;
			os << "Fancy Restaurant" << std::endl;
			os << "--------------------------" << std::endl;

			for (size_t i = 0; i < obj.m_COUNT; i++)
			{
				os << obj.m_res[i];
			}

			os << "--------------------------" << std::endl;
		}

		return os;
	}
}

