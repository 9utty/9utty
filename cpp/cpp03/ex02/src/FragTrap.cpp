/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:57 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:49:05 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap(100, 100, 30)
{
	std::cout << GREEN << "Default FragTrap Create." << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref)
	: ClapTrap(ref.mName, ref.mHitPoints, ref.mEnergyPoints, ref.mAttackDamage)
{
	std::cout << BLUE << "Copy Create." << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& Name)
	: ClapTrap(Name, 100, 100, 30)
{
	std::cout << GREEN << this->mGetName() << " : FragTrap Create." << RESET << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	if (this != &ref)
	{
		this->mSetName(ref.mGetName());
		this->mSetHitPoints(ref.mGetHitPoints());
		this->mSetEnergyPoints(ref.mGetEnergyPoints());
		this->mSetAttackDamage(ref.mGetAttackDamage());
		std::cout << BLUE << "FragTrap Insert Finish." << RESET << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << this->mGetName() << " : FragTrap Delete." << RESET << std::endl;
}

void FragTrap::attack(const std::string& Name)
{
	std::cout << MAGENTA << "FragTrap " << this->mGetName() << " attacks " << Name << ", causing " << this->mGetAttackDamage() << " point of damage!" << RESET <<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << BACK_YELLOW << "high five!!! have a nice day!!!" << RESET << std::endl;
}
