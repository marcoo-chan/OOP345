// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/10/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Car.h"

using namespace std;

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif