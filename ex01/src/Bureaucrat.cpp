/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:55:32 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:05:06 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#define GradeTooHighException_ 1
#define GradeTooLowException_ 150

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* what_arg): std::out_of_range(what_arg) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const char* what_arg): std::out_of_range(what_arg) {}

// --------------- Orthodox Canonical Form --------------- // 

Bureaucrat::Bureaucrat(): 
	name_("fonctionnaire"), 
	grade_(1)
{
	std::cout << "Def ctor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(int n, const std::string& name): 
	name_(name)
{
	if (n > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from prms ctor Bureaucrat)");
	if (n < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from prms ctor Bureaucrat)");
	grade_ = n;
	std::cout << "Prms ctor Bureaucrat " << name_ << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs): 
	name_(rhs.name_), grade_(rhs.grade_)
{
	std::cout << "Copy ctor " << name_ << std::endl; 
}
// ------------- DON'T USED --------------- // 
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ) {
	std::cout << "Copy assignement operator " << std::endl; 
	return *this;
}

Bureaucrat::~Bureaucrat() {std::cout << "\nDctor Bureaucrat " << name_ << std::endl;}


// -------------------- Other functions -------------------- // 

std::string Bureaucrat::getName() const {return name_;}

int Bureaucrat::getGrade() const {return grade_;}

void Bureaucrat::setGrade(int grade) {
	if (grade > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from setGrade) Bureaucrat");
	if (grade < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from setGrade) Bureaucrat");
	grade_ = grade;
}

// --------------- Increments and decrements --------------- // 

void Bureaucrat::incrementGrade(void) {
	if (grade_ < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from increment) Bureaucrat");
	operator++();
}

void Bureaucrat::decrementGrade(void) {
	if (grade_ > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from decrement) Bureaucrat");
	operator--();
}

// --------------- Operator++ and operator-- --------------- // 

// preincrement
Bureaucrat& Bureaucrat::operator--()
{
	if (grade_ + 1 > GradeTooLowException_)
		throw GradeTooLowException("\tError! Grade is too low (from operator++) Bureaucrat");
	grade_ += 1;
	return (*this);
}

// predecrement
Bureaucrat& Bureaucrat::operator++()
{
	if (grade_ - 1 < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from operator--) Bureaucrat");
	grade_ -= 1;
	return (*this);
}

// ------------------------ Others ------------------------- // 

void Bureaucrat::signForm(Form& f) const
{
	f.beSigned(*this);
	std::cout << "\33[32m\t" << this->name_ << " signed " << f.getName() << "\33[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}