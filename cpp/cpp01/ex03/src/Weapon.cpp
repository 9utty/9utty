/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:24:54 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 10:54:32 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: mType(type)
{
	std::cout << "Weapon Create >>>> " << mType << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon Delete >>>>> " << mType << " Delete." << std::endl;
}

void Weapon::setType(std::string type)
{
	this->mType = type;
}

std::string Weapon::mGetType()
{
	return this->mType;
}
