/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:16:16 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:51:05 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	: WrongAnimal()
{
	std::cout << GREEN << this->mGetType() << " : Default WrongCat Create." << RESET << std::endl;
}

WrongCat::WrongCat(std::string arg)
	: WrongAnimal(arg)
{
	std::cout << GREEN << this->mGetType() << " : WrongCat Create." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref)
	: WrongAnimal(ref.type)
{
	std::cout << BLUE << this->type << " : WrongCat Copy Create." << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
if (this != &ref)
	{
		this->mSetType(ref.mGetType());
		std::cout << BLUE << this->mGetType() << ": WrongCat Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: WrongCat Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << this->mGetType() << " : WrongCat Delete." << RESET << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << BACK_YELLOW << this->mGetType() << " : wrong? meow(?)" << RESET << std::endl;
}
