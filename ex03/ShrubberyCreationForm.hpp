#ifndef SCFORM_HPP
#define SCFORM_HPP

#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm: public Form{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm&operator=(const ShrubberyCreationForm&);
        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string target;
};

#endif
