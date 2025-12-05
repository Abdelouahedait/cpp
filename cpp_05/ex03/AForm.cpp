#include "AForm.hpp"

AForm::AForm()
{
    std::cout << "default constructor called"<< std::endl;
}
AForm::AForm( std::string  name,  int _grade_to_sign_it,  int _grade_to_execute_it) : name(name)
{
    if (_grade_to_sign_it > 150 || _grade_to_execute_it  > 150)
        throw GradeTooLowException();
    else if (_grade_to_sign_it < 1 || _grade_to_execute_it < 1)
        throw GradeTooHighException();
    grade_to_sign_it = _grade_to_sign_it;
    grade_to_execute_it = _grade_to_execute_it;
    is_signed = 0;
}
AForm::AForm(const AForm &oth)
{
    *this = oth;
    std::cout << "copy constructor called"<< std::endl;

}
AForm &AForm::operator=(const AForm &oth)
{
    if (this != &oth)
    {
        this->grade_to_sign_it = oth.grade_to_sign_it;
        this->grade_to_execute_it = oth.grade_to_execute_it;
    }
    std::cout << "copy assignment operator called"<< std::endl;
    return *this;
}
AForm::~AForm()
{
    std::cout << "AForm destructor called"<< std::endl;
}

// std::ostream &operator<<(std::ostream &os, AForm &b)
// {
//     os << b.get_name()<< ", AForm grade_to_sign_it = "<< b.get_grade_to_sign_it()<< ", grade_to_sign_it = "<< b.get_grade_to_sign_it()<<std::endl;
//     return os;
// }

std::string AForm::get_name()const
{
    return this->name;
}

int AForm::get_grade_to_sign_it()const
{
    return this->grade_to_sign_it;
}

int AForm::get_grade_to_execute_it()const
{
    return this->grade_to_execute_it;
}
bool AForm::get_is_signed()const
{
    return this->is_signed;
}
void AForm::set_is_signed(bool status) 
{
    this->is_signed = status;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > grade_to_sign_it)
    {
        throw AForm::GradeTooLowException();
    }
    set_is_signed(true);
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!is_signed)
        throw AForm::FormNotSignedException();
    if(grade_to_execute_it < executor.getGrade() )
        throw AForm::GradeTooLowException();
}
const char *AForm::GradeTooHighException::what()const throw()
{
    return "Grade too high! --AFORM--";
}

const char *AForm::GradeTooLowException::what()const throw()
{
    return "Grade too low! --AFORM--";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed!";
}