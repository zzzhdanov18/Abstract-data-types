#ifndef RATIONAL_RATIONAL_20201007
#define RATIONAL_RATIONAL_20201007

#include <iosfwd>

class Rational {
public:
    Rational() = default;
    Rational(const Rational& rhs) = default;
    Rational& operator=(const Rational& rhs) = default;
    explicit Rational(const int num, const int den = 1);
    ~Rational() = default;
    int num() const noexcept { return numer; }
    int denum() const noexcept { return denom; }
    Rational operator-() const noexcept { return Rational(-numer, denom); }
    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator/=(const Rational& rhs);
    Rational& operator+=(const int rhs) noexcept { return operator+=(Rational(rhs)); }
    Rational& operator-=(const int rhs) noexcept { return operator-=(Rational(rhs)); }
    Rational& operator*=(const int rhs) noexcept { return operator*=(Rational(rhs)); }
    Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }
    bool operator==(const Rational& rhs) const noexcept { return numer == rhs.numer && denom == rhs.denom; }
    bool operator!=(const Rational& rhs) const noexcept { return !operator==(rhs); }
    bool operator==(const int rhs) const noexcept { return operator==(Rational(rhs)); }
    bool operator!=(const int rhs) const noexcept { return !operator==(rhs); }
    bool operator>(const Rational& rhs) const noexcept;
    bool operator<(const Rational& rhs) const noexcept;
    bool operator<=(const Rational& rhs) const noexcept { return !operator>(rhs); }
    bool operator>=(const Rational& rhs) const noexcept { return !operator<(rhs); }
    bool operator>(const int rhs) const noexcept { return operator>(Rational(rhs)); }
    bool operator<(const int rhs) const noexcept { return operator<(Rational(rhs)); }
    bool operator<=(const int rhs) const noexcept { return !operator>(rhs); }
    bool operator>=(const int rhs) const noexcept { return !operator<(rhs); }
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
private:
    int numer  = 0;
    int denom = 0;
    static const char separator{ '/' };
    int Norm (int a1, int a2) const noexcept;
};
inline bool operator==(const int lhs, const Rational& rhs) noexcept { return rhs.operator==(lhs); }
inline bool operator!=(const int lhs, const Rational& rhs) noexcept { return rhs.operator!=(lhs); }
inline bool operator>(const int lhs, const Rational& rhs) noexcept { return rhs.operator<(lhs); }
inline bool operator<(const int lhs, const Rational& rhs) noexcept { return rhs.operator>(lhs); }
inline bool operator>=(const int lhs, const Rational& rhs) noexcept { return rhs.operator<=(lhs); }
inline bool operator<=(const int lhs, const Rational& rhs) noexcept { return rhs.operator>=(lhs); }
inline Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) += rhs; }
inline Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) -= rhs; }
inline Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) *= rhs; }
inline Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }
inline Rational operator+(const int lhs, const Rational& rhs) noexcept { return Rational(lhs) += rhs; }
inline Rational operator-(const int lhs, const Rational& rhs) noexcept { return Rational(lhs) -= rhs; }
inline Rational operator*(const int lhs, const Rational& rhs) noexcept { return Rational(lhs) *= rhs; }
inline Rational operator/(const int lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }
inline Rational operator+(const Rational& lhs, const int rhs) noexcept { return Rational(lhs) += rhs; }
inline Rational operator-(const Rational& lhs, const int rhs) noexcept { return Rational(lhs) -= rhs; }
inline Rational operator*(const Rational& lhs, const int rhs) noexcept { return Rational(lhs) *= rhs; }
inline Rational operator/(const Rational& lhs, const int rhs) { return Rational(lhs) /= rhs; }

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) 
{
    return rhs.readFrom(istrm);
}
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) 
{
    return rhs.writeTo(ostrm);
}
#endif 
