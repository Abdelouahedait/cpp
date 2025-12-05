#include <iostream>
#include <cstdlib> // For srand/rand
#include <ctime>   // For time

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Colors for readable output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

void printHeader(std::string title) {
    std::cout << "\n" << BOLD << BLUE << "==========================================" << RESET << std::endl;
    std::cout << BOLD << BLUE << "TEST: " << title << RESET << std::endl;
    std::cout << BOLD << BLUE << "==========================================" << RESET << std::endl;
}

int main()
{
    std::srand(std::time(NULL));

    try {
        // Create Bureaucrats
        Bureaucrat boss("The Boss", 1);        // Can do everything
        Bureaucrat mid("Middle Man", 45);      // Can do Robotomy, but not President
        Bureaucrat intern("The Intern", 150);  // Can't do anything

        // Create Forms
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm   robot("Bender");
        PresidentialPardonForm pardon("Criminal");

        // ------------------------------------------------------------------
        printHeader("1. SHRUBBERY CREATION (Low Level Form)");
        // ------------------------------------------------------------------
        std::cout << YELLOW << "[Intern tries to sign Shrubbery]" << RESET << std::endl;
        intern.signForm(shrub); // Should fail (Grade 150 vs Req 145)

        std::cout << YELLOW << "\n[MidLevel signs Shrubbery]" << RESET << std::endl;
        mid.signForm(shrub);    // Should succeed

        std::cout << YELLOW << "\n[Intern tries to execute Shrubbery]" << RESET << std::endl;
        intern.executeForm(shrub); // Should fail (Grade 150 vs Req 137)
        
        std::cout << YELLOW << "\n[MidLevel executes Shrubbery]" << RESET << std::endl;
        mid.executeForm(shrub); // Should succeed -> Check for file "Garden_shrubbery"

        // ------------------------------------------------------------------
        printHeader("2. ROBOTOMY REQUEST (Mid Level Form)");
        // ------------------------------------------------------------------
        std::cout << YELLOW << "[MidLevel tries to execute BEFORE signing]" << RESET << std::endl;
        mid.executeForm(robot); // Should fail (Not signed)

        std::cout << YELLOW << "\n[Boss signs Robotomy]" << RESET << std::endl;
        boss.signForm(robot);

        std::cout << YELLOW << "\n[MidLevel executes Robotomy 4 times (Testing 50% Randomness)]" << RESET << std::endl;
        // Running multiple times to see different outcomes
        mid.executeForm(robot);
        mid.executeForm(robot);
        mid.executeForm(robot);
        mid.executeForm(robot);

        // ------------------------------------------------------------------
        printHeader("3. PRESIDENTIAL PARDON (High Level Form)");
        // ------------------------------------------------------------------
        std::cout << YELLOW << "[MidLevel tries to sign Presidential]" << RESET << std::endl;
        mid.signForm(pardon); // Should fail (Grade 45 vs Req 25)

        std::cout << YELLOW << "\n[Boss signs Presidential]" << RESET << std::endl;
        boss.signForm(pardon);

        std::cout << YELLOW << "\n[MidLevel tries to execute Presidential]" << RESET << std::endl;
        mid.executeForm(pardon); // Should fail (Grade 45 vs Req 5)

        std::cout << YELLOW << "\n[Boss executes Presidential]" << RESET << std::endl;
        boss.executeForm(pardon); // Should succeed

        printHeader("DESTRUCTORS START HERE");
    }
    catch (std::exception &e) {
        std::cout << RED << "Unexpected Exception in Main: " << e.what() << RESET << std::endl;
    }

    return 0;
}