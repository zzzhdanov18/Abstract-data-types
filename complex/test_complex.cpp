#include<complex/complex.h>
#include<iostream>
#include<sstream>
#include<string>
int main()
{
	Complex z(13,1);
	Complex h(7, -6);
	std::cout << z << std::endl;
	std::cout << h << std::endl;
	Complex test;
	test = z + h;
	std::cout << test << std::endl;
	test = z - h;
	std::cout << test << std::endl;
	test = z * h;
	std::cout << test << std::endl;
	test = z / h;
	std::cout << test << std::endl;
	double tmp = 6;
	test = z + tmp;
	std::cout << test << std::endl;
	test = tmp - h;
	std::cout << test << std::endl;
	test = tmp * h;
	std::cout << test << std::endl;
	test = tmp / h;
	std::cout << test << std::endl;

}
