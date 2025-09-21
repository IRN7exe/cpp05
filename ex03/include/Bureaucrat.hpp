/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:46:05 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 17:59:02 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include "AForm.hpp"

class AForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;
class RobotomyRequestForm;

class Bureaucrat {
	private:
		const std::string name_;
		int grade_;
		Bureaucrat& operator=(const Bureaucrat& );
	public:
	// 	// Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(int n, const std::string& name);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();
	// getters, setters
		std::string getName() const;
		int getGrade() const;
		void setGrade(int grade);
	// other functions	
		Bureaucrat& operator++();
		Bureaucrat& operator--();
		void decrementGrade(void);
		void incrementGrade(void);
	// required by subjects
		void signForm(AForm& f) const;
		void executeForm(AForm const & form) const;
	// exception classes
		class GradeTooHighException: public std::out_of_range {
			public:
				explicit GradeTooHighException(const char* what_arg); 
		};
		
		class GradeTooLowException: public std::out_of_range {
			public:
				explicit GradeTooLowException(const char* what_arg);
		};
		class EException: public std::out_of_range {
			public:
				explicit EException(const std::string& name, const std::string& what_arg);
		};
};
	
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
