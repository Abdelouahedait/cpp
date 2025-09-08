#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 5);
        std::cout << b1.get_name() << ", grade: " << b1.get_grade() << std::endl;

        b1.increment_grade();
        std::cout << "After increment: " << b1.get_name() << ", grade: " << b1.get_grade() << std::endl;

        b1.decrement_grade();
        std::cout << "After decrement: " << b1.get_name() << ", grade: " << b1.get_grade() << std::endl;

        // This will throw an exception
        Bureaucrat b2("Bob", 0);

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;   

}