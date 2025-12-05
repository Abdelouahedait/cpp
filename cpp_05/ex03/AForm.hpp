#pragma once 
#include <iostream>
#include <string>
#include <ctime>
#include "Bureaucrat.hpp"


class Bureaucrat;
class AForm
{
    private:
        const std::string  name;
        bool is_signed;
         int grade_to_sign_it;
         int grade_to_execute_it;
    public:
        AForm();
        virtual ~AForm();
        AForm(std::string  name,  int _grade_to_sign_it,  int _grade_to_execute_it);
        AForm(const AForm &oth);
        AForm &operator=(const AForm &oth);

        std::string get_name()const;
        int get_grade_to_sign_it()const;
        int get_grade_to_execute_it()const;
        bool get_is_signed()const;

        void set_is_signed(bool status) ;
        void beSigned(const Bureaucrat &b);

      virtual void execute(Bureaucrat const & executor) const = 0;

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
    class FormNotSignedException : public std::exception
    {
        public:
            const char *what() const throw();
    }; 
};

// std::ostream &operator<<(std::ostream &os, AForm  &b);