// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/23/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <cstring>
#include <iostream>
#include <chrono>

namespace sdds
{
	const int MAX = 7;

	class TimedEvents
	{
		int noOfRecords;

		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point stop;

		struct
		{
			const char * m_msg;
			const char * m_unitOfTime;

			std::chrono::steady_clock::duration duration;
		} record[MAX];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char * event);
		friend std::ostream& operator << (std::ostream& os, const TimedEvents& cpy);
	};

}

#endif 