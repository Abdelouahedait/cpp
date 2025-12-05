#pragma once

#include "from_int.hpp"
#include "from_char.hpp"
#include "from_float.hpp"
#include "from_double.hpp"

class ScalarConverter
{
    private:
        ScalarConverter();
        public:
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
        static void convert(const std::string &s);

};