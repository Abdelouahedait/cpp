#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class  PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &Sh);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &Sh);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
};