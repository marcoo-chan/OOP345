// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/06/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif