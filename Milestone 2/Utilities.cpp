// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Station.h"
#include "Utilities.h"

using namespace std;

	size_t Utilities::m_widthField = 1;
	char Utilities::m_delimiter; //delimeter preset in main ("," and "|")

	void Utilities::setFieldWidth(size_t newWidth) //sets the field width of the current object to the value of the parameter
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more)
	{
		string token = str.substr(next_pos);
		size_t pos = token.find(m_delimiter);

		if (pos != string::npos)
		{
			token = token.substr(0, pos);
			next_pos += token.size() + 1;
			more = true;

			if (m_widthField < token.size()) 
			{
				m_widthField = token.size();
			}
		}

		else
		{
			more = false;
		}

		return token;
	}

	void Utilities::setDelimiter(char newDelimeter)
	{
		m_delimiter = newDelimeter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}