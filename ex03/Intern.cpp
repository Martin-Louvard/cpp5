#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout <<"Default Intern constructor" << std::endl;
}

Intern::~Intern()
{
    std::cout <<"Intern destructor" << std::endl;
}

Intern::Intern(const Intern& I)
{    
    std::cout <<"Intern copy constructor" << std::endl;
    *this = I;
}

Intern& Intern::operator=(const Intern& i)
{
    return (*this);
}

Form* Intern::makeForm(std::string form_name, std::string target)
{
    Form *forms[] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    std::string names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i = 0;
    for (; i < 3; i++)
    {
        if (names[i] == form_name);
            break;
    }
    for (int j = 0; j < 3; j++)
    {
        if (names[j] != form_name)
            delete forms[j];
    }
    if (i == 3 && names[i] != form_name)
    {
        std::cerr << "Form name does not exists" << std::endl;
        return (NULL);
    }
    std::cout << form_name << " form was created" << std::endl;
    return (forms[i]);
}
