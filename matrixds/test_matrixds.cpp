#include <iostream>
#include <matrixds/matrixds.h>
void print(MatrixDs rhs)
{
	for (int i = 0; i < rhs.rowCount(); ++i)
	{
		for (int j = 0; j < rhs.colCount(); ++j)
		{
			std::cout << rhs.at(i, j) << " ";
		}
		std::cout << std::endl;
	}
}
int main() 
{
	MatrixDs test(3, 3);
	test.at(0, 0) = 1;
	test.at(0, 1) = 2; 
	test.at(0, 2) = 3;

	test.at(1, 0) = 3;
	test.at(1, 1) = 4;
	test.at(1, 2) = 5;

	test.at(2, 0) = 8;
	test.at(2, 1) = 1;
	test.at(2, 2) = 9;

	print(test);
	test.transpose();
	std::cout << "-------------------------------------" << std::endl;
	print(test);
	MatrixDs test_2 = test;
	test_2.multiply(test);
	std::cout << "-------------------------------------" << std::endl;
	print(test_2);
	std::cout << "-------------------------------------" << std::endl;
	test.swapColumns(1,2);
	print(test);
	std::cout << "-------------------------------------" << std::endl;
	test.swapRows(0, 1);
	print(test);
	std::cout << "-------------------------------------" << std::endl;
	std::cout << test.at(1, 1) << std::endl;
}
