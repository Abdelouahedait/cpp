#include "Identify.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* basePtr = generate();

    identify(basePtr);
    identify(*basePtr);

    delete basePtr;

    return 0;
}