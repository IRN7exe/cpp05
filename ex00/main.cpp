/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:04:08 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/24 20:56:30 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n------------ TEST 0: Test def ctor and setGrade -------------\n" << std::endl;
	{
		try
		{
			Bureaucrat b;
			std::cout << b << std::endl;
			b.setGrade(222);
			std::cout << "Call setGrade: ";
			std::cout << b << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
	}
	std::cout << "\n\n\n-------------------------------------------------------------" << std::endl;
	std::cout << "----------------- TEST 1: test prms ctor --------------------\n" << std::endl;
	{
		std::cout << "test: 19, officier" << std::endl;
		try
		{
			Bureaucrat b(19, "officier");
			std::cout << b << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
	}
	std::cout << "\n-----------------------------------------------------------" << std::endl;
	{		
		std::cout << std::endl;
		std::cout << "test: 190, lieutenant" << std::endl;
		try
		{
			Bureaucrat b1(190, "lieutenant");
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
	}
	std::cout << "\n\n\n-----------------------------------------------------------" << std::endl;
	std::cout << "TEST 2: test getGrade, decrement (to 150), increment (to 1)\n" << std::endl;
	{
		std::cout << "test: 150, lieutenant" << std::endl;
		Bureaucrat b(150, "lieutenant");
		std::cout << b << std::endl;
		try
		{
			std::cout << "Call getGrade: \n";
			std::cout << b.getGrade() << std::endl;
			std::cout << "Call decrement: \n";
			b.decrementGrade();
			std::cout << b.getGrade() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}

		try
		{
			std::cout << "Call increment: ";
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
	}
	std::cout << "\n\n\n-------------------------------------------------------------" << std::endl;
	std::cout << "--------------- TEST 3: operator--, operator++ --------------\n" << std::endl;
	{
		std::cout << "test: 150, sergent" << std::endl;
		try
		{
			Bureaucrat b(150, "sergent");
			std::cout << b << std::endl;
			std::cout << "Call operator--: ";
			b.operator--();
			std::cout << b << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
		std::cout << "\n-------------------------------------------------------------" << std::endl;
		std::cout << "test: 0, general" << std::endl;
		try
		{
			Bureaucrat x(0, "general");
			std::cout << "Call operator++: ";
			++x;
			std::cout << x << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
	}
	std::cout << "\n\n\n-------------------------------------------------------------" << std::endl;
	std::cout << "--------------------- TEST 4: test copy ctor ------------------\n" << std::endl;
	{
		std::cout << "test: -22, officier" << std::endl;
		try
		{
			Bureaucrat b(-22, "officier");
			std::cout << "\nBureaucrat b: " << std::endl;
			std::cout << b << std::endl;

			std::cout << "\n\nBureaucrat c: " << std::endl;
			Bureaucrat c(b);
			std::cout << c << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &eh)
		{
			std::cerr << eh.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException &el)
		{
			std::cerr << el.what() << '\n';
		}
	}
	std::cout << "\n-----------------------------------------------------------" << std::endl;
	return 0;
}


//catch (std::exception & e)