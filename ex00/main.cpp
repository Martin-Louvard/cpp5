#include "Bureaucrat.hpp"

int
main (int ac, char **av)
{
	try
	{
		Bureaucrat		test = Bureaucrat("Paul", 1);
		std::cout << test << std::endl;
		test.decrementGrade(10);
		std::cout << test << std::endl;
		test.incrementGrade(10);
		std::cout << test << std::endl;
		test.incrementGrade(10);
		std::cout << test << std::endl;
        std::cout << test << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		test = Bureaucrat("Paul", 1);
		std::cout << test << std::endl;
		test.decrementGrade(100);
		std::cout << test << std::endl;
		test.incrementGrade(10);
		std::cout << test << std::endl;
		test.decrementGrade(100);
		std::cout << test << std::endl;
        std::cout << test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		test = Bureaucrat("Paul", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		test = Bureaucrat("Paul", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	
}