#pragma once
#include <iostream>
#include <string>
#include <exception>

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
		
		void increment_grade();
		void decrement_grade();
		
		int getGrade();
		std::string getName();
		
		
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