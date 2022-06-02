#include<complex/complex.h>
#include<iostream>
#include<limits>
#include<stdexcept>

Complex::Complex(const double real) : Complex(real, 0.0) {}

Complex::Complex(const double re, const double im) : re(re), im(im) {}

bool Complex::operator==(const Complex& rhs) const noexcept
{
    return std::abs(rhs.re - re) < 2 * std::numeric_limits<double>::epsilon() &&
        std::abs(rhs.im - im) < 2 * std::numeric_limits<double>::epsilon();
}

Complex& Complex::operator+=(const Complex& rhs) noexcept 
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept 
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept 
{
    double rc = re;
    re = re * rhs.re - im * rhs.im;
    im = im * rhs.re + rhs.im * rc;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) 
{
    double denum = rhs.re * rhs.re + rhs.im * rhs.im;
    if (denum < 2 * std::numeric_limits<double>::epsilon()) 
    {
        throw std::invalid_argument("Deviding by 0");
    }
    double re_num = this->re * rhs.re + this->im * rhs.im;
    double im_num = rhs.re * this->im - this->re * rhs.im;
    *this = Complex(re_num / denum, im_num / denum);
    return *this;
}

Complex& Complex::operator/=(const double rhs) 
{
    if (std::abs(rhs) < 2 * std::numeric_limits<double>::epsilon()) 
    {
        throw std::invalid_argument("Deviding by 0");
    }
    re /= rhs;
    im /= rhs;
    return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const 
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) 
{
    char leftBrace;
    double real;
    char comma;
    double imaginary;
    char rightBrace;
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good()) {
        if (Complex::rightBrace == rightBrace && Complex::leftBrace == leftBrace && Complex::separator == comma) {
            re = real;
            im = imaginary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) 
{
    return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) 
{
    return rhs.readFrom(istrm);
}
