/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:45:03 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:24:43 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
// #include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(const char* what_arg): std::out_of_range(what_arg) {}
AForm::GradeTooLowException::GradeTooLowException(const char* what_arg): std::out_of_range(what_arg) {}
AForm::ExecuteException::ExecuteException(const std::string& name, const std::string& what_arg): std::out_of_range((name + what_arg).c_str()) {}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	return (os << "\nname: " << f.getName() \
				<< "\nsigned: " << f.getSigned() \
				<< "\ntoSign: " << f.getToSign() \
				<< "\ntoExecute: " << f.getToExecute() \
				<< "\n");
}

AForm::AForm():
	name_("Blank"), 
	signed_(0), 
	toSign_(10),
	toExecute_(100)
{
	//std::cout << "Def ctor AForm" << std::endl;
}

AForm::AForm(std::string name, int n, int s, int e): 
	name_(name), 
	signed_(n),
	toSign_(s), 
	toExecute_(e)
{
	if (toSign_ < 1)
	{
		// std::cout << *this << std::endl;
		throw GradeTooHighException("Error! Grade toSign is too big (from prms ctor Form)");
	}
	if (toExecute_ < 1)
	{
		// std::cout << *this << std::endl;
		throw GradeTooHighException("Error! Grade toExecute is too big (from prms ctor Form)");
	}
	if (toSign_ > 150)
	{
		// std::cout << *this << std::endl;
		throw GradeTooLowException("Error! Grade toSign is too low (from prms ctor Form)");
	}
	if (toExecute_ > 150)
	{
		// std::cout << *this << std::endl;
		throw GradeTooLowException("Error! Grade toExecute is too low (from prms ctor Form)");
	}
	// std::cout << "Prms ctor AForm" << std::endl;
}

AForm::AForm(std::string target): signed_(0), toSign_(0), toExecute_(0), target_(target)
{
	target_ = target;
	// std::cout << "Prms ctor AForm (target)" << std::endl;
}

AForm::AForm(const AForm& rhs):
	name_(rhs.name_),
	signed_(rhs.signed_),
	toSign_(rhs.toSign_),
	toExecute_(rhs.toExecute_)
{
	// std::cout << "Copy ctor AForm" << std::endl;
}

// ----------- NOT USED ------------ //
AForm& AForm::operator=(const AForm& ) {
	// std::cout << "Copy assignement operator of AForm" << std::endl;
	return (*this);
}

AForm::~AForm() {std::cout << "Dctor AForm" << std::endl;}


//---------------------------- GETTERS ----------------------------// 
std::string AForm::getName() const {return name_;}

int AForm::getSigned() const {return static_cast<int>(signed_);}

int AForm::getToSign() const {return toSign_;}

int AForm::getToExecute() const {return toExecute_;}

std::string AForm::getTarget() const {return target_;}

//---------------------------- OTHERS ----------------------------// 

void AForm::setTarget(const std::string& target) {target_ = target;}

void AForm::setSigned(void) {signed_ = true;}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > getToSign())
	{
		// std::cout << *this << std::endl;
		std::string str = "\33[31m" + b.getName() + " couldn’t sign " + name_ + " because grade is too law\33[0m";
		throw GradeTooLowException(str.c_str());
	}
	setSigned();
	// std::cout << *this << std::endl;
}
