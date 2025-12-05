#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade < 1)
        throw GradeTooHighException();
    grade = _grade;
} 

Bureaucrat::Bureaucrat(const Bureaucrat &oth)
{
    *this = oth;
    std::cout << "copy constructor called"<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &oth)
{
    if (this != &oth)
        this->grade = oth.grade;
    std::cout << "copy assignment operator called"<< std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b)
{
    os << b.getName()<< ", Bureaucrat grade "<< b.getGrade()<<std::endl;
    return os;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called"<< std::endl;
}


std::string Bureaucrat::getName()const
{
    return this->name;
}

int Bureaucrat::getGrade()const
{
    return this->grade;
}

void Bureaucrat::increment_grade()
{

    if (grade == 1)
        throw GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrement_grade()
{
    if (grade == 150)
        throw GradeTooLowException();
    else
        grade++;
}

void Bureaucrat::signForm(Form &f)
{
    try{
        f.beSigned(*this);
    }
    catch(const std::exception& e)
	{
	    std::cerr <<e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}
