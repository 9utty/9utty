/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:01 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 05:11:40 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(int argc, char *argv[])
{
	Intern test;
	Form* tmp;
	Bureaucrat gulee("gulee", 5);

	if (argc != 2)
		return 1;
	try
	{
		tmp = test.makeForm(argv[1], "TEST!!");
		std::cout << *tmp << std::endl;
		gulee.executeForm(*tmp);
		delete tmp;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
