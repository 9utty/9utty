/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:56 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:45:28 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: mName(""), mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
{
	std::cout << GREEN << "Default ClapTrap Create." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: mName(name), mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
{
	std::cout << GREEN << this->mGetName() << " : ClapTrap Create." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
	: mName(ref.mName), mHitPoints(ref.mHitPoints), mEnergyPoints(ref.mEnergyPoints), mAttackDamage(ref.mAttackDamage)
{
	std::cout << BLUE << "Copy Create." << RESET << std::endl;
}

ClapTrap::ClapTrap(unsigned int hp, unsigned int ep, unsigned int ad)
	: mName(""), mHitPoints(hp), mEnergyPoints(ep), mAttackDamage(ad)
{
	std::cout << GREEN << this->mGetName() << " : ClapTrap Create." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad)
	: mName(name), mHitPoints(hp), mEnergyPoints(ep), mAttackDamage(ad)
{
	std::cout << GREEN << this->mGetName() << " : ClapTrap Create." << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	if (this != &ref)
	{
		this->mSetName(ref.mGetName());
		this->mSetHitPoints(ref.mGetHitPoints());
		this->mSetEnergyPoints(ref.mGetEnergyPoints());
		this->mSetAttackDamage(ref.mGetAttackDamage());
		std::cout << BLUE << "Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Insert FAIL." << RESET << std::endl;
		return *this;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << this->mGetName() << " : ClapTrap Delete." << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->mGetHitPoints() == 0)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << "Can not attack. (HitPoints zero)" << RESET << std::endl;
		return ;
	}
	if (this->mGetEnergyPoints() == 0)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << " : Can not attack. (EnergyPoints zero)" << RESET << std::endl;
		return ;
	}
	std::cout << MAGENTA << "ClapTrap " << this->mGetName() << " attacks" << target << ", causing " << this->mGetAttackDamage() << " point of damage!" << RESET <<std::endl;
	this->mSetEnergyPoints(this->mGetEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->mGetHitPoints() == 0)
	{
		std::cout << BACK_RED << "Error >> " << this->mGetName() << "Can not takeDamage. (HitPoints zero)" << RESET << std::endl;
		return ;
	}
	this->mSetHitPoints((this->mGetHitPoints() > amount) ? (this->mGetHitPoints() - amount) : 0);
	std::cout << MAGENTA << this->mGetName() << ": Take damage amount (" << amount << ")!" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
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
	this->mSetHitPoints((this->mGetHitPoints() + amount > this->mGetHitPoints()) ? (this->mGetHitPoints() + amount) : (UINT_MAX));
}

std::string ClapTrap::mGetName(void) const
{
	return (this->mName);
}

unsigned int ClapTrap::mGetHitPoints(void) const
{
	return (this->mHitPoints);
}

unsigned int ClapTrap::mGetEnergyPoints(void) const
{
	return (this->mEnergyPoints);
}

unsigned int ClapTrap::mGetAttackDamage(void) const
{
	return (this->mAttackDamage);
}

void ClapTrap::mSetName(std::string ReName)
{
	this->mName.assign(ReName);
}

void ClapTrap::mSetHitPoints(unsigned int Hit)
{
	this->mHitPoints = Hit;
}

void ClapTrap::mSetEnergyPoints(unsigned int Energy)
{
	this->mEnergyPoints = Energy;
}

void ClapTrap::mSetAttackDamage(unsigned int Damage)
{
	this->mAttackDamage = Damage;
}

std::ostream& operator<<(std::ostream& o, const ClapTrap& ref)
{
	o << std::endl;
	o << BACK_WHITE;
	o << "========================================================" << std::endl;
	o << "          Name : " << ref.mGetName() << std::endl;
	o << "     HitPoints : " << ref.mGetHitPoints() << std::endl;
	o << "  EnergyPoints : " << ref.mGetEnergyPoints() << std::endl;
	o << "  AttackDamage : " << ref.mGetAttackDamage() << std::endl;
	o << "========================================================"<< std::endl;
	o << RESET;

	return o;
}
