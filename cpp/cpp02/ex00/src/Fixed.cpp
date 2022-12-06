/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:53 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 19:05:59 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
	: mFixedPoint(0)
{
	std::cout << "\033[33mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "\033[32mCopy constructor called\033[0m" << std::endl;
	this->mFixedPoint = src.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "\033[31mDestructor called\033[0m" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "\033[35mCopy assignment operator called\033[0m" << std::endl;
	if (this != &rhs)
	{
		this->mFixedPoint = rhs.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "\033[36mgetRawBits member function called\033[0m" << std::endl;
	return this->mFixedPoint;
}

void Fixed::setRawBits(const int raw)
{
	this->mFixedPoint = raw;
}
