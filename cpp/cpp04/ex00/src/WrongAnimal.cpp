/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:04:20 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:50:43 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	: type("")
{
	std::cout << GREEN << "Default WrongAnimal Create." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string arg)
	: type(arg)
{
	std::cout << GREEN << this->mGetType() << " : WrongAnimal Create." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
	: type(ref.type)
{
	std::cout << BLUE << type << " : WrongAnimal Copy Create." << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	if (this != &ref)
	{
		this->mSetType(ref.mGetType());
		std::cout << BLUE << this->mGetType() << ": WrongAnimal Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: WrongAnimal Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << this->mGetType() << " : WrongAnimal Delete." << RESET << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << BACK_MAGENTA << "WrongAnimal makeSound()" << RESET << std::endl;
}

std::string WrongAnimal::mGetType(void) const
{
	return this->type;
}

void WrongAnimal::mSetType(std::string arg)
{
	this->type = arg;
}
