#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::sign_form(Form& f)  const{
    try {
        f.be_signed(*this);
        std::cout << name << " signed " << f.get_name() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << f.get_name()
                  << " because " << e.what() << std::endl;
    }
}

// std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
// {
//     os << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade();
//     return os;
// }