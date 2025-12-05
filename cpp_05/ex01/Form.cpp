#include "Form.hpp"

Form::Form()
{
    std::cout << "default constructor called"<< std::endl;
}


Form::Form( std::string  name,  int _grade_to_sign_it,  int _grade_to_execute_it) : name(name)
{
    if (_grade_to_sign_it > 150 || _grade_to_execute_it  > 150)
        throw GradeTooLowException();
    else if (_grade_to_sign_it < 1 || _grade_to_execute_it < 1)
        throw GradeTooHighException();
    grade_to_sign_it = _grade_to_sign_it;
    grade_to_execute_it = _grade_to_execute_it;
    is_signed = 0;
}

Form::Form(const Form &oth)
{
    *this = oth;
    std::cout << "copy constructor called"<< std::endl;

}

Form &Form::operator=(const Form &oth)
{
    if (this != &oth)
    {
        this->grade_to_sign_it = oth.grade_to_sign_it;
        this->grade_to_execute_it = oth.grade_to_execute_it;
    }
    std::cout << "copy assignment operator called"<< std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "destructor called"<< std::endl;
}

std::ostream &operator<<(std::ostream &os, Form &b)
{
    os << b.get_name()<< ", Form grade_to_sign_it = "<< b.get_grade_to_sign_it()<< ", grade_to_sign_it = "<< b.get_grade_to_sign_it()<<std::endl;
    return os;
}

std::string Form::get_name()
{
    return this->name;
}

int Form::get_grade_to_sign_it()
{
    return this->grade_to_sign_it;
}

int Form::get_grade_to_execute_it()
{
    return this->grade_to_execute_it;
}
bool Form::get_is_signed()
{
    return this->is_signed;
}

void Form::beSigned(const Bureaucrat &b)
{
    
    
    if (b.getGrade() <= grade_to_sign_it && is_signed == 0)
    {
        is_signed = 1;
        std::cout <<b.getName()<< " sina " << name<<std::endl;
    }
    else if (grade_to_sign_it < b.getGrade())
    {
    std::cout <<b.getName()<< " ma9drch isini " <<name<< ", hitach ";
        throw GradeTooLowException();
    }
    else if (is_signed == 1)
    {
        std::cout <<b.getName()<< " ma9drch isini " <<name<< ", hitach msinya" <<std::endl;
    }
}

const char *Form::GradeTooHighException::what()const throw()
{
    return "Grade too high! --FORM--";
}

const char *Form::GradeTooLowException::what()const throw()
{
    return "Grade too low! --FORM--";
}