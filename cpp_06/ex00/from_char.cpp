#include "from_char.hpp"

void char_to_int(const std::string &s)
{
	char c = s[0];
	std::cout<< "int: "<< static_cast<int>(c)<<std::endl;
}

void char_to_float(const std::string &s)
{
	char c = s[0];
	std::cout<< "float: "<< static_cast<float>(c)<<".0f"<<std::endl;
}
void char_to_double(const std::string &s)
{
	char c = s[0];
	std::cout<< "double: "<< static_cast<double>(c)<<".0"<<std::endl;
}