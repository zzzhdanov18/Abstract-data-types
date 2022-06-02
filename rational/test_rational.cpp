#include<rational/rational.h>
#include<iostream>
#include<sstream>

int main()
{
	Rational z(1, 5); Rational a(2, 5);
	Rational mem;
	mem = z * a;
	std :: cout << mem << std::endl;
	mem = z - a;
	std::cout << mem << std::endl;
	mem = z + a;
	std::cout << mem << std::endl;
	mem = z / a;
	std::cout << mem << std::endl;
	mem = z + 5;
	std::cout << mem << std::endl;
	mem = z - 5;
	std::cout << mem << std::endl;
	mem = z * 5;
	std::cout << mem << std::endl;
	mem = z / 5;
	std::cout << mem << std::endl;
	mem = 5 + z;
	std::cout << mem << std::endl;
	mem = 5 - z;
	std::cout << mem << std::endl;
	mem = 5 * z;
	std::cout << mem << std::endl;
	mem = 5 / z;
	std::cout << mem << std::endl;
	bool test = false;
	test = z > a;
	std::cout << test << std::endl;
	test = z >= a;
	std::cout << test << std::endl;
	test = z == a;
	std::cout << test << std::endl;
	test = z > 5;
	std::cout << test << std::endl;
	test = z == 5;
	std::cout << test << std::endl;
	test = z < 5;
	std::cout << test << std::endl;
	test = z != 5;
	std::cout << test << std::endl;
}
