/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:01:28 by gulee             #+#    #+#             */
/*   Updated: 2022/10/25 20:08:46 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string cmd;
	PhoneBook	PhoneBook;

	while (1)
	{
		PhoneBook.mPrintMenu();
		std::cout << "\033[1;34mPhoneBook > \033[0m";
		if (std::getline(std::cin, cmd).eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "ADD")
		{
			PhoneBook.mAddContact();
			if (PhoneBook.mGetCount() < 8)
				PhoneBook.mSetCount();
		}
		if (cmd == "SEARCH")
			PhoneBook.mPrintContact();
		if (cmd == "EXIT")
			break ;
	}
	return (0);
}
