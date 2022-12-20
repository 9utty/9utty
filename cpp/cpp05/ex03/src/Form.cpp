/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:40:32 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 19:29:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: mName("default"), mIsSign(false), mSignGrade(150), mExecGrade(150)
{
	std::cout << GREEN << "Default Form Create." << RESET << std::endl;
}

Form::Form(const std::string name, const unsigned int sign, const unsigned int exec)
	: mName(name), mIsSign(false), mSignGrade(sign), mExecGrade(exec)
{
	if (this->mSignGrade > GRADE_MAX || this->mExecGrade > GRADE_MAX)
		throw GradeTooHighException();
	else if (this->mSignGrade < GRADE_MIN || this->mExecGrade < GRADE_MIN)
		throw GradeTooLowException();
	std::cout << GREEN << this->getName() << " : Form Create." << RESET << std::endl;
}

Form::Form(const Form& ref)
	: mName(ref.getName()), mIsSign(ref.getSigned()), mSignGrade(ref.getSignGrade()), mExecGrade(ref.getExecGrade())
{
	if (this->mSignGrade > GRADE_MAX || this->mExecGrade > GRADE_MAX)
		throw GradeTooHighException();
	else if (this->mSignGrade < GRADE_MIN || this->mExecGrade < GRADE_MIN)
		throw GradeTooLowException();
	std::cout << BLUE << this->getName() << " : Form Copy Create." << RESET << std::endl;
}

Form& Form::operator=(const Form& ref)
{
	if (this != &ref)
	{
		this->mIsSign = ref.getSigned();
		std::cout << BLUE << this->getName() << ": Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Form Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

Form::~Form(void)
{
	std::cout << RED << this->getName() << " : Form Delete." << RESET << std::endl;
}

std::string Form::getName(void) const
{
	return this->mName;
}

bool Form::getSigned(void) const
{
	return this->mIsSign;
}

unsigned int Form::getSignGrade(void) const
{
	return this->mSignGrade;
}

unsigned int Form::getExecGrade(void) const
{
	return this->mExecGrade;
}

void Form::beSigned(const Bureaucrat& ref)
{
	if (this->getSigned() == true)
		throw (IsAlreadyException());
	if (ref.getGrade() > this->mSignGrade)
		throw (GradeTooLowException());
	this->mIsSign = true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("\033[41mCan't sign it because it's high!\033[0m");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("\033[41mCan't sign it because it's low!\033[0m");
}

const char* Form::IsAlreadyException::what(void) const throw()
{
	return ("\033[41mIt's a signed Form\033[0m");
}

const char* Form::IsNotSignException::what(void) const throw()
{
	return ("\033[41mIs a not signed.\033[0m");
}

std::ostream& operator<<(std::ostream& os, const Form &ref)
{
	os << BACK_WHITE;
	os << "\tName : " << ref.getName() << std::endl;
	os << "\tIsSign : " << (ref.getSigned() ? "Signed." : "Not Signed.") << std::endl;
	os << "\tSignGrade : " << ref.getSignGrade() << std::endl;
	os << "\tExecGrade : " << ref.getExecGrade() << std::endl;
	os << RESET;

	return os;
}
