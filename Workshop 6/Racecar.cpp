// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/06/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds
{
	Racecar::Racecar(std::istream & in) : Car(in)
	{
		string temp;
		getline(in, temp, ',');
		m_booster = stod(temp);
	}

	void Racecar::display(std::ostream & out) const
	{
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}
}