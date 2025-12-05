#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string  name;
        bool is_signed;
         int grade_to_sign_it;
         int grade_to_execute_it;
    public:
        Form();
        ~Form();
        Form(std::string  name,  int _grade_to_sign_it,  int _grade_to_execute_it);
        Form(const Form &oth);
        Form &operator=(const Form &oth);

        std::string get_name();
        int get_grade_to_sign_it();
        int get_grade_to_execute_it();
        bool get_is_signed();

        void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Form  &b);