/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:45:27 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 22:44:38 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

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
		AForm(const std::string& name, int n, int s, int e);
		AForm(const std::string& target);
		AForm(const AForm& rhs);
		virtual ~AForm() = 0;
	// getters, setters
		std::string getName() const;
		int getSigned() const;
		int getToSign() const;
		int getToExecute() const;
		std::string getTarget() const;
		void setTarget(const std::string& target);
		void setSigned(void);
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

#endif

