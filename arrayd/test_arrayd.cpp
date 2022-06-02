#include<arrayd/arrayd.h>
#include<iostream>
#include<sstream>

int main()
{
	ArrayD test(5);
	for (int i = 0; i < test.size(); i++)
		test[i] = i;
	for (int i = 0; i < test.size(); i++)
		std::cout << test[i] << std::endl;
	std::cout << "-------------------------" << std::endl;
	test.resize(7);
	std::cout << test.size() << std::endl;
	for (int i = 0; i < test.size(); i++)
		std::cout << test[i] << std::endl;
	std::cout << "-------------------------" << std::endl;
	test.resize(8);
	std::cout << test.size() << std::endl;
	for (int i = 0; i < test.size(); i++)
		std::cout << test[i] << std::endl;
}
