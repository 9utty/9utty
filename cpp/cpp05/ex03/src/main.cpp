/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:01 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 19:45:33 by gulee            ###   ########.fr       */
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

	tmp = test.makeForm(argv[1], "TEST!!");
	std::cout << *tmp << std::endl;
	gulee.executeForm(*tmp);
	tmp->beSigned(gulee);
	gulee.executeForm(*tmp);
	delete tmp;

	return 0;
}
