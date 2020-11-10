// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/06/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	Reservation::Reservation()
	{
		m_resId = "";
		m_resName = "";
		m_resEmail = "";
		m_noOfPeople = 0;
		m_day = 0; 
		m_hour = 0;
	}

	Reservation::Reservation(const std::string& res)
	{
		if (!(res == "" || res[0] == '#'))
		{
			string temp = res;

			while (temp.find(' ') != string::npos)
			{
				temp.erase(temp.find(' '), 1);
			}

			size_t colon = temp.find(':');
			size_t firstComma = temp.find(',');
			size_t secondComma = temp.find(',', firstComma + 1);
			size_t thirdComma = temp.find(',', secondComma + 1);
			size_t fourthComma = temp.find(',', thirdComma + 1);

			m_resId = temp.substr(0, colon);
			m_resName = temp.substr(colon + 1, (firstComma - (colon + 1)));
			m_resEmail = temp.substr(firstComma + 1, (secondComma - (firstComma + 1)));
			m_noOfPeople = stoi(temp.substr(secondComma + 1, (thirdComma - (secondComma + 1))));
			m_day = stoi(temp.substr(thirdComma + 1, (fourthComma - (thirdComma + 1))));
			m_hour = stoi(temp.substr(fourthComma + 1));
		}
	}

	std::ostream& operator << (std::ostream& os, const Reservation& obj)
	{
		string temp;
		string concatEmail = "<" + obj.m_resEmail + ">";

		if (obj.m_hour >= 6 && obj.m_hour <= 9)
		{
			temp = "Breakfast on day";
		}

		else if (obj.m_hour >= 11 && obj.m_hour <= 15)
		{
			temp = "Lunch on day";
		}

		else if (obj.m_hour >= 17 && obj.m_hour <= 21)
		{
			temp = "Dinner on day";
		}

		else
		{
			temp = "Drinks on day";
		}

		os << "Reservation " << obj.m_resId + ": " << setw(10) << right << obj.m_resName << "  " << setw(20) << left << concatEmail << "    " << temp << " " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_noOfPeople << " people." << endl;
		return os;
	}
}
