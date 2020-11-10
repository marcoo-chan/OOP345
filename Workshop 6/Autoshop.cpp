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
#include "Autoshop.h"

using namespace std;

namespace sdds
{
	Autoshop & Autoshop::operator+=(Vehicle * theVehicle)
	{
		m_vehicles.push_back(theVehicle);

		return *this;
	}

	void Autoshop::display(std::ostream & out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (auto car : m_vehicles)
		{
			car -> display(out);
			out << endl;
		}

		out << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop()
	{
		for (auto& car : m_vehicles)
		{
			delete car;
		}
	}
}