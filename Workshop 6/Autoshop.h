// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/06/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <vector>
#include <list>
#include "Car.h"
#include "Vehicle.h"

using namespace std;

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto& car : m_vehicles)
			{
				if (test(car)) vehicles.push_back(car);
			}
		}
	};
}

#endif