#pragma once

// #include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>


class Bureaucrat;

class  Form 
{
    private:
        std::string name;
        bool is_signed_;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        Form(const std::string& name, int grade_to_sign, int grade_to_execute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        void be_signed(const Bureaucrat& bureaucrat_);
        const std::string& get_name() const;
        bool is_signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_execute() const;
        
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

