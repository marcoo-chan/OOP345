// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[5];
		std::string m_goodWords[5];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}

#endif