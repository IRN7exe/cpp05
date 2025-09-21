/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:37:12 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 18:04:28 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

#define toSign_ 145
#define toExecute_ 137

// --------------- Orthodox Canonical Form --------------- // 

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 0, toSign_, toExecute_)
{
	std::cout << "Def ctor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 0, toSign_, toExecute_)
{
	std::cout << "Prms ctor ShrubberyCreationForm" << std::endl;
	setTarget(target);
	someActivity(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs)
{
	std::cout << "Copy ctor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ) {
	std::cout << "Copy assignement operator of ShrubberyCreationForm" << std::endl; 
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Dctor ShrubberyCreationForm" << std::endl;
}

// ------------------------ Others ------------------------- // 

void ShrubberyCreationForm::someActivity(const std::string& target) const
{
	std::cout << "\n\t----- Realisation start -----" << std::endl;
	std::string fileNameW = target + "_shrubbery";
	std::ofstream W;
	try
	{
		W.open(fileNameW.c_str(), std::ios::out);
		if (!(W.is_open()))
			throw std::ios_base::failure("Could not open file");
	}
	catch (const std::ios_base::failure& e) {
        std::cerr << "\tError: " << e.what() << std::endl;
	}
	std::cout << "\n\tFile '" << fileNameW << "' has been created" << std::endl;
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
	std::cout << "\tFile '" << fileNameW << "' has been processed\n" << std::endl;
	W.close();
	if (W.fail()) {std::cerr << "\tStream W is failed" << std::endl;}
	else {std::cout << "\tOutput file closed.\n" << std::endl;}
	std::cout << "\t----- Realisation end -------\n" << std::endl;
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