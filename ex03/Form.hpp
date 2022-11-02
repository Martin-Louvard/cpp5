#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    public:
        Form();
        Form(std::string const name, int grade_to_sign, int grade_to_execute);
        ~Form();
        Form(const Form& F);
        Form&operator=(const Form&  F);

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        void beSigned(const Bureaucrat&);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class FormUnsigned: public std::exception{
            public:
                virtual const char* what() const throw();
        };
    private:
        std::string name;
        bool is_signed;
        int grade_to_sign;
        int grade_to_execute;

        
};
std::ostream & operator << (std::ostream &out, const Form& f);


#endif