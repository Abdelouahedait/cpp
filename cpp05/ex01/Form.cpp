#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed_(false),
      grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
}



Form::Form(const Form &other)
    : name(other.name),
      is_signed_(other.is_signed_),
      grade_to_sign(other.grade_to_sign),
      grade_to_execute(other.grade_to_execute)
{}



Form& Form::operator=(const Form& other) 
{
    if (this != &other) 
    {
        // name, grade_to_sign, and grade_to_execute are const, so we don't assign them
        is_signed_ = other.is_signed_;
    }
    return *this;
}
Form::~Form() {}

void Form::be_signed(const Bureaucrat& bureaucrat_) 
{
    if (bureaucrat_.get_grade() > grade_to_sign)
        throw Form::GradeTooLowException();
    is_signed_ = true;
}
const std::string& Form::get_name() const 
{
    return name;
}
bool Form::is_signed() const 
{
    return is_signed_;
}
int Form::get_grade_to_sign() const 
{
    return grade_to_sign;
}
int Form::get_grade_to_execute() const 
{
    return grade_to_execute;
}
const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form grade too high";
}
const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form grade too low";
}