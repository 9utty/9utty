/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:08:33 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 09:55:12 by gulee            ###   ########.fr       */
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
	return this->mName;
}

void Zombie::mSetName(std::string name)
{
	this->mName = name;
	std::cout << mGetName() << ": Create" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << mGetName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
