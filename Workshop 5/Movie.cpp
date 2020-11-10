// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Movie.h"

using namespace std;

namespace sdds
{
	Movie::Movie()
	{
		m_title = "";
		m_desc = "";
		m_year = 0;
	}

	const std::string & Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		string temp = strMovie;

		size_t firstComma = temp.find(',');
		size_t secondComma = temp.find(',', firstComma + 1);

		m_title = temp.substr(0, firstComma);
		m_title.erase(0, m_title.find_first_not_of(' '));
		m_title.erase(m_title.find_last_not_of(' ') + 1);
		m_year = stoi(temp.substr(firstComma + 1, (secondComma - (firstComma + 1))));
		m_desc = temp.substr(secondComma + 1);
		m_desc.erase(0, m_desc.find_first_not_of(' '));
	}

	std::ostream& operator << (std::ostream& os, const Movie& obj)
	{
		os << setw(40) << obj.m_title << " | ";
		os << setw(4) << obj.m_year << " | ";
		os << obj.m_desc << endl;

		return os;
	}
}