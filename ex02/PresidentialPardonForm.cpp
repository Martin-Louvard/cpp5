#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 25, 5), target("no target")
{
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PPF)
{
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
    *this = PPF;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& PPF)
{
    *this = PPF;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
          if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else if (!(this->getIsSigned()))
        throw Form::FormUnsigned();
    else
        std::cout << this->target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
