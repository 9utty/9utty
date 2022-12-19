/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:56:44 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 00:14:04 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog")
{
	this->brain = new Brain();
	std::cout << GREEN << this->mGetType() << " : Default Dog Create." << RESET << std::endl;
}

Dog::Dog(std::string name)
	: Animal(name)
{
	this->brain = new Brain();
	std::cout << GREEN << this->mGetType() << " : Dog Create." << RESET << std::endl;
}

Dog::Dog(const Dog& ref)
	: Animal(ref)
{
	this->brain = new Brain();
	*(this->brain) = *(ref.brain);
	std::cout << BLUE << type << " : Dog Copy Create." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	if (this != &ref)
	{
		this->type = ref.type;
		*(this->brain) = *(ref.brain);
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
	delete this->brain;
	std::cout << RED << this->mGetType() << " : Dog Delete." << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	if (this->brain->mIdeasIndex != 0)
	{
		for (int i = 0; i < this->brain->mIdeasIndex; ++i)
		{
			std::cout << BACK_WHITE << this->brain->ideas[i] << RESET << std::endl;
		}
	}
	std::cout << BACK_GREEN << this->mGetType() << " : Bark(?)" << RESET << std::endl;
}

void Dog::mThinking(const std::string thinking) const
{
	this->brain->mThinking(thinking);
}
