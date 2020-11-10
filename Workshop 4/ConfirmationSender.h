// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/11/2010
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Reservation.h"
#include "Restaurant.h"

using namespace std;

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_res = nullptr;
		size_t m_COUNT = 0;

	public:
		ConfirmationSender();
		~ConfirmationSender();

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		ConfirmationSender& operator = (const ConfirmationSender& cpy); //copy operator
		ConfirmationSender(const ConfirmationSender& cpy); //copy constructor
		
		ConfirmationSender(ConfirmationSender&& src); //move constructor
		ConfirmationSender& operator=(ConfirmationSender&& src); //move operator

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj);
	};
}

#endif