/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:56:44 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:50:19 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog")
{
	std::cout << GREEN << this->mGetType() << " : Default Dog Create." << RESET << std::endl;
}

Dog::Dog(std::string name)
	: Animal(name)
{
	std::cout << GREEN << this->mGetType() << " : Dog Create." << RESET << std::endl;
}

Dog::Dog(const Dog& ref)
	: Animal(ref.type)
{
	std::cout << BLUE << type << " : Dog Copy Create." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	if (this != &ref)
	{
		this->mSetType(ref.mGetType());
		std::cout << BLUE << this->mGetType() << ": Dog Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Dog Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

Dog::~Dog(void)
{
	std::cout << RED << this->mGetType() << " : Dog Delete." << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << BACK_GREEN << this->mGetType() << " : Bark(?)" << RESET << std::endl;
}
