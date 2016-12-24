#include"Tuple.h"
#include<iostream>

int main()
{
	// create and use tuple with only one field
	Tuple<int> t1;
	val<1>(t1) += 42;
	std::cout << t1.v1() << std::endl;

	// create and use duo
	Tuple<bool, int> t2;
	std::cout << val<1>(t2) << ", ";
	std::cout << t2.v1() << std::endl;

	// create and use triple
	Tuple<bool, int, double> t3;

	val<1>(t3) = true;
	val<2>(t3) = 42;
	val<3>(t3) = 0.2;

	std::cout << val<1>(t3) << ", ";
	std::cout << val<2>(t3) << ", ";
	std::cout << val<3>(t3) << std::endl;

	t3 = MakeTuple(false, 23, 13.13);

	std::cout << val<1>(t3) << ", ";
	std::cout << val<2>(t3) << ", ";
	std::cout << val<3>(t3) << std::endl;

	// create and use quadruple
	Tuple<bool, int, float, double> t4(true, 42, 13, 1.95583);
	std::cout << val<4>(t4) << std::endl;
	std::cout << t4.v2().v2().v2() << std::endl;
}