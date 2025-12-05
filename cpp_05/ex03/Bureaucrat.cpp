#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "default constructor called"<< std::endl;
}
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
    std::cout << "Bureaucrat destructor called"<< std::endl;
}

std::string Bureaucrat::getName()const
{
    return this->name;
}

int Bureaucrat::getGrade()const
{
    return this->grade;
}

void Bureaucrat::signForm(AForm &f) const
{
    try{
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.get_name() << std::endl;
    }
    catch(const std::exception& e)
	{
	    std::cerr <<e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout<< "can't execute " << form.get_name() << " because " << e.what() << std::endl;
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
