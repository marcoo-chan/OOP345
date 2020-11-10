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
#include <fstream>
#include <cstring>
#include "Station.h"
#include "Utilities.h"

using namespace std;

	unsigned int Station::m_widthField = 0;
	unsigned int Station::id_generator = 0;

	Station::Station(const std::string str) 
	{
		//inherit 3 arguments from Utilities extractToken (str, next_pos, more)
		//constructor uses an Utilities object to extract each token from the record
		Utilities m_util;
		size_t next_pos = 0;
		bool more = true;

		m_name = m_util.extractToken(str, next_pos, more); //extract name
		m_serialNumber = stoi(m_util.extractToken(str, next_pos, more)); //stoi extract integer serial number
		m_quantity = stoi(m_util.extractToken(str, next_pos, more)); //stoi extract integer quantity

		if (m_widthField < m_util.getFieldWidth())
		{
			m_widthField = m_util.getFieldWidth();
		}

		m_description = m_util.extractToken(str, next_pos, more); //extract description

		m_id = ++id_generator;
	}

	const std::string & Station::getItemName() const
	{
		return m_name;
	}

	unsigned int Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}

	unsigned int Station::getQuantity() const
	{
		return m_quantity;
	}

	void Station::updateQuantity()
	{
		if (m_quantity > 0)
		{
			m_quantity --;
		}
	}

	void Station::display(std::ostream & os, bool full) const
	{
		os << right << "[" << setw(3) << setfill('0') << m_id << "] ";
		os << "Item: " << left << setfill(' ') << setw(m_widthField) << m_name;
		os << " [" << setw(6) << setfill('0') << right << m_serialNumber << "]";

		if (full) 
		{
			os << " Quantity: " << std::left << std::setw(m_widthField) << setfill(' ') << m_quantity;
			os << right << " Description: " << m_description;
		}

		os << std::endl;
	}
