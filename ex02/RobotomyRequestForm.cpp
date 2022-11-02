#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target("no target")
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& RRF)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
    *this = RRF;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& RRF)
{
    *this = RRF;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else if (!(this->getIsSigned()))
        throw Form::FormUnsigned();
    else
    {
        std::cout << "BZZZZZZZZZZZZZZZZZZZZ...." << std::endl;
        srand(time(NULL));
        int random_number = rand() % 2;
        if (random_number)
            std::cout << this->target << " has been robotomyzed." << std::endl;
        else
            std::cout << "operation failed."<< std::endl;
    }
}
