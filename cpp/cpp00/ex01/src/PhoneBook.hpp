/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:47:49 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 19:58:28 by gulee            ###   ########.fr       */
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
	int		mGetCount(void);
	void	mSetCount(void);
private :
	int		mCount;
	Contact mContact[MAX_CONTACT];
	void	mReplaceContact(std::string cmd);
	void	mSetContact(int index);
	void	mPrintContact(std::string cmd);
};

#endif
