/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:04:08 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/07/05 23:07:46 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <exception>
#include <stdexcept>

int main(void)
{
	std::cout << "\n--------- TEST: Bureaucrat can't to sign this form ---------" << std::endl;
	{
		std::cout << "test: 10, Dan\n" << std::endl;
		try
		{
			Bureaucrat b(10, "Dan");
			std::cout << b << std::endl;
			Form form("white blank", 0, 9, 1);
			b.signForm(form);
		}
		catch (Form::GradeTooHighException &ex)
		{
			std::cerr << ex.what() << '\n'; 
		}
		catch (Form::GradeTooLowException &ex)
		{
			std::cerr << ex.what() << '\n';
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\n\n---------------------- TEST: Norm case ---------------------" << std::endl;
	{
		std::cout << "test: 10, Dan\n" << std::endl;
		try
		{
			Bureaucrat b(10, "Dan");
			std::cout << b << std::endl;
			Form form("white blank", 0, 75, 50);
			b.signForm(form);
		}
		catch (const std::out_of_range& ex)
		{
			std::cerr << ex.what() << '\n';
		}
	}


	// std::cout << "------------ TEST 0: Invalid grade of Bureaucrat -------------\n" << std::endl;
	// {
	// 	std::cout << "test: 158, Dan, white blank, signed_ = 0, toSign_ = 6, toExecute_ = 1\n" << std::endl;
	// 	try
	// 	{
	// 		Bureaucrat b(158, "Dan");
	// 		Form form("white blank", 0, 6, 1);
	// 		b.signForm(form);
	// 	}
	// 	catch (const std::out_of_range& ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// }
	// std::cout << "\n\n\n------------ TEST 1: Invalid grade toSign of Form ------------" << std::endl;
	// {
	// 	std::cout << "test: 8, Dan, white blank, signed_ = 0, toSign_ = 151, toExecute_ = 1\n" << std::endl;
	// 	try
	// 	{
	// 		Bureaucrat b(8, "Dan");
	// 		Form form("white blank", 0, 151, 1);
	// 		b.signForm(form);
	// 	}
	// 	catch (const std::out_of_range& ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// }
	// std::cout << "\n\n\n------------ TEST 2: Invalid grade toSign of Form ------------" << std::endl;
	// {
	// 	try
	// 	{
	// 		std::cout << "test: 8, Dan, white blank, signed_ = 0, toSign_ = 0, toExecute_ = 1\n" << std::endl;
	// 		Bureaucrat b(8, "Dan");
	// 		Form form("white blank", 0, 0, 1);
	// 		b.signForm(form);
	// 	}
	// 	catch (Form::GradeTooHighException &ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// 	catch (Form::GradeTooLowException &ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// std::cout << "\n\n\n----------- TEST 3: Invalid grade toExecute of Form ----------" << std::endl;
	// {
	// 	std::cout << "test: 8, Dan, white blank, signed_ = 0, toSign_ = 150, toExecute_ = 151\n" << std::endl;
	// 	try
	// 	{
	// 		Bureaucrat b(8, "Dan");
	// 		Form form("white blank", 0, 150, 151);
	// 		b.signForm(form);
	// 	}
	// 	catch (Form::GradeTooHighException &ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// 	catch (Form::GradeTooLowException &ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// std::cout << "\n\n\n----------- TEST 4: Invalid grade toExecute of Form ----------" << std::endl;
	// {
	// 	std::cout << "test: 8, Dan, white blank, signed_ = 0, toSign_ = 150, toExecute_ = 0\n" << std::endl;
	// 	try
	// 	{
	// 		Bureaucrat b(8, "Dan");
	// 		Form form("white blank", 0, 150, 0);
	// 		b.signForm(form);
	// 	}
	// 	catch (const std::out_of_range& ex)
	// 	{
	// 		std::cerr << ex.what() << '\n';
	// 	}
	// }
	// std::cout << "--------------------------------------------------------------\n" << std::endl;
	return 0;
}

