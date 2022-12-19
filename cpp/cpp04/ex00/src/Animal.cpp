/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:20:31 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 01:12:06 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: type("")
{
	std::cout << GREEN << "Default Animal Create." << RESET << std::endl;
}

Animal::Animal(std::string type)
	: type(type)
{
	std::cout << GREEN  << type << " : Animal Create." << RESET << std::endl;
}

Animal::Animal(const Animal& ref)
	: type(ref.type)
{
	std::cout << BLUE << type << " : Animal Copy Create." << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& ref)
{
	if (this != &ref)
	{
		this->type = ref.mGetType();
		std::cout << BLUE << this->mGetType() << ": Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Animal Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

Animal::~Animal(void)
{
	std::cout << RED << this->mGetType() << " : Animal Delete." << RESET << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << BACK_WHITE << "Animal makeSound()" << RESET << std::endl;
}

std::string Animal::mGetType(void) const
{
	return (this->type);
}

void Animal::mSetType(std::string arg)
{
	this->type = arg;
}
