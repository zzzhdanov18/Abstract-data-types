#ifndef ARRAY_D_H
#define ARRAY_D_H
#include<cstddef>
class ArrayD
{
public:
	ArrayD() = default;
	ArrayD(const ArrayD& arr); // copy constructor
	ArrayD(const std::ptrdiff_t size); // array of the specified size
	ArrayD& operator=(const ArrayD& rhs); // assignment operator (total copy)
	~ArrayD() {delete[] data_;} // D-25T
	std::ptrdiff_t size() const { return size_;}
	float& operator[](const std::ptrdiff_t i); // accessing an array element
	const float& operator[](const std::ptrdiff_t i)const;
	void resize(const std::ptrdiff_t size); // resize
private:
    std::ptrdiff_t capacity_{0};
	std::ptrdiff_t size_{0};
	float* data_{nullptr};
};
#endif // ARRAY_D_H
