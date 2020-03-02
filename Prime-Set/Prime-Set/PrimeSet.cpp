#include <iostream>
#include <vector>
#include <cmath>
#include "PrimeSet.h"

PrimeSet::PrimeSet() : _n(1) { }
PrimeSet::PrimeSet(std::vector<unsigned int>& items) : _n(1)
{
	for (size_t i = 0; i < items.size(); ++i)
	{
		add(items[i]);
	}
}

bool PrimeSet::empty() const
{
	bool result = this->_n == 1;
	return result;
}

bool PrimeSet::contains(unsigned int item) const
{
	bool result = this->_n % item == 0;
	return result;
}

void PrimeSet::erese()
{
	this->_n = 1;
}

void PrimeSet::add(unsigned int item)
{
	if (!this->contains(item))
	{
		bool isPrime = true;
		for (size_t i = 2; isPrime && i < sqrt((double)item); ++i)
		{
			if (item % i == 0)
			{
				isPrime = false;
			}
		}
		if (isPrime)
		{
			this->_n *= item;
		}
	}
}

void PrimeSet::remove(unsigned int item)
{
	if (this->contains(item))
	{
		this->_n /= item;
	}
}

std::ostream& operator << (std::ostream& os, const PrimeSet& ps)
{
	os << "[";
	PrimeSet l_ps = ps;
	unsigned int i = 2;
	bool printedAlredy = false;
	while (!l_ps.empty())
	{
		if (l_ps.contains(i))
		{
			if (printedAlredy)
			{
				os << "," << i;
			}
			else
			{
				os << i;
				printedAlredy = true;
			}
			l_ps.remove(i);
		}
		++i;
	}
	os << "]";
	return os;
}
