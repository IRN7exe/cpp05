/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:05:16 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 22:39:06 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <bits/stdc++.h>
#include <sys/time.h>

class RobotomyRequestForm: public AForm
{
	private:
		RobotomyRequestForm& operator=(const RobotomyRequestForm& );
	public:
	// Orthodox Canonical Form
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();
	// other functions	
		void someActivity(const std::string& target) const;
		void execute(Bureaucrat const & executor) const;
	// exception classes
		class InvalidException: public std::invalid_argument {
			public:
				explicit InvalidException(const char* what_arg);
		};
};

