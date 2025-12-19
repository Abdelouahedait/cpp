#include "easyfind.hpp"

template <typename T>
bool easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    return (it != container.end());
}