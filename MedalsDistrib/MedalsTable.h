#pragma once
#include <iostream>
#include <cassert>
#include "MedalRow.h"
using namespace std;

class MedalsTable
{
public:
	static const int maxSize{ 10 };
private:
	MedalRow medalRows[MedalsTable::maxSize];
	int size;
	int findCountry(const char* country)const
	{
		for (int i{ 0 }; i < size; ++i)
		{
			if (strcmp(medalRows[i].getCountry(),
				country) == 0)
			{
				return i;
			}
		}
		return -1;
	}
public:
	MedalsTable() : size{ 0 } {};
	MedalRow& operator[](const char* country)
	{
		int idx{ findCountry(country) };
		if (idx == -1)
		{
			assert(size < MedalsTable::maxSize and
				"Table is FULL!");
			idx = size++;
			medalRows[idx].setCountry(country);
		}
		return medalRows[idx];
	}
	const MedalRow& operator[](const char* country)const
	{
		int idx{ findCountry(country) };
		assert(idx != -1 and "Country not found on const "
			"table");
		return medalRows[idx];
	}
	void print()const
	{
		for (int i{ 0 }; i < size; ++i)
		{
			medalRows[i].print();
		}
	}
};

