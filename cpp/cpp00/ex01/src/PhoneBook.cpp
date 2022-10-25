/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:35:02 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 20:09:36 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{

}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::mGetInfo()
{
	std::cout << "\033[1;34mEnter your command [ADD, SEARCH, EXIT]:\033[0m\n";
}

void	PhoneBook::mSetContact(int index)
{
	mContact[index].mSetFirstName();
	mContact[index].mSetLastName();
	mContact[index].mSetNickName();
	mContact[index].mSetPhoneNum();
	mContact[index].mSetDarkestSecret();
}

void	PhoneBook::mReplaceContact(std::string cmd)
{
	int	index;

	index = 0;
	if (cmd.length() == 1)
	{
		if (cmd[0] > '0' && cmd[0] < 9)
			index = cmd[0] - '0';
			mSetContact(index - 1);
			return ;
	}
	else
		std::cout << "\033[1;31mError index\033[0m\n";
		return ;
}

void	PhoneBook::mAddContact()
{
	static int	index = 0;
	std::string	cmd;

	if (index == 8)
	{
		std::cout << "\033[1;31mPhone Book list is full, \nEnter is Index number to be updated or MENU\n\033[0m > ";
		while (std::getline(std::cin, cmd))
		{
			if (std::cin.eof())
			{
				std::cerr << "\033[1;31mError\033[0m\n";
				std::exit(1);
			}
			if (cmd == "R")
				return ;
			else
			{
				mReplaceContact(cmd);
				break ;
			}
		}
	}
	else
	{
		mSetContact(index);
		++index;
	}
}

void	PhoneBook::mPrintContact(std::string cmd)
{
	int	index;

	index = 0;
	if (cmd.length() == 1)
	{
		if (cmd[0] > '0' && cmd[0] < '9')
		{
			index = (cmd[0] - '0') - 1;
			mContact[index].mPrintAll();
			return ;
		}

	}
}

int		PhoneBook::mGetCount()
{
	return this->mCount;
}

void	PhoneBook::mSetCount()
{
	if (this->mCount < 8)
		this->mCount += 1;
}

void	PhoneBook::mPrintContact()
{
	std::string cmd;
	int			tmp;

	std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|      index| First name|  Last name|   Nickname|" << std::endl;
    std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
	if (mContact[0].mIsEmpty())
	{
	    std::cout << "|                      \033[1;31mEMPTY\033[0m                    |" << std::endl;
        std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
        return;
	}
	for (int i = 0; i < 8; ++i)
	{
		if (mContact[i].mIsEmpty())
			break ;
		std::cout << "|" << std::setw(11) << mContact[i].mGetIndex() << "|";
		mContact[i].mPrintFirstName();
		std::cout << "|";
		mContact[i].mPrintLastName();
		std::cout << "|";
		mContact[i].mPrintNickName();
		std::cout << "|" << std::endl;
        std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
	}
	std::cout << "\033[1;31mIndex Number Enther > \033[0m";
	while (std::getline(std::cin, cmd)) {
		tmp = atoi(cmd.c_str());
		if (tmp > mGetCount() || tmp > 8)
		{
			std::cout << "\033[1;31mError Not Index Empty or Index Error" << std::endl;
			std::cout << "\033[1;31mIndex Number Enther > \033[0m";
			continue ;
		}
		if (std::cin.eof())
		{
            std::cerr << "\033[1;31mPressed Ctrl-D..exit\033[0m\n";
            exit(0);
        }
		if (cmd == "R")
		{
			return ;
		}
		else
		{
			tmp = atoi(cmd.c_str());
			if (tmp <= mGetCount() && tmp <= 8)
           		mPrintContact(cmd);
			std::cout << "\033[1;31mIndex Number Enther > \033[0m";
        }
	}
}

void PhoneBook::mPrintMenu(void)
{
	std::cout << std::endl;
	std::cout << "ADD : Add a new contact" << std::endl;
	std::cout << "SEARCH : Search for a contact" << std::endl;
	std::cout << "EXIT : Program Exit." << std::endl;
}
