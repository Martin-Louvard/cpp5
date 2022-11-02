#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& B);
        Bureaucrat&operator=(const Bureaucrat& B);

        std::string getName() const;
        int getGrade() const;
        void incrementGrade(int i);
        void decrementGrade(int i);

    private:
        std::string const name;
        int grade;
        
        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
};
std::ostream & operator << (std::ostream &out, const Bureaucrat &b);

#endif