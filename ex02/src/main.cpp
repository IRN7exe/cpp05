/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:38:40 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/06 22:36:51 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <exception>
#include <stdexcept>

int main(void)
{
	std::cout << "--------------- TEST 1: ShrubberyCreationForm ----------------\n" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 139\t name = Dan" << std::endl;
			std::cout << "form: sign = 145\t exec = 137\n" << \
			"result:\tCAN SIGN \t CAN'T EXECUTE\n" << std::endl;
			Bureaucrat b(139, "Dan");
			ShrubberyCreationForm sh("tree");
			b.signForm(sh);
			b.executeForm(sh);
		}
		catch (const std::out_of_range& ex)
		{
			std::cerr << RED << "\t" << ex.what() << DEF << '\n';
		}
	}
	std::cout << "\n\n\n\n\n\n\n--------------- TEST 2: ShrubberyCreationForm ----------------\n" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 150\t name = Dan" << std::endl;
			std::cout << "form: sign = 145\t exec = 137\n" << \
				"result:\tCAN'T SIGN\n" << std::endl;
			Bureaucrat b1(150, "Dan");
			ShrubberyCreationForm sh1("file");
			b1.signForm(sh1);
			b1.executeForm(sh1);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}
	}
	std::cout << "\n\n\n\n\n\n\n--------------- TEST 3: ShrubberyCreationForm ----------------\n" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 160\t name = Dan" << std::endl;
			std::cout << "form: sign = 145\t exec = 137\n" << \
				"result:\tCAN'T CREATE BUREAUCRAT\n" << std::endl;
			Bureaucrat b2(160, "Dan");
			ShrubberyCreationForm sh2("next");
			b2.signForm(sh2);
			b2.executeForm(sh2);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}
	}
	std::cout << "\n\n\n\n\n\n\n--------------- TEST 4: ShrubberyCreationForm ----------------\n" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 1\t name = Dan" << std::endl;
			std::cout << "form: sign = 145\t exec = 137\n" << \
				"result:\tOK\n" << std::endl;
			Bureaucrat b3(1, "Dan");
			ShrubberyCreationForm sh3("one_more");
			b3.signForm(sh3);
			b3.executeForm(sh3);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}
	}
	std::cout << "\n\n\n\n\n\n\n---------------- TEST 5: RobotomyRequestForm -----------------\n" << std::endl;
	{
		// for (int i = 0; i < 10; ++i)
		// {
			try
			{
				std::cout << "bur: grade = 15\t name = Sam" << std::endl;
				std::cout << "form: sign = 72\t exec = 45\nresult:\tOK\n" << std::endl;
				Bureaucrat b(15, "Sam");
				std::cout << b << std::endl;
				RobotomyRequestForm ro("house");
				b.signForm(ro);
				b.executeForm(ro);
				std::cout << "\n---------------------------------------------\n" << std::endl;
			}
			catch (const RobotomyRequestForm::InvalidException& ia)
			{
				std::cout << RED << "\t" << ia.what() << DEF << std::endl;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << RED << "\t" << e.what() << DEF << std::endl;
			}		
		// }
	
	}

	std::cout << "\n\n\n\n\n\n\n---------------- TEST 6: RobotomyRequestForm -----------------\n" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 15\t name = Sam" << std::endl;
			std::cout << "form: sign = 72\t exec = 45\nresult:\tINVALID ARGUMENT\n" << std::endl;
			Bureaucrat b(15, "Sam");
			RobotomyRequestForm ro("Dan");
			b.signForm(ro);
			b.executeForm(ro);
		}
		catch (const RobotomyRequestForm::InvalidException& ia)
		{
			std::cout << RED << "\t" << ia.what() << DEF << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}		
	}
	std::cout << "\n\n\n\n\n\n\n---------------- TEST 7: PresidentialPardonForm ----------------" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 1\t name = Max" << std::endl;
			std::cout << "form: sign = 25\t exec = 5\nresult:\tOK\n" << std::endl;
			Bureaucrat b(1, "Max");
			PresidentialPardonForm pr("Mike");
			b.signForm(pr);
			b.executeForm(pr);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}
	}
	std::cout << "\n\n\n\n\n\n\n---------------- TEST 8: PresidentialPardonForm ----------------" << std::endl;
	{
		try
		{
			std::cout << "bur: grade = 30\t name = Nik" << std::endl;
			std::cout << "form: sign = 25\t exec = 5\nresult:\tCAN'T SIGN \t CAN'T EXECUTE\n" << std::endl;
			Bureaucrat b(30, "Nik");
			PresidentialPardonForm pr("Mike");
			b.signForm(pr);
			b.executeForm(pr);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << RED << "\t" << e.what() << DEF << std::endl;
		}
	}
	std::cout << "--------------------------------------------------------------\n" << std::endl;
	return 0;
}
