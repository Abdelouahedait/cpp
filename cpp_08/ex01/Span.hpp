#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
    private:
        std::vector<unsigned int> N;
    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(unsigned int N);
        unsigned int shortestSpan();
        unsigned int longestSpan();

    template <typename T>
    void addNumbers(T begin, T end)
    {
        for (T it = begin; it != end; ++it)
        {
            if (this->N.size() >= this->N.capacity())
                throw std::out_of_range("Span is full");
            this->N.push_back(*it);
        }
    }
};