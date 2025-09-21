/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:37:12 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 22:35:17 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

#define toSign_ 145
#define toExecute_ 137

// --------------- Orthodox Canonical Form --------------- // 

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 0, toSign_, toExecute_)
{
	// std::cout << "Def ctor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 0, toSign_, toExecute_)
{
	// std::cout << "Prms ctor ShrubberyCreationForm" << std::endl;
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs)
{
	// std::cout << "Copy ctor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ) {
	// std::cout << "Copy assignement operator of ShrubberyCreationForm" << std::endl; 
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {std::cout << "Dctor ShrubberyCreationForm" << std::endl;}

// ------------------------ Others ------------------------- // 

void ShrubberyCreationForm::someActivity(const std::string& target) const
{
	std::string fileNameW = target + "_shrubbery";
	std::ofstream W;
	W.open(fileNameW.c_str(), std::ios::out);
	if (!W.is_open())
	{
		std::cerr << "Error opening the file of destination!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	// std::cout << "\nFile '" << fileNameW << "' has been created" << std::endl;
	W << this->getName()       \
		<< "\n  ASCII tree  \n" \
		<< "--------------\n" \
		<< "|     /\\     |\n" \
		<< "|    //\\\\    |\n" \
		<< "|   ///\\\\\\   |\n" \
		<< "|  ////\\\\\\\\  |\n" \
		<< "| /////\\\\\\\\\\ |\n" \
		<< "|//////\\\\\\\\\\\\|\n" \
		<< "|     ||     |\n" \
		<< "--------------\n";
	// std::cout << "File '" << fileNameW << "' has been processed\n" << std::endl;
	W.close();
	if (W.fail()) {std::cerr << "Stream W is failed" << std::endl;}
	// else {std::cout << "Output file closed.\n" << std::endl;}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == 1)
	{
		if (executor.getGrade() > toExecute_)
			throw AForm::ExecuteException(executor.getName(), " can't execute this form");
	}
	else
		throw AForm::ExecuteException(executor.getName(), ", the form has not been signed yet");
}