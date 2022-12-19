/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:26:02 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 04:34:07 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public :
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string name);
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
	virtual ~PresidentialPardonForm(void);
	void execute(Bureaucrat const & executor) const;
};

#endif
