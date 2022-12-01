/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:43 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 16:56:42 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "\033[33mCreate.\033[0m" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "\033[31mDelete.\033[0m" << std::endl;
}

void Harl::debug(void)
{
	std::cout << std::endl;
	std::cout << "\033[42m=========================[DEBUG]=========================\033[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << std::endl;
	std::cout << "\033[43m=========================[INFO]=========================\033[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warnig(void)
{
	std::cout << std::endl;
	std::cout << "\033[45m=========================[WARNING]=========================\033[0m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << std::endl;
	std::cout << "\033[41m=========================[ERROR]=========================\033[0m" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string cmd)
{
	void (Harl::*Func[4])(void);
	{
		Func[0] = &Harl::debug;
		Func[1] = &Harl::info;
		Func[2] = &Harl::warnig;
		Func[3] = &Harl::error;
		std::string list[4] = {"debug", "info", "warning", "error"};
		for(int i = 0; i < 4; ++i)
		{
			if (list[i] == cmd)
				(this->*Func[i])();
		}
	}
}
