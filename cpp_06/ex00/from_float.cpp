#include "from_float.hpp"

void float_to_char(float n)
{
	if (isnan(n) || isinf(n))
		std::cout<< "char: impossible"<<std::endl;
	else if (isascii(n))
		std::cout<< "char: '"<< static_cast<char>(n)<<"'"<<std::endl;
	else
		std::cout<< "char: Non displayable"<<std::endl;
}
void float_to_int(float n)
{
	if (n > INT_MAX || n < INT_MIN || isnan(n))
		std::cout<< "int: impossible"<<std::endl;
	else
		std::cout<< "int: "<< static_cast<int>(n)<<std::endl;
}
void to_float(float f, const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
	{
		std::cout<< "float: "<< f<<"f"<<std::endl;
		return ;
	}
	int z = s.find('.');
	std::string sub = s.substr(z);
	if (sub == ".0f")
		std::cout<< "float: "<< f<<".0f"<<std::endl;
	else
		std::cout<< "float: "<< f<<"f"<<std::endl;
}
void float_to_double(float n, const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
	{
		std::cout<< "double: "<< static_cast<double>(n)<<std::endl;
		return ;
	}
	int z = s.find('.');
	std::string sub = s.substr(z);
	if (sub == ".0f")
		std::cout<< "double: "<< static_cast<double>(n)<<".0"<<std::endl;
	else
		std::cout<< "double: "<< static_cast<double>(n)<<std::endl;
}