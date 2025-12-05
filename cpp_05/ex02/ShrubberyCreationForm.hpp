#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class  ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &Sh);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &Sh);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

