#include <rational/rational.h>
#include <stdexcept>
#include <iostream>

Rational::Rational(const int num, const int den) : numer(num), denom(den) 
{
	if (denom == 0) throw std::invalid_argument("Den == 0");
	int g = Norm(numer, denom);
	numer /= g;
	denom /= g;
	if (numer* denom < 0 && denom < 0) 
	{
		numer *= -1;
		denom *= -1;
	}
}

Rational& Rational::operator+=(const Rational& rhs) noexcept 
{
	int g = Norm(denom, rhs.denom);
	int l = denom * rhs.denom / g;
	int a = l / denom;
	int b = l / rhs.denom;
	*this = Rational(numer * a + rhs.numer * b, l);
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept 
{
	int g = Norm(denom, rhs.denom);
	int l = denom * rhs.denom / g;
	int a = l / denom;
	int b = l / rhs.denom;
	*this = Rational(numer * a - rhs.numer * b, l);
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept 
{
	*this = Rational(numer * rhs.numer, denom * rhs.denom);
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) 
{
	if (rhs.numer == 0) throw std::invalid_argument("Error (0)");
	*this = Rational(numer * rhs.denom, denom * rhs.numer);
	return *this;
}
bool Rational::operator>(const Rational& rhs) const noexcept
{
	if (numer* rhs.numer < 0) return numer > 0;
	return numer * rhs.denom > rhs.numer * denom;
}

bool Rational::operator<(const Rational& rhs) const noexcept
{
	if (numer * rhs.numer < 0) return numer < 0;
	return numer * rhs.denom < rhs.numer* denom;
}
int Rational::Norm(int a, int b) const noexcept 
{
	if (b == 0) return a;
	return Norm(b, a % b);
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const 
{
	ostrm << numer << "/" << denom;
	return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm) 
{
	int num;
	char slash;
	int den;
	istrm >> num;
	istrm.get(slash);
	char c = istrm.peek();
	istrm >> den;
	if (istrm.eof()) {
		if (Rational::separator == slash && den > 0 && c >= '0' && c <= '9') 
		{
			*this = Rational(num, den);
		}
		else 
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	else 
	{
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}
