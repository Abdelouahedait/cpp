#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Roboto", 72, 45), target("Default"){}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Roboto", 72, 45), target(target)
{
  
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Sh) : AForm("Roboto", 72, 45)
{
    this->target = Sh.target;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &Sh)
{
    if (this != &Sh)
    {
        AForm::operator=(Sh);
        this->target = Sh.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
        std::cout << "RobotomyRequestForm destructor called"<< std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << "* VRRRRRRRR... ZZZZZZTTT... CLANK! *" << std::endl;
    std::cout << "* (Uncomfortable drilling noises echo) *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout <<target<< " has been robotomized"<<std::endl;
    else   
        std::cout << "robotomy failed"<<std::endl;
}