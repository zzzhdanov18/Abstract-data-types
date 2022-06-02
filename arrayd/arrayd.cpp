#include <arrayd/arrayd.h>
#include <iostream>
#include <stdexcept>

ArrayD::ArrayD(const ArrayD& arr) 
{
	capacity_ = 2 * arr.size() + 1;
	size_ = arr.size();
	delete[] data_;
	data_ = new float[capacity_];
	for (ptrdiff_t i = 0; i < size_; ++i) 
		*(data_ + i) = arr[i];
}

ArrayD& ArrayD::operator=(const ArrayD& arr) 
{
	if (capacity_ >= arr.size()) 
	{
		size_ = arr.size();
		for (ptrdiff_t i = 0; i < size_; ++i) *(data_ + i) = arr[i];
	}
	else 
	{
		capacity_ = 2 * arr.size() + 1;
		size_ = arr.size();
		delete[] data_;
		data_ = new float[capacity_];
		for (ptrdiff_t i = 0; i < size_; ++i) 
			*(data_ + i) = arr[i];
	}
	return *this;
}

ArrayD::ArrayD(const std::ptrdiff_t size) 
{
	if (size < 0) 
		throw std::logic_error("Error size");
	capacity_ = 2 * size + 1;
	size_ = size;
	data_ = new float[capacity_];
	for (ptrdiff_t i = 0; i < size_; ++i) 
		*(data_ + i) = 0.0f;
}

void ArrayD::resize(const std::ptrdiff_t size) 
{
	if (size < 0) 
		throw std::logic_error("Error size");
	if (size > capacity_) 
	{
		float* temp = new float[size_];
		for (ptrdiff_t i = 0; i < size_; ++i) 
			*(temp + i) = *(data_ + i);
		delete[] data_;
		capacity_ = 2 * size;
		data_ = new float[capacity_];
		for (ptrdiff_t i = 0; i < size_; ++i) 
			*(data_ + i) = *(temp + i);
		delete[] temp;
	}
	for (ptrdiff_t i = size_; i < size; ++i) 
		*(data_ + i) = 0.0f;
	size_ = size;
}

const float& ArrayD::operator[](const std::ptrdiff_t i) const 
{
	if (i < 0 || i >= size_) 
		throw std::out_of_range("Error size");
	return *(data_ + i);
}

float& ArrayD::operator[](const std::ptrdiff_t i) 
{
	if (i < 0 || i >= size_) 
		throw std::out_of_range("Error size");
	return *(data_ + i);
}
