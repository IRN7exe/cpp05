/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:52:40 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 18:00:02 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
// #ifndef PRESIDENTIALPARDONFORM_HPP
// #define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm
{
	private:
		PresidentialPardonForm& operator=(const PresidentialPardonForm& );
	public:
	// Orthodox Canonical Form
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
	// other functions	
		void someActivity(const std::string& target) const;
		void execute(Bureaucrat const & executor) const;
};

// #endif