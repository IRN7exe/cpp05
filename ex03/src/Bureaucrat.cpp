/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:45:57 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 20:06:33 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#define GradeTooHighException_ 1
#define GradeTooLowException_ 150

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* what_arg): std::out_of_range(what_arg) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const char* what_arg): std::out_of_range(what_arg) {}
Bureaucrat::EException::EException(const std::string& name, const std::string& what_arg): std::out_of_range((name + what_arg).c_str()) {}

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
		throw GradeTooLowException("\tError! Grade is too low (from prms ctor)");
	if (n < GradeTooHighException_)
		throw GradeTooHighException("\tError! Grade is too high (from prms ctor)");
	grade_ = n;
	std::cout << "Prms ctor Bureaucrat " << name_ << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs): 
	name_(rhs.name_), grade_(rhs.grade_)
{
	std::cout << "Copy ctor " << name_ << std::endl; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ) {
	std::cout << "Copy assignement operator of " << name_ << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {std::cout << "\nDctor Bureaucrat " << name_ << std::endl;}

// -------------------- Other functions -------------------- // 

std::string Bureaucrat::getName() const {return name_;}

int Bureaucrat::getGrade() const {return grade_;}

void Bureaucrat::setGrade(int grade) {
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

// ------------------------ Others ------------------------- // 

void Bureaucrat::signForm(AForm& f) const {
	f.beSigned(*this);
	std::cout << "\33[32m\t" << this->name_ << " signed " << f.getName() << "\33[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}

void Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	std::cout << "\33[32m\t" << this->name_ << " executed " << form.getName() << "\33[0m" << std::endl;
	form.someActivity(form.getTarget());
}