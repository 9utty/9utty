/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:54 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 04:46:27 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Form;
# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

# define GRADE_MAX (150)
# define GRADE_MIN (1)

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BACK_RED		"\033[41m"
# define BACK_GREEN		"\033[42m"
# define BACK_YELLOW	"\033[43m"
# define BACK_MAGENTA	"\033[45m"
# define BACK_WHITE		"\033[47m"

class Bureaucrat
{
private:
	const std::string mName;
	unsigned int mGrade;

public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, const unsigned int grade);
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat& operator=(const Bureaucrat& ref);
	virtual ~Bureaucrat(void);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	void decrement(void);
	void increment(void);
	void signForm(Form& form);
	void executeForm(Form const & form);

	std::string getName(void) const;
	unsigned int getGrade(void) const;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ref);

#endif
