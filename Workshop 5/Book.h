// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/14/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_desc;
		size_t m_year;
		double m_price;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_desc);
		}

		friend std::ostream& operator << (std::ostream& os, const Book& obj);
	};
}

#endif