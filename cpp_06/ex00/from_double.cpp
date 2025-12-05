#include "from_double.hpp"

void double_to_char(double n)
{
	if (isnan(n) || isinf(n))
		std::cout<< "char: impossible"<<std::endl;
	else if (isascii(n))
		std::cout<< "char: '"<< static_cast<char>(n)<<"'"<<std::endl;
	else
		std::cout<< "char: Non displayable"<<std::endl;
}
void double_to_int(double n)
{
	if (n > INT_MAX || n < INT_MIN || isnan(n))
		std::cout<< "int: impossible"<<std::endl;
	else
		std::cout<< "int: "<< static_cast<int>(n)<<std::endl;
}
void double_to_float(double n, const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
	{
		std::cout<< "float: "<< static_cast<float>(n)<<"f"<<std::endl;
		return ;
	}
	int z = s.find('.');
	std::string sub = s.substr(z);

	if (sub != ".0")
		std::cout<< "float: "<< static_cast<float>(n)<<"f"<<std::endl;
	else
		std::cout<< "float: "<< static_cast<float>(n)<<".0f"<<std::endl;
}
void to_double(double d, const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
	{
		std::cout<< "double: "<< d <<std::endl;
		return ;
	}
	int z = s.find('.');
	std::string sub = s.substr(z);
	if (sub == ".0")
		std::cout<< "double: "<< d<<".0"<<std::endl;
	else
		std::cout<< "double: "<< d<<std::endl;
}