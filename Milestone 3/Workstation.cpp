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
#include <string>
#include <deque>
#include "Workstation.h"
#include "Station.h"
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

	Workstation::Workstation(const std::string & str) : Station(str)
	{
		
	}

	void Workstation::runProcess(std::ostream & os) 
	{
		if (!m_orders.empty())
		{
			CustomerOrder& order = m_orders.back();

			if (!order.isItemFilled(getItemName()))
			{
				order.fillItem(*this, os);
			}
		}
	}

	bool Workstation::moveOrder()
	{
		if (!m_orders.empty())
		{
			CustomerOrder& order = m_orders.back();

			if (order.isItemFilled(getItemName()) && m_pNextStation != nullptr)
			{
				*m_pNextStation += std::move(order);
				m_orders.pop_back();
				return true;
			}
		}

		return false;
	}

	void Workstation::setNextStation(Station& station) 
	{
		m_pNextStation = (Workstation*) &station;
	}

	const Workstation * Workstation::getNextStation() const 
	{
		return m_pNextStation; 
	}

	bool Workstation::getIfCompleted(CustomerOrder & order)
	{
		if (!m_orders.empty() && m_orders.back().isOrderFilled())
		{
			order = std::move(m_orders.back());
			m_orders.pop_back();
			return true;
		}

		return false;
	}

	void Workstation::display(std::ostream & os) const
	{
		os << getItemName() << " --> ";

		if (m_pNextStation) 
		{
			os << m_pNextStation->getItemName() << endl;
		}

		else
		{
			os << "END OF LINE" << endl;
		}
	}

	Workstation & Workstation::operator+=(CustomerOrder && order)
	{
		m_orders.push_front(std::move(order));
		return *this;
	}
