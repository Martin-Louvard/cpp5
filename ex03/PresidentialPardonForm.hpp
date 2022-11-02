#ifndef PPFORM_HPP
#define PPFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm&);
        PresidentialPardonForm&operator=(const PresidentialPardonForm&);
        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string target;
};

#endif