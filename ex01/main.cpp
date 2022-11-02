#include "Bureaucrat.hpp"
#include "Form.hpp"

int
main (int ac, char **av)
{
	try
	{
		Form			f("A12-B34", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form			f("A12-B34", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form			f("A12-B34", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form			f("A12-B34", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat		paul = Bureaucrat("Paul", 1);
		Form			f("A12-B34", 150, 150);
	
		std::cout << f << std::endl;
		paul.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		
	try
	{
		Bureaucrat		paul = Bureaucrat("Paul", 10);
		Form			f("A12-B34", 1, 1);

		std::cout << f << std::endl;
		paul.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;	
}