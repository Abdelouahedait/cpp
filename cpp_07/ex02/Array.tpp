#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->_data = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other)
{
     this->_data = new T[other.size()];
    for (unsigned int i = 0; i < other.size(); i++)
         this->_data[i] = other._data[i];
}

template <typename T>
Array<T> & Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->_data;
        this->_data = new T[other.size()];
        for (unsigned int i = 0; i < other.size(); i++)
            this->_data[i] = other._data[i];
    }
    return *this;

}

template <typename T>
T&  Array<T>::operator[](unsigned int index)
{
    if (index >= size())
        throw std::out_of_range("Index out of range");
    return this->_data[index];

}

template <typename T>
const T&Array<T>::operator[](unsigned int index)const
{
    if (index >= size())
        throw std::out_of_range("Index out of range");
    return this->_data[index];
}  

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_data;
}