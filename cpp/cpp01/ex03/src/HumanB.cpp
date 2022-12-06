/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:25:39 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 11:22:05 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: mName(name)
{
	this->mWeapon = NULL;
	std::cout << mName << " Create." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << mName << " Delete." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->mWeapon = &weapon;
}

void HumanB::attack()
{
	if (this->mWeapon == NULL)
	{
		std::cout << mName << " : What is it Weapon?" << std::endl;
		return ;
	}
	std::cout << mName << " attacks with their " << mWeapon->mGetType() << std::endl;
}
