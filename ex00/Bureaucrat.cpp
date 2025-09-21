/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:55:32 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/04 20:56:03 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define GradeTooHighException_ 1
#define GradeTooLowException_ 150

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* what_arg): std::out_of_range(what_arg) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const char* what_arg): std::out_of_range(what_arg) {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}

// --------------- Orthodox Canonical Form --------------- // 

// The const variable cannot be left un-initialized at the time of the declaration. (CE)
// It cannot be assigned value anywhere in the program.
// Explicit value needed to be provided to the constant variable at the time of 
// declaration of the constant variable.

Bureaucrat::Bureaucrat(): 
	name_("fonctionnaire"), 
	grade_(1)
{
	std::cout << "Def ctor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(int n, const std::string& name): 
	name_(name)
{
	std::cout << "Prms ctor Bureaucrat " << name_ << std::endl;
	if (n > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from prms ctor)");
	if (n < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from prms ctor)");
	grade_ = n;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs): 
	name_(rhs.name_)
{
	std::cout << "Copy ctor " << name_ << std::endl; 
	grade_ = rhs.grade_;
}

// ----------- NOT USED ------------ //
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ) {
	std::cout << "Copy assignement operator" << std::endl; 
	return *this;
}

Bureaucrat::~Bureaucrat() {std::cout << "\nDctor Bureaucrat " << name_ << std::endl;}

// -------------------- Other functions -------------------- // 

std::string Bureaucrat::getName() const {return name_;}

int Bureaucrat::getGrade() const {return grade_;}

void Bureaucrat::setGrade(const int grade) {
	if (grade > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from setGrade)");
	if (grade < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from setGrade)");
	grade_ = grade;
}

// --------------- Increments and decrements --------------- // 

void Bureaucrat::incrementGrade(void) {
	if (grade_ < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from increment)");
	operator++();
}

void Bureaucrat::decrementGrade(void) {
	if (grade_ > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from decrement)");
	operator--();
}

// --------------- Operator++ and operator-- --------------- // 

// preincrement
Bureaucrat& Bureaucrat::operator--()
{
	if (grade_ + 1 > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from operator++)");
	grade_ += 1;
	return (*this);
}

// predecrement
Bureaucrat& Bureaucrat::operator++()
{
	if (grade_ - 1 < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from operator--)");
	grade_ -= 1;
	return (*this);
}
