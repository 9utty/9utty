/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:41:38 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 02:18:05 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat")
{
	this->brain = new Brain();
	std::cout << GREEN << this->mGetType() << " : Default Cat Create." << RESET << std::endl;
}

Cat::Cat(std::string name)
	: Animal(name)
{
	this->brain = new Brain();
	std::cout << GREEN << this->mGetType() << " : Cat Create." << RESET << std::endl;
}

Cat::Cat(const Cat& ref)
	: Animal(ref.type)
{
	this->brain = new Brain();
	this->brain->mSetIdeas(*(ref.brain));
	std::cout << BLUE << type << " : Cat Copy Create." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	if (this != &ref)
	{
		this->mSetType(ref.mGetType());
		this->brain->mSetIdeas(*(ref.brain));
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
	delete this->brain;
	std::cout << RED << this->mGetType() << " : Cat Delete." << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << BACK_YELLOW << this->mGetType() << " : meow(?)" << RESET << std::endl;
}
