// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/14/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sdds
{
	Book::Book()
	{
		m_author = "";
		m_title = "";
		m_country = "";
		m_desc = "";
		m_price = 0.0;
		m_year = 0;
	}

	const std::string & Book::title() const
	{
		return m_title;
	}

	const std::string & Book::country() const
	{
		return m_country;
	}

	const size_t & Book::year() const
	{
		return m_year;
	}

	double & Book::price()
	{
		return m_price;
	}

	Book::Book(const std::string & strBook)
	{
		if (!(strBook == "" || strBook[0] == '#'))
		{
			string temp = strBook;

			size_t firstComma = temp.find(',');
			size_t secondComma = temp.find(',', firstComma + 1);
			size_t thirdComma = temp.find(',', secondComma+ 1);
			size_t fourthComma = temp.find(',', thirdComma + 1);
			size_t fifthComma = temp.find(',', fourthComma + 1);

			m_author = temp.substr(0, firstComma);
			m_author.erase(0, m_author.find_first_not_of(' '));
			m_author.erase(m_author.find_last_not_of(' ') + 1);
			m_title = temp.substr(firstComma + 1, (secondComma - (firstComma + 1)));
			m_title.erase(0, m_title.find_first_not_of(' '));
			m_title.erase(m_title.find_last_not_of(' ') + 1);
			m_country = temp.substr(secondComma + 1, (thirdComma - (secondComma + 1)));
			m_country.erase(0, m_country.find_first_not_of(' '));
			m_country.erase(m_country.find_last_not_of(' ') + 1);
			m_price = stod(temp.substr(thirdComma + 1, (fourthComma - (thirdComma + 1))));
			m_year = stoi(temp.substr(fourthComma + 1, (fifthComma - (fourthComma + 1))));
			m_desc = temp.substr(fifthComma + 1);
			m_desc.erase(0, m_desc.find_first_not_of(' '));
		}

	}

	
	std::ostream & operator<<(std::ostream & os, const Book & obj)
	{
		os << setw(20) << obj.m_author << " | ";
		os << setw(22) << obj.m_title << " | ";
		os << setw(5) << obj.m_country << " | ";
		os << setw(4) << obj.m_year << " | ";
		os << setw(6) << fixed << setprecision(2) << obj.m_price << " | ";
		os << obj.m_desc << endl;

		return os;
	}

}
