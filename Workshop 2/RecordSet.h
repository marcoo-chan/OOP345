// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <cstring>
#include <iostream>
#include <chrono>

namespace sdds
{

	class RecordSet
	{
		std::string * m_string;
		size_t COUNT;

	public:
		RecordSet();
		RecordSet(const char * fileName);
		RecordSet(const RecordSet& cpy);
		RecordSet& operator = (const RecordSet& cpy);
		RecordSet(RecordSet&& src);
		RecordSet& operator = (RecordSet&& src);
		~RecordSet();
		size_t size();
		std::string getRecord(size_t idx);
	};

}

#endif 