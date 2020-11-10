// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
		m_res = nullptr;
		m_COUNT = 0;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_res;
		m_res = nullptr;
	}

	ConfirmationSender & ConfirmationSender::operator+=(const Reservation & res)
	{
		bool CHECK = false;

		for (size_t i = 0; i < m_COUNT; i++)
		{
			if (m_res[i] == &res) //compare existing array for res
			{
				CHECK = true; //if res is already in the array, this operator does nothing
			}
		}

		if (CHECK == false)
		{
			Reservation** temp = new Reservation*[m_COUNT + 1];

			for (size_t i = 0; i < m_COUNT; i++)
			{
				temp[i] = const_cast<Reservation*>(m_res[i]);
			}

			delete[] m_res;
			m_res = const_cast<const Reservation**>(temp);
			m_res[m_COUNT++] = &res; //resize the array to make room for res
		}

		return *this;
	}

	ConfirmationSender & ConfirmationSender::operator-=(const Reservation & res)
	{
		for (size_t i = 0; i < m_COUNT; i++)
		{
			if (m_res[i] == &res) //compare existing array for res
			{
				m_res[i] = nullptr; //set the pointer in the array to nullptr when res is found
				m_COUNT--; //resize the array
			}
		}

		return *this;
	}

	ConfirmationSender & ConfirmationSender::operator=(const ConfirmationSender & cpy)
	{
		if (this != &cpy)
		{
			delete[] m_res;
			m_res = nullptr;
			m_COUNT = cpy.m_COUNT;

			if (cpy.m_res != nullptr)
			{
				m_res = new const Reservation *[cpy.m_COUNT];

				for (size_t i = 0; i < cpy.m_COUNT; i++)
				{
					m_res[i] = cpy.m_res[i];
				}
			}

			else
			{
				m_res = nullptr;
			}
		}

		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender & cpy)
	{
		*this = cpy;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender && src)
	{
		*this = std::move(src);
	}

	ConfirmationSender & ConfirmationSender::operator=(ConfirmationSender && src)
	{
		if (this != &src)
		{
			delete[] m_res;
			m_res = src.m_res;
			m_COUNT = src.m_COUNT;
			src.m_COUNT = 0;
			src.m_res = nullptr;
		}

		return *this;
	}

	std::ostream & operator<<(std::ostream & os, const ConfirmationSender & obj)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (obj.m_COUNT == 0)
		{
			os << "The object is empty!" << std::endl;
		}

		else
		{
			for (size_t i = 0; i < obj.m_COUNT; i++)
			{
				os << *obj.m_res[i];
			}
		}

		os << "--------------------------" << std::endl;

		return os;
	}
}
