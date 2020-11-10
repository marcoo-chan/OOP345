// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/06/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{
	class Reservation
	{
		string m_resId;
		string m_resName;
		string m_resEmail;
		int m_noOfPeople;
		int m_day;
		int m_hour;

	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator << (std::ostream& os, const Reservation& obj);
	};
}

#endif