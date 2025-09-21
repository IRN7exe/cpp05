/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:45:27 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 00:09:05 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
// #include <string>
// #include <iostream>


#define GRADE 75

#define DEF "\33[0m"
#define RED "\33[31m"
#define GRE "\33[32m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name_;
		bool 				signed_;
		const int 			toSign_;
		const int 			toExecute_;
		std::string			target_;
		AForm& operator=(const AForm& );
	public:
	// Orthodox Canonical Form
		AForm();
		AForm(std::string name, int n, int s, int e);
		AForm(std::string target);
		AForm(const AForm& rhs);
		virtual ~AForm() = 0;
	// getters, setters
		std::string getName() const;
		int getSigned() const;
		int getToSign() const;
		int getToExecute() const;
		void setSigned(void);
		void setTarget(const std::string& target);
		std::string getTarget() const;
	// required by subjects
		void beSigned(const Bureaucrat& b);
		virtual void someActivity(const std::string& target) const = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;
	// exception classes
		class GradeTooHighException: public std::out_of_range {
			public:
				explicit GradeTooHighException(const char* what_arg);
		};
		
		class GradeTooLowException: public std::out_of_range {
			public:
				explicit GradeTooLowException(const char* what_arg);
		};
		class ExecuteException: public std::out_of_range {
			public:
				explicit ExecuteException(const std::string& name, const std::string& what_arg);
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

// #include "Bureaucrat.hpp"