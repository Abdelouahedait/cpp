#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presiden", 25, 5), target("default"){}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presiden", 25, 5), target(target){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Sh) : AForm("Presiden", 25, 5)
{
    this->target = Sh.target;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &Sh)
{
    if (this != &Sh)
    {
        AForm::operator=(Sh);
        this->target = Sh.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called"<< std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << target<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}