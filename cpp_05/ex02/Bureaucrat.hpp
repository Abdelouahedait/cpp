#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &oth);
		Bureaucrat& operator=(const Bureaucrat &oth);
		Bureaucrat(std::string name, int grade);
		
		int getGrade()const;
		std::string getName()const;
		void executeForm(AForm const & form) const;
		void signForm(AForm &form) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat  &b);