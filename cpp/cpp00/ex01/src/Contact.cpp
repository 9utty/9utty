/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:43:29 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 16:59:20 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	static int index = 1;
	mIndex = index;
	++index;
}

Contact::~Contact(void)
{

}

void	Contact::mSetFirstName()
{
	if (!mFirstName.empty())
		mFirstName.clear();
	std::cout << "\033[1;32mEnter at first name > \033[0m\n";
	std::getline(std::cin, mFirstName);
	if (std::cin.eof())
	{
		std::cerr << "\033[1;31mError\033[0m\n";
		std::exit(1);
	}
	if (mFirstName.empty())
		mSetFirstName();
}

void	Contact::mPrintFirstName()
{
	if (mFirstName.length() > 10)
		std::cout << " " << mFirstName.substr(0, 9) << ".";
	else
		std::cout << std::setw(11) << mFirstName;
}

void	Contact::mSetLastName()
{
	if (!mLastName.empty())
		mLastName.clear();
	std::cout << "\033[1;32mEnter at last name > \033[0m\n";
	std::getline(std::cin, mLastName);
	if (std::cin.eof())
	{
		std::cerr << "\033[1;31mError\033[0m\n";
		std::exit(1);
	}
	if (mLastName.empty())
		mSetLastName();
}

void	Contact::mPrintLastName()
{
	if (mLastName.length() > 10)
		std::cout << " " << mLastName.substr(0, 9) << ".";
	else
		std::cout << std::setw(11) << mLastName;
}

void	Contact::mSetNickName()
{
	if (!mNickName.empty())
		mNickName.clear();
	std::cout << "\033[1;32mEnter at Nickname > \033[0m\n";
	std::getline(std::cin, mNickName);
	if (std::cin.eof())
	{
		std::cerr << "\033[1;31mError\033[0m\n";
		std::exit(1);
	}
	if (mNickName.empty())
		mSetNickName();
}

void	Contact::mPrintNickName()
{
	if (mNickName.length() > 10)
		std::cout << " " << mNickName.substr(0, 9) << ".";
	else
		std::cout << std::setw(11) << mNickName;
}

void	Contact::mSetPhoneNum()
{
	if (!mPhoneNum.empty())
		mPhoneNum.clear();
	std::cout << "\033[1;32mEnter at Phone Number > \033[0m\n";
	std::getline(std::cin, mPhoneNum);
	if (std::cin.eof())
	{
		std::cerr << "\033[1;31mError\033[0m\n";
		std::exit(1);
	}
	if (mPhoneNum.empty())
		mSetPhoneNum();
}

void	Contact::mSetDarkestSecret()
{
	if (!mDarkestSecret.empty())
		mDarkestSecret.clear();
	std::cout << "\033[1;32mEnter at Darkest Secret > \033[0m\n";
	std::getline(std::cin, mDarkestSecret);
	if (std::cin.eof())
	{
		std::cerr << "\033[1;31mError\033[0m\n";
		std::exit(1);
	}
	if (mDarkestSecret.empty())
		mSetDarkestSecret();
}

t_bool	Contact::mIsEmpty()
{
	return ((t_bool)mDarkestSecret.empty());
}

int	Contact::mGetIndex()
{
	return (mIndex);
}

void	Contact::mPrintAll()
{
	std::cout << std::setw(20) << "Full Name : " << mLastName << " " << mFirstName << " (" << mNickName << ")" << std::endl;
	std::cout << std::setw(20) << "Phone Number : " << mPhoneNum << std::endl;
	std::cout << std::setw(20) << "Darkest Secret : " << mDarkestSecret << std::endl;
}
