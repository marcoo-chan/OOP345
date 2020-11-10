// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include "Station.h"
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;

	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr; 
	}

	CustomerOrder::CustomerOrder(const std::string & str)
	{
		Utilities m_util; //utilities object to extract tokens (str, next_pos, more)

		size_t first_pos = 0;
		size_t second_pos = 0;
		vector<string> token;
		bool more = true;

		m_name = m_util.extractToken(str, first_pos, more);
		m_product = m_util.extractToken(str, first_pos, more);

		second_pos = first_pos;
		m_cntItem = 0;

		while (more) 
		{
			token.push_back(m_util.extractToken(str, first_pos, more));
			m_cntItem++;
		}

		m_cntItem--;
		m_lstItem = new Item*[token.size()];

		for (size_t i = 0; i < token.size(); i++) 
		{
			token[i] = m_util.extractToken(str, second_pos, more);
			m_lstItem[i] = new Item(token[i]);
		}

		if (m_widthField < m_util.getFieldWidth()) 
		{
			m_widthField = m_util.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder & cpy)
	{
		throw "ERROR: Cannot make copies.";
	}

	CustomerOrder::CustomerOrder(CustomerOrder && cpy) noexcept
	{
		m_lstItem = nullptr;
		*this = std::move(cpy);
	}

	CustomerOrder & CustomerOrder::operator=(CustomerOrder && cpy)
	{
		if (this != &cpy)
		{
			if (m_lstItem)
			{
				for (size_t i = 0; i < m_cntItem; i++)
				{
					delete m_lstItem[i];
				}

				delete[] m_lstItem;
			}

			m_name = cpy.m_name;
			m_product = cpy.m_product;
			m_cntItem = cpy.m_cntItem;
			m_lstItem = cpy.m_lstItem;

			cpy.m_name.clear();
			cpy.m_product.clear();;
			cpy.m_cntItem = 0;
			cpy.m_lstItem = nullptr;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}

		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		for (size_t i = 0; i < m_cntItem; i++) 
		{
			if (!m_lstItem[i]->m_isFilled || m_lstItem[i]->m_isFilled == false)
			{
				return false;
			}
		}

		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string & itemName) const
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (m_lstItem[i]->m_isFilled == false)
				{
					return false;
				}
			}
		}

		return true;
	}

	void CustomerOrder::fillItem(Station & station, std::ostream & os) 
	{
		for (size_t i = 0; i < m_cntItem; i++) 
		{
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) 
			{
				if (station.getQuantity() != 0)
				{
					station.updateQuantity(); //subtract 1 from inventory (-1)
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber(); //update serial number (+1)
					m_lstItem[i]->m_isFilled = true; //update m_isFilled

					os << "    Filled ";
				}

				else
				{
					os << "    Unable to fill ";
				}
				
				os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}

	void CustomerOrder::display(std::ostream & os) const
	{
		os << left << m_name << " - " << m_product << endl;
		
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << setw(6) << right << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName << " - ";

			if (m_lstItem[i]->m_isFilled)
			{
				os << "FILLED";
			}

			else
			{
				os << "MISSING";
			}

			os << endl;
		}
	}
