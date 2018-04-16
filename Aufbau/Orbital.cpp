#include "Orbital.h"

char subshells[7] = { 's', 'p', 'd', 'f', 'g', 'h', 'i' };

Orbital::Orbital(int n, int l, bool startFilled)
	:n{n}, l{l}
{
	if (startFilled)
		this->e = this->maxElectrons();
	else
		this->e = 0;
}

/*
 * This function uses the formula En = 2 + (l - 1) * 4, derivated from an
 * arithmetic progression. We don't actually subtract one from l, since
 * the azimuthal number is already "l - 1"
 */
int Orbital::maxElectrons() const
{
	return 2 + l * 4;
}

void Orbital::addElectrons(int e)
{
	int after = this->e + e;
	if (after <= this->maxElectrons())
		this->e = after;
}

void Orbital::removeElectrons(int e)
{
	int after = this->e - e;
	if (after >= 0)
		this->e = after;
}

bool operator<(const Orbital& a, const Orbital& b)
{
	int sa = (a.n + a.l);
	int sb = (b.n + b.l);
	if (sa == sb)
		return a.n < b.n;
	return sa < sb;
}

bool operator>(const Orbital& a, const Orbital& b)
{
	int sa = (a.n + a.l);
	int sb = (b.n + b.l);
	if (sa == sb)
		return a.n > b.n;
	return sa > sb;
}

std::ostream& operator<<(std::ostream& os, const Orbital& atom)
{
	os << atom.n << subshells[atom.l] << atom.e;
	return os;
}
