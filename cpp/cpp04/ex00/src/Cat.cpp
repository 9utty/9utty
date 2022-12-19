/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:41:38 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:50:02 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat")
{
	std::cout << GREEN << this->mGetType() << " : Default Cat Create." << RESET << std::endl;
}

Cat::Cat(std::string name)
	: Animal(name)
{
	std::cout << GREEN << this->mGetType() << " : Cat Create." << RESET << std::endl;
}

Cat::Cat(const Cat& ref)
	: Animal(ref.type)
{
	std::cout << BLUE << type << " : Cat Copy Create." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	if (this != &ref)
	{
		this->mSetType(ref.mGetType());
		std::cout << BLUE << this->mGetType() << ": Cat Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Cat Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

Cat::~Cat(void)
{
	std::cout << RED << this->mGetType() << " : Cat Delete." << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << BACK_YELLOW << this->mGetType() << " : meow(?)" << RESET << std::endl;
}
