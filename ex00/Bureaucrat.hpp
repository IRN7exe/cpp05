/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:53:02 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 22:44:18 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
		void setGrade(const int grade);
	// other functions	
		Bureaucrat& operator++();
		Bureaucrat& operator--();
	// required by subjects
		void decrementGrade(void);
		void incrementGrade(void);
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

#endif
