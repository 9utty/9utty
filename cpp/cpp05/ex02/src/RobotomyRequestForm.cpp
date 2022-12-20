/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:46:58 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 19:26:20 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("default", 72, 45)
{
	std::cout << GREEN << "Default RobotomyRequestForm Create." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: Form (name, 72, 45)
{
	std::cout << GREEN << this->getName() << " : RobotomyRequestForm Create." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
	: Form (ref.getName(), ref.getSignGrade(), ref.getExecGrade())
{
	std::cout << BLUE << this->getName() << " : RobotomyRequestForm Copy Create." << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << BLUE << this->getName() << ": RobotomyRequestForm Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: RobotomyRequestForm Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << this->getName() << " : RobotomyRequestForm Delete." << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (this->getSigned() != true)
		throw IsNotSignException();
	std::cout << BLUE << "RobotomyRequestForm execute create." << RESET << std::endl;
	std::cout << RED << "Drilling noises..............................." << RESET << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << GREEN << this->getName() << " has been robotomized successfully 50% of the time." << RESET << std::endl;
	else
		std::cout << RED << "informs that the robotomy failed." << RESET << std::endl;
}
