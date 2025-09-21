/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:26:31 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 21:09:26 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <typeinfo>  
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;
class RobotomyRequestForm;

#define DEF "\33[0m"
#define RED "\33[31m"
#define GRE "\33[32m"
#define BLU "\33[34m"

#define ARRSIZE 3

class Intern
{
	private:
		Intern& operator=(const Intern& );
	public:
	// Orthodox Canonical Form
		Intern();
		Intern(const Intern& rhs);
		virtual ~Intern();
	// required by subjects
		AForm* makeForm(const std::string& nameOfForm, const std::string& target);
	// other
		// AForm* (Intern::*arrForm[ARRSIZE])(AForm* ptr, const std::string& target);
		AForm* createRobotomy(const std::string& target);
		AForm* createShrubbery(const std::string& target); 
		AForm* createPardon(const std::string& target);
};

#endif
