// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include "Station.h"

using namespace std;


	class Utilities
	{
		static size_t m_widthField;
		static char m_delimiter;

	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimeter);
		static char getDelimiter();
	};

#endif