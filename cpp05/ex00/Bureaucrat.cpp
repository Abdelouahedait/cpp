#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < highest_grade)
        throw Bureaucrat::GradeTooHighException();
    if (grade > lowest_grade)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // name is const, so we don't assign it
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::get_name() const
{
    return name;
}


int Bureaucrat::get_grade() const
{
    return grade;
}

void Bureaucrat::increment_grade()
{
    if (grade <= highest_grade)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}


void Bureaucrat::decrement_grade()
{
    if (grade >= lowest_grade)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}
