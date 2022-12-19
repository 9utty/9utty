/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:47:06 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 04:34:38 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "cstdlib"

class RobotomyRequestForm : public Form
{
public :
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string name);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
	virtual ~RobotomyRequestForm(void);
	void execute(Bureaucrat const & executor) const;
};

#endif
