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

using namespace std;

namespace sdds
{
	Car::Car()
	{
		m_maker = "";
		m_condition = "";
		m_topSpeed = 0.0;
	}

	std::string & Car::trim(std::string & str)
	{
		while (str.length() > 0 && str[0] == ' ')
		{
			str.erase(0, 1);
		}

		while (str.length() > 0 && str[str.length() - 1] == ' ')
		{
			str.erase(str.length() - 1, 1);
		}

		return str;
	}

	Car::Car(std::istream& is)
	{
		string temp;

		//trim leading and trailing whitespaces
		getline(is, temp, ',');
		trim(temp);

		//get maker and check if its a car
		//if (temp[0] == 'c' || temp[0] == 'C')
		//{
			getline(is, m_maker, ',');
			trim(m_maker);

			//get condition of car
			getline(is, temp, ',');
			trim(temp);

			if (temp == "" || temp == "n")
			{
				m_condition = "new";
			}

			else if (temp == "b")
			{
				m_condition = "broken";
			}

			else if (temp == "u")
			{
				m_condition = "used";
			}

			else
			{
				throw "Invalid record!";
			}

			//get speed
			getline(is, temp, ',');

			try
			{
				m_topSpeed = stod(temp);
			}

			catch (...)
			{
				throw "Invalid record!";
			}
		//}
	}

	std::string Car::condition() const
	{
		return m_condition;
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(std::ostream & out) const
	{
		out << "| " << right << setw(10) << m_maker;
		out << " | " << left << setw(6) << m_condition;
		out << " | " << fixed << setprecision(2) << setw(6) << topSpeed() << " |";
	}
}