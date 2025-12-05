#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include <cstdlib>

class  RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &Sh);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &Sh);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};