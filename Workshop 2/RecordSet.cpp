// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstring>
#include "RecordSet.h"
#include "TimedEvents.h"

using namespace std;

namespace sdds
{
	RecordSet::RecordSet()
	{
		m_string = nullptr;
		COUNT = 0;
	}

	//open file, detect word from whitespace to whitespace, save word
	RecordSet::RecordSet(const char * fileName) : RecordSet()
	{
		COUNT = 1;
		std::ifstream fileInput;
		std::string line;

		fileInput.open(fileName);

		if (fileInput.is_open())
		{
			while (getline(fileInput, line, ' '))
			{
				if (fileInput.good())
				{
					COUNT++;
				}

			}

			fileInput.close();
		}

		m_string = new string[COUNT];

		fileInput.open(fileName);

		if (fileInput.is_open())
		{

			for (size_t i = 0; i < COUNT; i++)
			{
				getline(fileInput, line, ' ');
				m_string[i] = line;
			}

			fileInput.close();
		}
	}

	//copy constructor and copy operator
	RecordSet::RecordSet(const RecordSet& cpy) : RecordSet()
	{
		*this = cpy;
	}

	RecordSet & RecordSet::operator = (const RecordSet& cpy)
	{
		if (this != &cpy)
		{
			delete[] m_string;
			COUNT = cpy.COUNT;
			m_string = new std::string[COUNT];

			for (size_t i = 0; i < (size_t)COUNT; i++)
			{
				m_string[i] = cpy.m_string[i];
			}
		}

		return *this;
	}

	//move constructor and move operator
	RecordSet& RecordSet::operator=(RecordSet&& src)
	{
		if (this != &src)
		{
			m_string = src.m_string;
			COUNT = src.COUNT;
			src.COUNT = 0;
			src.m_string = nullptr;
		}

		return *this;
	}

	RecordSet::RecordSet(RecordSet&& src)
	{
		*this = std::move(src);
	}

	//deconstructor
	RecordSet::~RecordSet()
	{
		delete[] m_string;
		m_string = nullptr;
	}

	//return counter
	size_t RecordSet::size()
	{
		return COUNT;
	}

	std::string RecordSet::getRecord(size_t idx)
	{
		if (idx < COUNT)
		{
			return m_string[idx];
		}

		else
		{
			return std::string();
		}
	}
}