#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	if (this != &other)
	{
		// Copy any necessary members here (if any)
	}
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		// Copy any necessary members here (if any)
	}
	return *this;
}
ScalarConverter::~ScalarConverter(){}

std::string get_type(const std::string &s)
{
	// Check for char
	if (s.length() == 1 && !isdigit(s[0]))
		return "char";
	// Check for int
	char* end;
	long int_val = strtol(s.c_str(), &end, 10);
	if (*end == '\0' && int_val >= INT_MIN && int_val <= INT_MAX)
		return "int";
	// Check for float
	char* endf;
	strtof(s.c_str(), &endf);
	if (*endf == 'f' && *(endf + 1) == '\0')
		return "float";
	// Check for double
	char* endd;
	strtod(s.c_str(), &endd);
	if (*endd == '\0')
		return "double";
	return "unknown";
}

void ScalarConverter::convert(const std::string &s)
{
	const std::string type = get_type(s);
	if (type == "char")
	{
		std::cout<< "char: '"<< s[0]<<"'" <<std::endl;
		char_to_int(s);
		char_to_float(s);
		char_to_double(s);
	}
	else if (type == "int")
	{
		char *end;
		int n = static_cast<int>(strtol(s.c_str(), &end, 10));
		int_to_char(n);
		std::cout<< "int: "<< n <<std::endl;
		int_to_float(n);
		int_to_double(n);
	}
	else if(type == "float")
	{
		char *end;
		float f = strtof(s.c_str(), &end);
		float_to_char(f);
		float_to_int(f);
		to_float(f, s);
		float_to_double(f, s);
	}
	else if(type == "double")
	{
		char *end;
		double d = strtod(s.c_str(), &end);
		double_to_char(d);
		double_to_int(d);
		double_to_float(d, s);
		to_double(d, s);
	}

}