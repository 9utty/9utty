/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:08:25 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 09:56:51 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void ZombieHorde(void)
{
	Zombie 		*tmp;
	std::string name;
	std::string N;
	int			num;

	std::cout << "\033[1;34mZombie Name > \033[0m";
	if (std::getline(std::cin, name).eof())
	{
		std::cout << std::endl;
		return ;
	}

	std::cout << "\033[1;34mZombie Horde > \033[0m";
	if (std::getline(std::cin, N).eof())
	{
		std::cout << std::endl;
		return ;
	}

	num = atoi(N.c_str());
	tmp = zombieHorde(num, name);

	for(int i = 0; i < num; ++i)
	{
		tmp[i].announce();
	}
	delete[] tmp;
}

void PrintManu(void)
{
	std::cout << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "HORDE : What the Hell" << std::endl;
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
		if (cmd == "HORDE")
			ZombieHorde();
		if (cmd == "EXIT")
			return 0;
	}
	return 0;
}
