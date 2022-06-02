#ifndef QUEUEA_QUEUEA_H
#define QUEUEA_QUEUEA_H
#include <cstddef>
#include <iostream>
class QueueA 
{
public:
	QueueA() = default;
	QueueA(const QueueA& q) = default;
	QueueA& operator=(const QueueA& q) = default;
	~QueueA() { delete[] data_; };
	void push(const float value);
	void pop();
	float& top();
	const float& top() const;
	bool is_empty() const;
private:
	std::ptrdiff_t capacity_{ 0 };
	std::ptrdiff_t i_head_{ -1 };
	std::ptrdiff_t i_tail_{ -1 };
	float* data_{ nullptr };
};
#endif
