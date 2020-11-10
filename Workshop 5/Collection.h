// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 02/22/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{
	template <typename T>

	class Collection
	{
		std::string m_name;
		T* m_items;
		size_t SIZE;

		void(*newItem) (const Collection<T>&, const T&);

	public:
		Collection(std::string name)
		{
			m_name = name;
			m_items = nullptr;
			SIZE = 0;
			newItem = nullptr;
		}

		Collection(const Collection& src) = delete;
		Collection& operator = (const Collection& src) = delete;

		~Collection()
		{
			delete[] m_items;
			m_items = nullptr;
		}

		const std::string& name() const 
		{
			return m_name;
		}

		size_t size() const
		{
			return SIZE;
		}

		void setObserver(void(*observer)(const Collection<T>&, const T&))
		{
			newItem = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool same = false;

			for (size_t i = 0; i < SIZE && !same; i++)
			{
				if (m_items[i].title() == item.title())
				{
					same = true;
					return *this;
				}
			}

			if (same == false)
			{
				T * tmp = new T[SIZE + 1];

				for (size_t i = 0; i < SIZE; i++)
				{
					tmp[i] = m_items[i];
				}
				
				tmp[SIZE] = item;
				delete[] m_items;
				m_items = tmp;
				m_items[SIZE++] = item; //check
				

				if (newItem != nullptr)
				{
					newItem(*this, item);
				}
			}

			return *this;
		}

		T& operator[](size_t idx) const
		{

			if (idx < SIZE)
			{
				return m_items[idx];
			}

				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(SIZE) + "] items.");
		}

		T* operator[](std::string title) const
		{
			for (size_t i = 0; i < SIZE; i++)
			{
				if (title == m_items[i].title())
				{
					return m_items + i;
				}
			}

			return nullptr;
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& obj)
	{
		for (size_t i = 0; i < obj.size(); i++)
		{
			os << obj[i];
		}

		return os;
	}
}

#endif