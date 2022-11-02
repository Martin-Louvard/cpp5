#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	Form	*rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	delete rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	rrf = someRandomIntern.makeForm("not existing", "Bender");

	return 0;
}