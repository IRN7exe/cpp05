/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 01:02:17 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/07 16:49:50 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <exception>
#include <stdexcept>

int main(void)
{
	{
		try
		{
			std::cout << "\n\n\n\n------------------- TEST 1: FAILURE ----------------------\n" << std::endl;
			Intern i1;
			AForm* form1 = i1.makeForm("robotomy request", "Ostap");
			
			delete form1;

			std::cout << "\n\n\n\n------------------- TEST 2: SUCCESS ----------------------\n" << std::endl;

			Intern i2;
			AForm* form2 = i2.makeForm("ShrubberyCreationForm", "Bender");
			
			delete form2;

			std::cout << "\n\n\n\n------------------- TEST 3: SUCCESS ----------------------\n" << std::endl;

			Intern i3;
			AForm* form3 = i3.makeForm("PresidentialPardonForm", "Ilya");
			
			delete form3;

			std::cout << "\n\n\n\n------------------- TEST 4: FAILURE ----------------------\n" << std::endl;

			Intern i4;
			AForm* form4 = i4.makeForm("PresidentialPardon", "Ilf");
			
			delete form4;

			std::cout << "\n\n\n\n------------------- TEST 5: ??????? ----------------------\n" << std::endl;

			Intern i5;
			AForm* form5 = i5.makeForm("RobotomyRequestForm", "Ostap");
			
			delete form5;

			std::cout << "\n\n\n\n------------------- TEST 6: ??????? ----------------------\n" << std::endl;

			Intern i6;
			AForm* form6 = i6.makeForm("RobotomyRequestForm", "Ostap");
			
			delete form6;
			
			std::cout << "\n\n\n\n--------------------------------------------------------------\n" << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}
		catch (RobotomyRequestForm::InvalidException& in)
		{
			std::cout << RED << "\t" << in.what() << DEF << std::endl;
		}
	}
	std::cout << "--------------------------------------------------------------\n" << std::endl;
	return 0;
}
