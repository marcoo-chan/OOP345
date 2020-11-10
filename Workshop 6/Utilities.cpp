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
#include <sstream>
#include "Car.h"
#include "Racecar.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in) 
	{
		string temp;
		char err = '\0';
		getline(in, temp);

		if (!temp.empty() && temp[0] != '\0') 
		{
			size_t pos = temp.find_first_not_of(' ');
			size_t endPos = temp.find_last_not_of(' ');
			temp = temp.substr(pos, endPos - pos + 1);
			stringstream record(temp);

			record >> err;

			if (temp[0] == 'c' || temp[0] == 'C') 
			{
				return new Car(record);
			}

			else if (temp[0] == 'r' || temp[0] == 'R')
			{
				return new Racecar(record);
			}

			else
			{
				throw err;
			}
		}

		return nullptr;
	}
}