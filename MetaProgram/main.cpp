#include"sqrt1.h"
#include<iostream>

int main()
{
	std::cout << "Sqrt<16>::result = " << Sqrt<16>::result << std::endl;
	std::cout << "Sqrt<25>::result = " << Sqrt<25>::result << std::endl;
	std::cout << "Sqrt<42>::result = " << Sqrt<42>::result << std::endl;
	std::cout << "Sqrt<1>::result = " << Sqrt<1>::result << std::endl;
	system("PAUSE");
	return 0;
}