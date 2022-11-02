#ifndef RRFORM_HPP
#define RRFORM_HPP

#include "Form.hpp"
#include <cstdlib>
#include <ctime>
class RobotomyRequestForm: public Form{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm&);
        RobotomyRequestForm&operator=(const RobotomyRequestForm&);
        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string target;
};

#endif