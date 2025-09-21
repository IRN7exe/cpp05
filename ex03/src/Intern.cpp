/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:58:59 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/07 16:35:59 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"


// --------------- Orthodox Canonical Form --------------- // 

Intern::Intern() {
	std::cout << "Def ctor Intern" << std::endl;
}

Intern::Intern(const Intern& rhs) {
	(void)rhs;
	std::cout << "Copy ctor Intern" << std::endl;
}

Intern& Intern::operator=(const Intern& ) {
	std::cout << "Copy assignement operator Intern" << std::endl;
	return (*this);
}

Intern::~Intern() {std::cout << "Dctor Intern" << std::endl;}

// -------------------- Other functions -------------------- // 

AForm* Intern::createRobotomy(const std::string& target)
{
	AForm* ptr = NULL;
	try
	{
		ptr = new RobotomyRequestForm(target);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (ptr);
}

AForm* Intern::createShrubbery(const std::string& target) 
{
	AForm* ptr = NULL;
	try
	{
		ptr = new ShrubberyCreationForm(target);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (ptr);
}

AForm* Intern::createPardon(const std::string& target)
{
	AForm* ptr = NULL;
	try
	{
		ptr = new PresidentialPardonForm(target);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (ptr);
}

AForm* Intern::makeForm(const std::string& nameOfForm, const std::string& target)
{
	AForm *form = NULL;
	std::string arrName[ARRSIZE] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
	AForm* (Intern::*arrForm[ARRSIZE])(const std::string& target) = {
		&Intern::createRobotomy, 
		&Intern::createShrubbery, 
		&Intern::createPardon
	};	
	
	try
	{
		for (int i = 0; i < ARRSIZE; ++i)
		{
			if (nameOfForm.compare(arrName[i].c_str()) == 0)
			{
				form = (this->*arrForm[i])(target);
				break;
			}
		}
		// std::string name = typeid(*form).name();
		(void)typeid(*form);
	}
	catch (std::bad_typeid& e)
	{
		std::cerr << RED << "\tbad_typeid caught: " << e.what() << std::endl;
		std::cerr << "\tError! Form's name not found" << DEF << std::endl;
	}
	
	if (form != NULL)
		std::cout << BLU << "\tIntern created form: " << form->getName() << ", " << form->getTarget() \
				<< ", " << form->getSigned() << DEF << std::endl;
	return (form);
}