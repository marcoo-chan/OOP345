// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include "Pair.h"
#include "SetSummable.h"

using namespace std;

namespace sdds
{
	template <typename K, typename V>

	class PairSummable : public Pair <K, V>
	{
		static V m_summValue;
		static size_t m_minWidth;

	public:
		PairSummable()
		{

		}

		static const V& getInitialValue()
		{
			return m_summValue;
		}

		PairSummable(const K& key, const V& value) : Pair <K, V>(key, value)
		{
			if (m_minWidth < key.size())
			{
				m_minWidth = key.size();
			}
		}

		V sum(const K& key, const V& val) const
		{
			if (key == Pair<K, V>::key())
			{
				return Pair<K, V>::value() + val;
			}

			else
			{
				return val;
			}
		}

		void display(std::ostream& os) const
		{
			os.setf(std::ios::left);
			os.width(m_minWidth);
			Pair<K, V>::display(os);
			os.unsetf(std::ios::left);
		}

	};

	template<typename K, typename V>
	size_t PairSummable<K, V>::m_minWidth = 0;

	template<>
	std::string PairSummable<std::string, std::string>::m_summValue = "";

	template<>
	int PairSummable<std::string, int>::m_summValue = 0;

	template<>
	std::string PairSummable<std::string, std::string>::sum(const std::string& s1, const std::string& s2) const
	{
		if (key() == s1)
		{
			if (s2 == "")
			{
				return value();
			}

			else return s2 + ", " + value();
		}

		else return s2;
	}

	/*
	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
	*/
}

#endif