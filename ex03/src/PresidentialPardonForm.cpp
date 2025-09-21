/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:39:39 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 18:01:16 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/PresidentialPardonForm.hpp"

#define toSign_ 25
#define toExecute_ 5

// --------------- Orthodox Canonical Form --------------- // 

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 0, toSign_, toExecute_)
{
	std::cout << "Def ctor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardon", 0, toSign_, toExecute_)
{
	setTarget(target);
	std::cout << "Prms ctor PresidentialPardonForm" << std::endl;
	someActivity(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs)
{
	std::cout << "Copy ctor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ) {
	std::cout << "Copy assignement operator of PresidentialPardonForm" << std::endl; 
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Dctor PresidentialPardonForm" << std::endl;
}

// ------------------------ Others ------------------------- // 

void PresidentialPardonForm::someActivity(const std::string& target) const
{
	std::cout << "\n\t----- Realisation start -----\n" << std::endl;
	std::cout << "\t" << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	std::cout << "\n\t----- Realisation end -------\n" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == 1)
	{
		if (executor.getGrade() > toExecute_)
			throw AForm::ExecuteException(executor.getName(), " can't execute this form");
	}
	else
		throw AForm::ExecuteException(executor.getName(), ", the form has not been signed yet");
}
