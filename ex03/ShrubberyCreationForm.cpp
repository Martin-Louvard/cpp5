#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target("no target")
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& SCF)
{
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
    *this = SCF;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& SCF)
{
    *this = SCF;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else if (!(this->getIsSigned()))
        throw Form::FormUnsigned();
    else
    {
        std::string file_name = this->target;
        file_name.append("_shrubbery");
        std::ofstream MyFile(file_name);

        // Write to the file
        MyFile <<"       ,,,.   ,@@@@@@/@@,  .oo8888o."<< std::endl
<<"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"<< std::endl
<<"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"<< std::endl
<<"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"<< std::endl
<<"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"<< std::endl
<<"   `&%\\ ` /%&'    |.|        \\ '|8'"<< std::endl
<<"       |o|        | |         | |"<< std::endl
<<"       |.|        | |         | |"<< std::endl
<<"jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

        // Close the file
        MyFile.close();
        std::cout << executor << " planted trees in current directory" << std::endl;
    }

}