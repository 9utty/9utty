/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:01 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 19:11:11 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void test1(void)
{

	Bureaucrat test1("gulee", 46);
	Form *ptr1 = new RobotomyRequestForm("Robot");
	try {
		ptr1->beSigned(test1);
		test1.executeForm(*ptr1);
		test1.decrement();
		test1.executeForm(*ptr1);
		test1.executeForm(*ptr1);
		delete ptr1;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		delete ptr1;
	}
}

void test2(void)
{
	Bureaucrat test2("gulee2", 2);
	Bureaucrat test3("gulee3", 149);
	Form *ptr2 = new ShrubberyCreationForm("Tree");

	try
	{
		ptr2->beSigned(test2);
		test2.executeForm(*ptr2);
		ptr2->beSigned(test3);
		test3.executeForm(*ptr2);
		test2.increment();
		test3.increment();
		test3.executeForm(*ptr2);
		delete ptr2;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		delete ptr2;
	}
}

void test3(void)
{
	Bureaucrat test4("fourth-grade civil", 4);
	Form *ptr4 = new PresidentialPardonForm("President");

	try
	{
		test4.executeForm(*ptr4);
		ptr4->beSigned(test4);
		test4.increment();
		test4.executeForm(*ptr4);
		delete ptr4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete ptr4;
	}
}

int main(void)
{
	test1();
	std::cout << "\n\n\n\n";
	test2();
	std::cout << "\n\n\n\n";
	test3();

	return 0;
}
