#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& B);
        Intern&operator=(const Intern& B);
        Form* makeForm(std::string form_name, std::string target);

};

#endif