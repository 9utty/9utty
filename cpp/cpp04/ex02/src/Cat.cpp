/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:41:38 by gulee             #+#    #+#             */
/*   Updated: 2022/12/19 23:13:18 by gulee            ###   ########.fr       */
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
	: Animal(ref)
{
	this->brain = new Brain();
	*(this->brain) = *(ref.brain);
	std::cout << BLUE << type << " : Cat Copy Create." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	if (this != &ref)
	{
		this->type = ref.type;
		*(this->brain) = *(ref.brain);
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
	for (int i = 0; i < this->brain->mIdeasIndex; ++i)
	{
		std::cout << BACK_WHITE << this->brain->ideas[i] << RESET << std::endl;
	}
	std::cout << BACK_YELLOW << this->mGetType() << " : meow(?)" << RESET << std::endl;
}

void Cat::mThinking(const std::string thinking) const
{
	this->brain->mThinking(thinking);
}
