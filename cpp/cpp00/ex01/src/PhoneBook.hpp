/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:47:49 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 15:54:02 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

# define MAX_CONTACT (8)

class PhoneBook
{
public :
	PhoneBook();
	~PhoneBook();
	void	mGetInfo(void);
	void	mAddContact(void);
	void	mPrintContact(void);
	void	mPrintMenu(void);
private :
	Contact mContact[MAX_CONTACT];
	void	mReplaceContact(std::string cmd);
	void	mSetContact(int index);
	void	mPrintContact(std::string cmd);
};

#endif
