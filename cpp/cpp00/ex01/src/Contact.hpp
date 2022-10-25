/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:42:53 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 16:08:49 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>

typedef enum e_bool
{
	FALSE_E,
	TRUE_E
}	t_bool;

class Contact
{
public :
	Contact();
	~Contact();
	void	mSetFirstName();
	void	mPrintFirstName();
	void	mSetLastName();
	void	mPrintLastName();
	void	mSetNickName();
	void	mPrintNickName();
	void	mSetPhoneNum();
	void	mSetDarkestSecret();
	t_bool	mIsEmpty();
	int		mGetIndex();
	void	mPrintAll();
private :
	int			mIndex;
	std::string mFirstName;
	std::string mLastName;
	std::string mNickName;
	std::string mPhoneNum;
	std::string mDarkestSecret;
};

#endif
