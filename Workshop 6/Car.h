// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/06/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
		double m_booster;

	public:
		Car();
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string& trim(std::string& str);
	};
}

#endif