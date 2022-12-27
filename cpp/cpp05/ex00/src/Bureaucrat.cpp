/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:41 by gulee             #+#    #+#             */
/*   Updated: 2022/12/27 17:40:07 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: mName("default"), mGrade(150)
{
	std::cout << GREEN << "Default Bureaucrat Create." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade)
	: mName(name), mGrade(grade)
{
	if (mGrade > GRADE_MAX)
		throw GradeTooLowException();
	else if (mGrade < GRADE_MIN)
		throw GradeTooHighException();
	std::cout << GREEN << this->getName() << " : Bureaucrat Create." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
	: mName(ref.getName()), mGrade(ref.getGrade())
{
	if (this->mGrade > GRADE_MAX)
		throw GradeTooLowException();
	else if (this->mGrade < GRADE_MIN)
		throw GradeTooHighException();
	std::cout << BLUE << this->getName() << " : Bureaucrat Copy Create." << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this != &ref)
	{
		if (this->mGrade > GRADE_MAX)
			throw GradeTooLowException();
		else if (this->mGrade < GRADE_MIN)
			throw GradeTooHighException();
		this->mGrade = ref.mGrade;
		std::cout << BLUE << this->getName() << ": Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Bureaucrat Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << this->getName() << " : Bureaucrat Delete." << RESET << std::endl;
}

void Bureaucrat::decrement(void)
{
	if (this->mGrade + 1 > GRADE_MAX)
		throw GradeTooLowException();
	else if (this->mGrade < GRADE_MIN)
		throw GradeTooHighException();
	this->mGrade += 1;
	std::cout << BACK_MAGENTA << getName() << " : Decreasing grade" << RESET << std::endl;
}

void Bureaucrat::increment(void)
{
	if (this->mGrade > GRADE_MAX)
		throw GradeTooLowException();
	else if (this->mGrade - 1 < GRADE_MIN)
		throw GradeTooHighException();
	this->mGrade -= 1;
	std::cout << BACK_GREEN << getName() << " : Increasing grade" << RESET << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return this->mName;
}

unsigned int Bureaucrat::getGrade(void) const
{
	return this->mGrade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("\033[41mGrade Too High!\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("\033[41mGrade Too low!\033[0m");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref)
{
	std::cout << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
	return (os);
}
