/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:05:05 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 22:29:29 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

#define toSign_ 72
#define toExecute_ 45

RobotomyRequestForm::InvalidException::InvalidException(const char* what_arg): std::invalid_argument(what_arg) {}

// --------------- Orthodox Canonical Form --------------- // 

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest", 0, toSign_, toExecute_)
{
	// std::cout << "Def ctor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequest", 0, toSign_, toExecute_)
{
	// std::cout << "Prms ctor RobotomyRequestForm" << std::endl;
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs)
{
	// std::cout << "Copy ctor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ) {
	// std::cout << "Copy assignement operator of RobotomyRequestForm" << std::endl; 
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {std::cout << "Dctor RobotomyRequestForm" << std::endl;}

// ------------------------ Others ------------------------- // 

void RobotomyRequestForm::someActivity(const std::string& target) const
{
	std::cout << "\n\tDRIIIIIILLLLLLLLLLIIIIIIINNNNNNGGGGGGGG\n" << std::endl;

	timeval time; 
	int errCode = gettimeofday(&time, NULL);
	if (errCode)
		throw InvalidException("Something is wrong");
	srand(time.tv_usec);
	if (rand() % 2 == 0)
		std::cout << "\t" << GRE << target << " has been robotomized successfully 50% of the time" << DEF << std::endl;
	else 
		throw InvalidException("The robotomy failed.");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == 1)
	{
		if (executor.getGrade() > toExecute_)
			throw AForm::ExecuteException(executor.getName(), " can't execute this form");
	}
	else
		throw AForm::ExecuteException(executor.getName(), ", the form has not been signed yet");
}
