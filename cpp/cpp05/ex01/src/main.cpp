/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:01 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 03:03:23 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test1(void)
{
	try {
		Bureaucrat test1("gulee", 2);
		Form form("form1", 1, 10);
		test1.signForm(form);
		test1.increment();
		test1.signForm(form);
		test1.decrement();
		test1.decrement();
		test1.signForm(form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void test2(void)
{
	try
	{
		Bureaucrat test2("kilee", 3);
		Form form("form2", 3, 10);
		Form form2("form3", 5, 10);

		test2.signForm(form);
		test2.decrement();
		test2.decrement();
		test2.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

int main(void)
{
	test1();
	std::cout << "\n\n\n\n";
	test2();

	return 0;
}
