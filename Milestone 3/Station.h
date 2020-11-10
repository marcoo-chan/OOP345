// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include "Utilities.h"

using namespace std;

	class Station
	{
		string m_name;
		string m_description;
		unsigned int m_id;
		unsigned int m_serialNumber;
		unsigned int m_quantity;

		static unsigned int m_widthField;
		static unsigned int id_generator;

	public:
		Station(const std::string str);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		unsigned int getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

#endif