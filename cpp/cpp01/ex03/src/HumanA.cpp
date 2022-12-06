/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:25:31 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 11:22:31 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: mName(name), mWeapon(weapon)
{
	std::cout << mName << " Weapon : " << mWeapon.mGetType() << " Create." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << mName << " Delete." << std::endl;
}

void HumanA::attack()
{
	std::cout << mName << " attacks with their " << mWeapon.mGetType() << std::endl;
}
