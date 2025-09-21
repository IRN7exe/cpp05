/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:52:40 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:52:45 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

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
