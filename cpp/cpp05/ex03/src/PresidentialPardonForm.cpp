/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:26:10 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 19:29:00 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("default", 25, 5)
{
	std::cout << GREEN << "Default PresidentialPardonForm Create." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
	: Form(name, 25, 5)
{
	std::cout << GREEN << this->getName() << " : PresidentialPardonForm Create." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
	: Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade())
{
	std::cout << BLUE << this->getName() << " : PresidentialPardonForm Copy Create." << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << BLUE << this->getName() << ": PresidentialPardonForm Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: PresidentialPardonForm Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << this->getName() << " : PresidentialPardonForm Delete." << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (this->getSigned() != true)
		throw IsNotSignException();
	std::cout << BLUE << "PresidentialPardonForm execute create." << RESET << std::endl;
	std::cout << GREEN << this->getName() << " has been pardoned by Zaphod Beebleborx." << RESET << std::endl;
}
