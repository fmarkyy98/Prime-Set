#include <iostream>
#include<vector>
#include "PrimeSet.h"

using namespace std;

int main()
{
	PrimeSet ps1;

	vector<unsigned int> values{ 2,3,5,7,11,13 };
	PrimeSet ps2(values);

	ps1.add(2);
	ps1.add(3);
	ps1.add(5);
	ps1.add(7);
	ps1.add(11);
	cout << ps1 << endl;
	ps1.remove(5);
	cout << ps1 << endl;
	cout << ps2 << endl;
	ps2.erese();
	cout << ps2 << endl;

	cout << "Hello World!\n";
	return 0;
}
