// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 04/04/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include "CustomerOrder.h"
#include "Workstation.h"
#include "Station.h"

using namespace std;

class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder = 0;

	Workstation* ws1 = nullptr;
	Workstation* ws2 = nullptr;

public:
	LineManager(const std::string& str, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};

#endif