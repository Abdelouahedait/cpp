#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& other)
{
    (void)other;
}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}
Intern::~Intern()
{
    std::cout << "Intern destructor called"<< std::endl;
}

AForm* createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm* createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm* createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std:: string formName, std::string target)
{
    std::string key[3] = {
                    "shrubbery creation",
                    "robotomy request",
                    "presidential pardon"};
    AForm* (*formCreators[3])(std::string target) = {
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (key[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern cannot create " << formName << " because it is unknown form." << std::endl;
    return NULL;
}