/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:39:09 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 18:04:57 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"
#include <cstdlib> 

class ShrubberyCreationForm: public AForm
{
	private:
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& );
	public:
	// Orthodox Canonical Form
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();
	// other functions	
		void someActivity(const std::string& target) const;
		void execute(Bureaucrat const & executor) const;
};


