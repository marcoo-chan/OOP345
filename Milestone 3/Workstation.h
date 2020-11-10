// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 04/04/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <string>
#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"

using namespace std;

class Workstation : public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation * m_pNextStation = nullptr;

public:
	Workstation (const std::string&);

	Workstation (const Workstation&) = delete; //copy con
	Workstation& operator=(const Workstation&) = delete; //copy op
	Workstation (Workstation&&) = delete; //move con
	Workstation& operator=(Workstation&&) = delete; //move op

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};

#endif