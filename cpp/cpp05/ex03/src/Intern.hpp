/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:44:05 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 04:50:08 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <typeinfo>

class Intern
{
public:
	Intern(void);
	Intern(const Intern& ref);
	Intern& operator=(const Intern& ref);
	virtual ~Intern(void);

	Form *makeForm(const std::string FormName, const std::string target);

	class FormNameException : public std::exception
	{
		const char* what() const throw();
	};
};

#endif
