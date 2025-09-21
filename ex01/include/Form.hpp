/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:25:15 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:03:11 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include "Bureaucrat.hpp"

#define GRADE 75

class Bureaucrat;

// class GradeTooHighException: public std::exception 
// {
// 	public:
// 		const char*			what_arg_;
// 	public:
// 		explicit GradeTooHighException(const char* what_arg) : what_arg_(what_arg) {};
// 		const char* what(void) const throw() {
// 			return what_arg_;
// 		} 
// };

class Form
{
	private:
		const std::string 	name_;
		bool 				signed_;
		const int 			toSign_;
		const int 			toExecute_;
		Form& operator=(const Form& );
	public:
	// Orthodox Canonical Form
		Form();
		Form(std::string name, int n, int s, int e);
		Form(const Form& rhs);
		~Form();
	// getters, setters
		std::string 		getName() const;
		int 				getSigned() const;
		int 				getToSign() const;
		int 				getToExecute() const;
		void 				setSigned(void);
	// required by subjects
		void 				beSigned(const Bureaucrat& b);
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

std::ostream& operator<<(std::ostream& os, const Form& f);


