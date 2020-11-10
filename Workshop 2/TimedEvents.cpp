// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstring>
#include "TimedEvents.h"

using namespace std;

namespace sdds
{
	TimedEvents::TimedEvents()
	{
		noOfRecords = 0;
	}

	void TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		stop = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char * event)
	{
		auto durationTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

		if (noOfRecords < MAX) //struct 
		{
			record[noOfRecords].m_msg = event;
			record[noOfRecords].m_unitOfTime = "nanoseconds";
			record[noOfRecords].duration = durationTime;

			noOfRecords++;
		}
	}

	std::ostream& operator << (std::ostream& os, const TimedEvents& cpy)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;

		for (int i = 0; i < cpy.noOfRecords; i++)
		{
			os << setw(20) << left << cpy.record[i].m_msg << " ";
			os << setw(12) << right << cpy.record[i].duration.count() << " ";
			os << cpy.record[i].m_unitOfTime << endl;
		}

		os << "--------------------------" << endl;
		return os;
	}
}
