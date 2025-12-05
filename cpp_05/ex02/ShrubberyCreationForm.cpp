#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("Default"){}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), target(target)
{
   
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Sh) : AForm("Shrubbery", 145, 137)
{
    this->target = Sh.target;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Sh)
{
    if (this != &Sh)
    {
        AForm::operator=(Sh);
        this->target = Sh.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called"<< std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::string s = target + "_shrubbery";
    std::ofstream Shrubbery(s.c_str());
    Shrubbery << "       _-_" << std::endl;
    Shrubbery << "    /~~   ~~\\" << std::endl;
    Shrubbery << " /~~         ~~\\" << std::endl;
    Shrubbery << "{               }" << std::endl;
    Shrubbery << " \\  _-     -_  /" << std::endl;
    Shrubbery << "   ~  \\\\ //  ~" << std::endl;
    Shrubbery << "_- -   | | _- _" << std::endl;
    Shrubbery << "  _ -  | |   -_" << std::endl;
    Shrubbery << "      // \\\\" << std::endl;
    Shrubbery << "" << std::endl;
    Shrubbery.close();
}