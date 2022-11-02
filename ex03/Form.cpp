#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():name("no name"), is_signed(false), grade_to_sign(1), grade_to_execute(1)
{
    std::cout << "Default Form constructor" << std::endl;
}

Form::Form(std::string const name, int grade_to_sign, int grade_to_execute):name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    std::cout << "Default Form constructor" << std::endl;
    if (grade_to_execute < 1 || grade_to_sign < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_execute > 150 || grade_to_sign > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
}

Form::Form(const Form& F)
{
    std::cout << "Form copy constructor" << std::endl;
    *this = F;
}

Form& Form::operator=(const Form& F)
{
    if (this == &F)
        return (*this);
    
    std::string* name_ptr = (std::string*)&(this->name);
    int* exec_ptr = (int*)&this->grade_to_sign;
    int* sign_ptr = (int*)&this->grade_to_execute;

    *name_ptr = F.name;
    *exec_ptr = F.grade_to_execute;
    *sign_ptr = F.grade_to_sign;

    return (*this);
}

std::string Form::getName(void) const
{
    return (this->name);
}

bool Form::getIsSigned(void) const
{
    return this->is_signed;
}

int Form::getGradeToSign(void) const
{
    return this->grade_to_sign;
}

int Form::getGradeToExecute(void) const
{
    return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat& B)
{
    if (B.getGrade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    else
        this->is_signed = true;
}

std::ostream & operator << (std::ostream &out, const Form& f)
{
    out << "Form " <<  f.getName() << ", grade to sign " << f.getGradeToSign() << ", grade to execute " << f.getGradeToExecute() << std::endl;
    return (out);
}

const char* Form::GradeTooLowException::what (void) const throw()
{
    return ("Exception! Grade too low");
}

const char* Form::GradeTooHighException::what (void) const throw()
{
    return ("Exception! Grade too high");
}

const char* Form::FormUnsigned::what (void) const throw()
{
    return ("Exception! Form Not signed");
}

void Form::execute(Bureaucrat const & executor) const
{
}