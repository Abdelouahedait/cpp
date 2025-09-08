#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 5);
        std::cout << b1.get_name() << ", grade: " << b1.get_grade() << std::endl;
        Form f1("TopSecret", 4, 5);
        std::cout << "Form: " << f1.get_name() << ", signed: " << f1.is_signed() 
                  << ", grade to sign: " << f1.get_grade_to_sign() 
                  << ", grade to execute: " << f1.get_grade_to_execute() << std::endl;
        b1.sign_form(f1);
        std::cout << "After signing attempt:" << std::endl;

        b1.increment_grade();
        std::cout << b1.get_name() << ", grade: " << b1.get_grade() << std::endl;
        b1.sign_form(f1);
        std::cout << "After second signing attempt:" << std::endl;
        std::cout << "Form: " << f1.get_name() << ", signed: " << f1.is_signed() 
                  << ", grade to sign: " << f1.get_grade_to_sign() 
                  << ", grade to execute: " << f1.get_grade_to_execute() << std::endl;
        b1.increment_grade();
        std::cout << b1.get_name() << ", grade: " << b1.get_grade() << std::endl;
        b1.increment_grade(); // This should throw an exception

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;   

}