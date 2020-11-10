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
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename) //edit
	{
		std::ifstream file(filename);

		if (!file.is_open())
		{
			throw "Bad file name!";
		}

		else
		{
			size_t i = 0;

			while (file)
			{
				file >> m_badWords[i];
				file >> m_goodWords[i];
				i++;
			}
		}

		file.close();
	}

	void SpellChecker::operator()(std::string& text) const
	{
		for (size_t i = 0; i < (sizeof(m_badWords) / sizeof(m_badWords[0])); i++)
		{
			size_t pos = text.find(m_badWords[i]);

			while (pos != text.npos)
			{
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				pos = text.find(m_badWords[i]);
			}
		}
	}
}

