// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/11/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	class Restaurant
	{
		Reservation * m_res; //dynamically allocated array of objects of type Reservation
		size_t m_COUNT;

	public:
		Restaurant();
		~Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant& operator = (const Restaurant& cpy); //copy operator
		Restaurant(const Restaurant& cpy); //copy constructor
		Restaurant& operator = (Restaurant&& src); //move operator
		Restaurant(Restaurant&& src); //move constructor
		size_t size() const;

		friend std::ostream& operator << (std::ostream& os, const Restaurant& obj);
	};
}

#endif