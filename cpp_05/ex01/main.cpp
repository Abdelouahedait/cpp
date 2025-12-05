
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.decrement_grade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	try
	{
	tim.decrement_grade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;


	std::cout << "\033[33m" << std::endl << "Test ex01" << "\033[0m" << std::endl;

	Form id_form("ID FORM", 100, 90);
	Bureaucrat mr_slow;
	Bureaucrat mr_id("MR_ID", 100);
	std::cout << id_form;
	
	std::cout << mr_slow;
	std::cout << id_form;
	mr_slow.signForm(id_form);

	std::cout << id_form;
	std::cout <<mr_id;
	mr_id.signForm(id_form);
	mr_id.signForm(id_form);
	return (0);
}