#ifndef COMPLEX_COMPLEX_H_20201007
#define COMPLEX_COMPLEX_H_20201007
#include<iosfwd>
struct Complex{
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real,const double imaginary);
	~Complex()=default;
	Complex& operator=(const Complex& com) = default;
	bool operator==(const Complex& rhs) const noexcept;
	bool operator!=(const Complex& rhs) const noexcept{return!operator==(rhs); }
	Complex operator-()noexcept{return Complex(-re,-im);  }
	Complex& operator+=(const Complex&rhs)noexcept;
	Complex& operator+=(const double rhs)noexcept{return operator+=(Complex(rhs));}
	Complex& operator-=(const Complex& rhs)noexcept;
	Complex& operator-=(const double rhs)noexcept{return operator-=(Complex(rhs));}
	Complex& operator*=(const Complex& rhs)noexcept;
	Complex& operator*=(const double rhs)noexcept { return operator*=(Complex(rhs)); };
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	
	double re{0.0};
	double im{0.0};
	static const char leftBrace{'{'};
	static const char separator{','};
	static const char rightBrace{'}'};
};
inline Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
inline Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
inline Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
inline Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
inline Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
inline Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
inline Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
inline Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
inline Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
inline Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
inline Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
inline Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
std::ostream& operator<<(std::ostream &ostrm,const Complex& rhs);
std::istream& operator>>(std::istream &istrm, Complex rhs);
#endif// COMPLEX_COMPLEX_H_20201007
