/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:05 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:46:28 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap(100, 50, 20)
{
	std::cout << GREEN << "Default ScavTrap Create." << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
	: ClapTrap(ref.mName, ref.mHitPoints, ref.mEnergyPoints, ref.mAttackDamage)
{
	std::cout << BLUE << "Copy ScavTrap Create." << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& Name)
	: ClapTrap(Name, 100, 50, 20)
{
	std::cout << GREEN << this->mGetName() << " : ScavTrap Create." << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << this->mGetName() << " : ScavTrap Delete." << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	if (this != &ref)
	{
		this->mSetName(ref.mGetName());
		this->mSetHitPoints(ref.mGetHitPoints());
		this->mSetEnergyPoints(ref.mGetEnergyPoints());
		this->mSetAttackDamage(ref.mGetAttackDamage());
		std::cout << BLUE << "ScavTrap Insert Finish." << RESET << std::endl;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& Name)
{
	if (this->mGetEnergyPoints() == 0)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << "Can not repair. (EnergyPoints zero)" << RESET << std::endl;
		return ;
	}
	if (this->mGetHitPoints() == 0 || this->mGetHitPoints() == UINT_MAX)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << "Can not repair. (HitPoints zero or UINT_MAX)" << RESET << std::endl;
		return ;
	}
	this->mSetEnergyPoints(this->mGetEnergyPoints() - 1);
	std::cout << MAGENTA << "ScavTrap " << this->mGetName() << " attacks " << Name << ", causing " << this->mGetAttackDamage() << " point of damage!" << RESET <<std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->mGetEnergyPoints() == 0)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << "Can not repair. (EnergyPoints zero)" << RESET << std::endl;
		return ;
	}
	if (this->mGetHitPoints() == 0)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << "Can not repair. (HitPoints zero or UINT_MAX)" << RESET << std::endl;
		return ;
	}
	this->mSetEnergyPoints(this->mGetEnergyPoints() - 1);
	std::cout << BACK_GREEN << "ScavTrap Special Mode : Gate keeper mode." << RESET << std::endl;
}
