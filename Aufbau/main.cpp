/*
Aufbau: prints out electronic configuration for a given number of electrons according to the Aufbau principle (doesn't account for exceptions)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "Orbital.h"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Please enter an atomic number" << std::endl;
		return 1;
	}
	std::vector<Orbital> orbitals;
	// Quantity of subshells in a shell is equal to it's number
	for (int n = 1; n <= 9; ++n)
	{
		for (int l = 0; l < n; ++l)
		{
			orbitals.push_back(Orbital(n, l, false));
		}
	}
	std::sort(orbitals.begin(), orbitals.end());
	std::vector<Orbital> atomOrbitals;
	int electronsAssigned = 0;
	int atomicNumber = atoi(argv[1]); // First argument
	for (auto s : orbitals)
	{
		if (electronsAssigned < atomicNumber)
		{
			Orbital orbital = s;
			// Fill with the maximum of electrons possible
			int electronsAdded = std::min(atomicNumber - electronsAssigned, orbital.maxElectrons());
			orbital.addElectrons(electronsAdded);
			atomOrbitals.push_back(orbital);
			electronsAssigned += electronsAdded;
		}
	}
	for (auto s : atomOrbitals)
		std::cout << s << " ";
	return 0;
}