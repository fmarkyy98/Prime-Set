#pragma once

#include <iostream>
#include<vector>

class PrimeSet
{
private:
	unsigned long long _n;

public:
	PrimeSet();
	PrimeSet(std::vector<unsigned int>& items);

	bool empty() const;
	bool contains(unsigned int item) const;
	void erese();
	void add(unsigned int item);
	void remove(unsigned int item);
	friend std::ostream& operator << (std::ostream& os, const PrimeSet& ps);
};

