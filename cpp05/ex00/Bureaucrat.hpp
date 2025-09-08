#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>



class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        static const int highest_grade = 1;
        static const int lowest_grade = 150;

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& get_name() const;
        int get_grade() const;
        void increment_grade();
        void decrement_grade();
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade too high";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade too low";
            }
    };


};