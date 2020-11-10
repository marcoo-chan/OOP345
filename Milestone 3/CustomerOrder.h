// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 03/20/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <memory>
#include <string>
#include <list>
#include <iostream>
#include "Utilities.h"
#include "Station.h"

using namespace std;

	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			unsigned int m_serialNumber = 0;
			bool m_isFilled = false;

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name;
		std::string m_product;
		unsigned int m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);

		CustomerOrder(const CustomerOrder& cpy);
		CustomerOrder& operator=(const CustomerOrder& cpy) = delete;
		CustomerOrder(CustomerOrder&& cpy) noexcept;
		CustomerOrder& operator=(CustomerOrder&& cpy);
		~CustomerOrder();

		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};

#endif