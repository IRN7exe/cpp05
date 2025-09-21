/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:53:02 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:05:12 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		Bureaucrat& operator=(const Bureaucrat& );
		const std::string name_;
		int grade_;
	public:
	// Orthodox Canonical Form
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
		void signForm(Form& f) const;
	// exception classes
		class GradeTooHighException: public std::out_of_range {
			public:
				explicit GradeTooHighException(const char* what_arg); 
		};
		class GradeTooLowException: public std::out_of_range {
			public:
				explicit GradeTooLowException(const char* what_arg);
		};
};
	
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

