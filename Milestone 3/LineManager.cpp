// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 04/04/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <deque>
#include <utility>
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include "LineManager.h"

using namespace std;

	LineManager::LineManager(const std::string & fileName, std::vector<Workstation*>& ws, std::vector<CustomerOrder>& temp)
	{
		ifstream fileInput(fileName);
		std::string line;
		std::vector<Station*> nextWS;

		while (getline(fileInput, line))
		{
			if (!fileInput)
			{
				throw "ERROR: Cannot open file [" + fileName + "].\n";
			}

			Utilities m_util; 
			size_t next_pos = 0; 
			bool more = true; 

			string temp1 = m_util.extractToken(line, next_pos, more); 
			string temp2 = m_util.extractToken(line, next_pos, more); 

			if (more)
			{
				auto task1 = find_if(ws.begin(), ws.end(), [&](Workstation* ws)
				{
					return ws->getItemName() == temp1;
				});

				auto task2 = find_if(ws.begin(), ws.end(), [&](Workstation* ws)
				{
					return ws->getItemName() == temp2;
				});

				(*task1)->setNextStation(**task2);
				nextWS.push_back(*task2);
			}

			else
			{
				auto task1 = find_if(ws.begin(), ws.end(), [&](Workstation* ws)
				{
					return ws->getItemName() == temp1;
				});

				ws2 = *task1;
			}
		}

		for (auto&& m_orders : temp)
		{
			ToBeFilled.push_front(std::move(m_orders));
		}

		m_cntCustomerOrder = ToBeFilled.size();

		bool check = false;

		for (auto workstation : ws)
		{
			AssemblyLine.push_back(workstation);

			if (!check && nextWS.end() == find(nextWS.begin(), nextWS.end(), workstation))
			{
				ws1 = workstation;
			}
		}
	}

	bool LineManager::run(std::ostream & os) 
	{
		static int COUNT = 1;

		os << "Line Manager Iteration: " << COUNT++ << endl;

		if (!ToBeFilled.empty())
		{
			*ws1 += std::move(ToBeFilled.back());
			ToBeFilled.pop_back();
		}

		for (auto stations : AssemblyLine)
		{
			stations->runProcess(os);
		}

		for (auto stations : AssemblyLine)
		{
			stations->moveOrder();
		}

		CustomerOrder temp;
		
		if (ws2->getIfCompleted(temp))
		{
			Completed.push_back(std::move(temp));
		}

		return Completed.size() == m_cntCustomerOrder;
	}

	void LineManager::displayCompletedOrders(std::ostream & os) const
	{
		for (auto& order : Completed)
		{
			order.display(os);
		}
	}

	void LineManager::displayStations() const 
	{
		for (auto stations : AssemblyLine)
		{
			stations->display(std::cout);
		}
	}

	void LineManager::displayStationsSorted() const 
	{
		const Workstation* wstations = ws1;

		while (wstations)
		{
			wstations->display(std::cout);
			wstations = wstations->getNextStation();
		}
	}
