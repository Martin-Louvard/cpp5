#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():name("no name"), grade(150)
{
    std::cout <<"default bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
        std::cout <<"default bureaucrat constructor" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout <<"Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& B)
{    
    std::cout <<"Bureaucrat copy constructor" << std::endl;
    *this = B;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B)
{
    if (this == &B)
        return (*this);

    std::string* stringPTR = (std::string*)&this->name;
	
	this->grade = B.grade;
	*stringPTR = B.name;
    *this = B;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(int i)
{

    if (this->grade - i < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade -= i;
}

void Bureaucrat::decrementGrade(int i)
{

    if (this->grade + i > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade += i;
 
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (out);
}

const char* Bureaucrat::GradeTooLowException::what (void) const throw()
{
    return ("Exception! Minimum grade is 150");
}

const char* Bureaucrat::GradeTooHighException::what (void) const throw()
{
    return ("Exception! Maximum grade is 1");
}

void Bureaucrat::signForm(Form F)
{
    try {
        F.beSigned(*this);
        std::cout << this->name << " signed " << F << std::endl;
    }
    catch (std::exception &e)
	{
		std::cout 	<< this->name << " couldn’t sign " << F << " because " << e.what() << "." << std::endl;
	}
}