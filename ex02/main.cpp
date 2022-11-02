#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Form			*form = NULL;
	Bureaucrat		bob("Bob", 1);
	Bureaucrat		phil("Phil", 40);
	Bureaucrat		luc("Luc", 150);

	try
	{
		form = new PresidentialPardonForm("Martin");
		bob.signForm(*form);
		form->execute(luc);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}


	try
	{
		form = new RobotomyRequestForm("Remi");
		luc.signForm(*form);
		form->execute(phil);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}



	try
	{
		form = new ShrubberyCreationForm("Garden");
		phil.signForm(*form);
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}


try{
		bob.executeForm(PresidentialPardonForm("Martin"));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	phil.executeForm(PresidentialPardonForm("Martin"));

	bob.executeForm(RobotomyRequestForm("Remi"));
	phil.executeForm(RobotomyRequestForm("Remi"));
	
	phil.executeForm(ShrubberyCreationForm("Garden"));

	delete form;

	return 0;
}