#pragma once
#include <iostream>

class Orbital
{
public:
	Orbital(int n, int l, bool startFilled = true);
	int maxElectrons() const; // Maximum number of electrons for current subshell
	void addElectrons(int e);
	void removeElectrons(int e);
	friend bool operator<(const Orbital& a, const Orbital& b);
	friend bool operator>(const Orbital& a, const Orbital& b);
	friend std::ostream& operator<<(std::ostream& os, const Orbital& atom);
private:
	int n; // Principal quantum number
	int l; // Azimuthal quantum number
	int e; // Number of electrons
};