#include "Serializ.hpp"

Serializ::Serializ(){}
Serializ::Serializ(const Serializ &other)
{
    if (this != &other)
    {

    }
}
Serializ&  Serializ::operator=(const Serializ &other)
{
    if (this != &other)
	{
		
	}
	return *this;
}
Serializ::~Serializ(){}

uintptr_t  Serializ::serialize(Data* ptr)
{
    uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
    return result;
}
Data*  Serializ::deserialize(uintptr_t raw)
{
    Data* result = reinterpret_cast<Data*>(raw);
    return result;
}