#include "Serializ.hpp"

int main()
{
    Data data;
    data.n = 42;
    data.str = "Hello, World!";

    uintptr_t raw = Serializ::serialize(&data);
    Data* deserializedData = Serializ::deserialize(raw);

    std::cout << "Original Data: n = " << data.n << ", str = " << data.str << std::endl;
    std::cout << "Deserialized Data: n = " << deserializedData->n << ", str = " << deserializedData->str << std::endl;
    std::cout << "Addresses: Original = " << &data << ", Deserialized = " << deserializedData << std::endl;
    return 0;
}