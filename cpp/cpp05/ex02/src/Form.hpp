/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:40:39 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 04:36:18 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string mName;
	bool mIsSign;
	const unsigned int mSignGrade;
	const unsigned int mExecGrade;
public:
	Form(void);
	Form(const std::string name, const unsigned int sign, const unsigned int exec);
	Form(const Form& ref);
	Form& operator=(const Form& ref);
	virtual ~Form(void);

	std::string getName(void) const;
	bool getSigned(void) const;
	unsigned int getSignGrade(void) const;
	unsigned int getExecGrade(void) const;
	void beSigned(const Bureaucrat& ref);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class IsAlreadyException : public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Form &ref);

#endif
