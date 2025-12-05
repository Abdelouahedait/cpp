#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
    std::srand(std::time(NULL)); 
    Intern  someRandomIntern;
    Bureaucrat boss("The Boss", 1);

    std::cout << BOLD << BLUE << "--- TEST 1: ROBOTOMY REQUEST (Valid) ---" << RESET << std::endl;
    {
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            
            delete rrf; 
        }
    }

    std::cout << BOLD << BLUE << "\n--- TEST 2: SHRUBBERY CREATION (Valid) ---" << RESET << std::endl;
    {
        AForm* scf;

        scf = someRandomIntern.makeForm("shrubbery creation", "Home");

        if (scf)
        {
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
    }

    std::cout << BOLD << BLUE << "\n--- TEST 3: PRESIDENTIAL PARDON (Valid) ---" << RESET << std::endl;
    {
        AForm* ppf;

        ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");

        if (ppf)
        {
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
    }

    std::cout << BOLD << BLUE << "\n--- TEST 4: UNKNOWN FORM (Invalid) ---" << RESET << std::endl;
    {
        AForm* wrong;

        wrong = someRandomIntern.makeForm("coffee request", "Target");

        if (wrong)
        {
            boss.signForm(*wrong);
            delete wrong;
        }
        else
        {
            std::cout << RED << "Test passed: Form was not created." << RESET << std::endl;
        }
    }

    std::cout << BOLD << BLUE << "\n--- DESTRUCTORS ---" << RESET << std::endl;
    return 0;
}