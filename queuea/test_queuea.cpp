#include<iostream>
#include<queuea/queuea.h>
int main()
{
	QueueA test;
	test.push(2);
	test.push(3);
	std::cout << test.top() << std::endl;
}
