/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:08:25 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 03:31:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void ZombieNew(void)
{
	Zombie *tmp;
	std::string cmd;

	std::cout << "\033[1;34mZombie Name > \033[0m";
	if (std::getline(std::cin, cmd).eof())
	{
		std::cout << std::endl;
		return ;
	}

	tmp = newZombie(cmd);
	delete tmp;
}

void ZombieRandom(void)
{
	std::string cmd;

	std::cout << "\033[1;34mZombie Name > \033[0m";
	if (std::getline(std::cin, cmd).eof())
	{
		std::cout << std::endl;
		return ;
	}
	randomChump(cmd);
}

void PrintManu(void)
{
	std::cout << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "NEW : New Zombie" << std::endl;
	std::cout << "RANDOM : Random Chump!!!!" << std::endl;
	std::cout << "EXIT : Program Exit" << std::endl;
	std::cout << "==================================" << std::endl;
}

int main(void)
{
	std::string cmd;

	while (1)
	{
		PrintManu();
		std::cout << "\033[1;34mBrainzZ... > \033[0m";
		if (std::getline(std::cin, cmd).eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "NEW")
			ZombieNew();
		if (cmd == "RANDOM")
			ZombieRandom();
		if (cmd == "EXIT")
			return 0;
	}
	return 0;
}
