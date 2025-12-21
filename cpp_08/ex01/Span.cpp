#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->N.reserve(N);
}
Span::Span(const Span &other)
{
    this->N = other.N;
}
Span &Span::operator=(const Span &other)
{
    if (this != &other)
        this->N = other.N;
    return *this;
}
Span::~Span(){}

void Span::addNumber(unsigned int N)
{
    if (this->N.size() >= this->N.capacity())
        throw std::out_of_range("Span is full");
    this->N.push_back(N);
}
unsigned int Span::shortestSpan()
{
    if (this->N.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    std::vector<unsigned int> sort_span = this->N;
    std::sort(sort_span.begin(), sort_span.end());
    unsigned int min_span = UINT_MAX;
    for (unsigned int i = 0; i < sort_span.size() - 1; i++)
    {
        unsigned int span = sort_span[i + 1] - sort_span[i];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}
unsigned int Span::longestSpan()
{
    if (this->N.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<unsigned int> sortedN = this->N;
    std::sort(sortedN.begin(), sortedN.end());

    return sortedN.back() - sortedN.front();
}