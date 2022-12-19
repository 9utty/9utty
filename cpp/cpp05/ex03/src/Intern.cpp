/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:43:56 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 05:11:22 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << GREEN << "Default Intern Create." << RESET << std::endl;
}

Intern::Intern(const Intern& ref)
{
	*this = ref;
	std::cout << BLUE << "\tIntern Copy Create." << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << BLUE << "\tIntern Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Intern Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
	return *this;
}

Intern::~Intern(void)
{
	std::cout << RED << "\tIntern Delete." << RESET << std::endl;
}

Form* Intern::makeForm(const std::string FormName, const std::string target)
{
	std::string formname[3] = {
		"shrubbery",
		"robotomy",
		"presidential"
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formname[i].compare(FormName) == 0)
		{
			switch (i)
			{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
			}
		}
	}

	return NULL;
}
