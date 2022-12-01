/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:48 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 16:55:52 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void PrintManu(void)
{
	std::cout << std::endl;
	std::cout << "\033[43m  =============================================  \033[0m" << std::endl;
	std::cout << "\033[43m  CMD : CMD PLZ...(INFO, DEBUG, WARNING, ERROR)  \033[0m" << std::endl;
	std::cout << "\033[43m  R : Previous Steps                             \033[0m" << std::endl;
	std::cout << "\033[43m  EXIT : Program Exit                            \033[0m" << std::endl;
	std::cout << "\033[43m =============================================   \033[0m" << std::endl;
}

void Auto(Harl &harl)
{
	harl.complain("info");
	harl.complain("debug");
	harl.complain("warning");
	harl.complain("error");
}

void Gogo(Harl &harl)
{
	std::string cmd;

	while (1)
	{
		PrintManu();
		std::cout << std::endl;
		std::cout << "\033[1;47m GetCMD  >> \033[0m";
		if (std::getline(std::cin, cmd).eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "INFO")
			harl.complain("info");
		else if (cmd == "DEBUG")
			harl.complain("debug");
		else if (cmd == "WARNING")
			harl.complain("warning");
		else if (cmd == "ERROR")
			harl.complain("error");
		else if (cmd == "R")
			return ;
		else if (cmd == "EXIT")
			exit(0);
		else
			std::cout << "\033[31mInvalid Command.\033[0m" << std::endl;
	}
}

int main(void)
{
	Harl harl;
	std::string cmd;

	while (1)
	{
		std::cout << std::endl;
		std::cout << "\033[46m  ==================================  \033[0m" << std::endl;
		std::cout << "\033[46m  A : Auto Simulation                 \033[0m" << std::endl;
		std::cout << "\033[46m  G : Select Simulation               \033[0m" << std::endl;
		std::cout << "\033[46m  EXIT : Program Exit                 \033[0m" << std::endl;
		std::cout << "\033[46m  ==================================  \033[0m" << std::endl;

		std::cout << std::endl;
		std::cout << "\033[1;47m GetCMD  >> \033[0m";
		if (std::getline(std::cin, cmd).eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "A")
			Auto(harl);
		else if (cmd == "G")
			Gogo(harl);
		else if (cmd == "EXIT")
			return (0);
		else
			std::cout << "\033[31mInvalid Command.\033[0m" << std::endl;
	}
	return 0;
}
