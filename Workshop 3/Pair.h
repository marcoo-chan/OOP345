// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

namespace sdds
{
	template <typename K, typename V>

	class Pair
	{
		K m_keyType;
		V m_valueType;

	public:
		Pair() : m_keyType{}, m_valueType{} {}

		Pair(const K& key, const V& value)
		{
			m_keyType = key;
			m_valueType = value;
		}

		const K& key() const
		{
			return m_keyType;
		}

		const V& value() const
		{
			return m_valueType;
		}

		virtual void display(std::ostream& os) const
		{
			os << m_keyType << " : " << m_valueType << std::endl;
		}
	};

	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}

#endif