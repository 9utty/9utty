/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:08:33 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 03:30:20 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	mSetName(name);
	std::cout << mGetName() << ": Create" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << mGetName() << ": died." << std::endl;
}

std::string Zombie::mGetName(void)
{
	return this->name;
}

void Zombie::mSetName(std::string &name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << mGetName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
