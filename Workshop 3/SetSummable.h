// Name: Marco Chan
// Seneca Student ID: 152215182
// Seneca email: mchan107@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include "Set.h"
#include "PairSummable.h"

using namespace std;

namespace sdds
{
	template <typename T, int N, typename K, typename V>

	class SetSummable : public Set <T, N>
	{
	public:
		V accumulate(const K& key) const
		{
			Set<T, N>& temp = (Set <T, N>&)*this;
			PairSummable<K, V> summ;
			V result = summ.getInitialValue();

			for (size_t i = 0; i < temp.size(); i++)
			{

				if (key == temp[i].key())
				{
					result = temp[i].sum(key, result);
				}
			}

			return result;
		}
	};
}

#endif