// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{
	class Movie
	{
		std::string m_title;
		std::string m_desc;
		size_t m_year;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		friend std::ostream& operator << (std::ostream& os, const Movie& obj);
	};
}

#endif