/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:24:54 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:02:52 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const char* what_arg): std::out_of_range(what_arg) {}
Form::GradeTooLowException::GradeTooLowException(const char* what_arg): std::out_of_range(what_arg) {}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	return (os << "\nname: " << f.getName() \
				<< "\nsigned: " << f.getSigned() \
				<< "\ntoSign: " << f.getToSign() \
				<< "\ntoExecute: " << f.getToExecute() \
				<< "\n");
}

Form::Form():
	name_("Blank"), 
	signed_(0), 
	toSign_(10),
	toExecute_(100)
{
	std::cout << "Def ctor Form" << std::endl;
}

Form::Form(std::string name, int n, int s, int e): 
	name_(name), 
	signed_(n),
	toSign_(s), 
	toExecute_(e)
{
	if (toSign_ < 1)
	{
		std::cout << *this << std::endl;
		throw GradeTooHighException("\tError! Grade toSign is too big (from prms ctor Form)");
	}
	if (toExecute_ < 1)
	{
		std::cout << *this << std::endl;
		throw GradeTooHighException("\tError! Grade toExecute is too big (from prms ctor Form)");
	}
	if (toSign_ > 150)
	{
		std::cout << *this << std::endl;
		throw GradeTooLowException("\tError! Grade toSign is too low (from prms ctor Form)");
	}
	if (toExecute_ > 150)
	{
		std::cout << *this << std::endl;
		throw GradeTooLowException("\tError! Grade toExecute is too low (from prms ctor Form)");
	}
	std::cout << "Prms ctor Form" << std::endl;
}

Form::Form(const Form& rhs):
	name_(rhs.name_),
	signed_(rhs.signed_),
	toSign_(rhs.toSign_),
	toExecute_(rhs.toExecute_)
{
	std::cout << "Copy ctor Form" << std::endl;
}

// ----------- NOT USED ------------ //
Form& Form::operator=(const Form& ) {
	std::cout << "Copy assignement operator" << std::endl; 
	return (*this);
}

Form::~Form() {std::cout << "Dctor Form" << std::endl;}


//---------------------------- GETTERS ----------------------------// 
std::string Form::getName() const {return name_;}

int Form::getSigned() const {return static_cast<int>(signed_);}

int Form::getToSign() const {return toSign_;}

int Form::getToExecute() const {return toExecute_;}

//---------------------------- OTHERS ----------------------------// 

void Form::setSigned(void) {signed_ = true;}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > getToSign())
	{
		std::cout << *this << std::endl;
		std::string str = "\33[31m\t" + b.getName() + " couldn’t sign " + name_ + " because grade is too law\33[0m";
		throw GradeTooLowException(str.c_str());
	}
	setSigned();
	std::cout << *this << std::endl;
}
