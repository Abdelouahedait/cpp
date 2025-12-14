#include "from_int.hpp"

void int_to_char(int n)
{
	if (isascii(n))
		std::cout<< "char: '"<< static_cast<char>(n)<<"'"<<std::endl;
	else
		std::cout<< "char: Non displayable"<<std::endl;
}
void int_to_float(int n)
{
	std::cout<< "float: "<< static_cast<float>(n)<<".0f"<<std::endl;
}
void int_to_double(int n)
{
	std::cout<< "double: "<< static_cast<double>(n)<<".0"<<std::endl;
}