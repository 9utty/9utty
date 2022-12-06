/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:05:19 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 19:06:06 by gulee            ###   ########.fr       */
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

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "\033[35mCopy assignment operator called\033[0m" << std::endl;
	if (this != &rhs)
	{
		this->mFixedPoint = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "\033[31mDestructor called\033[0m" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "\033[37mInt constructor called\033[0m" << std::endl;
	this->mFixedPoint = (n << this->mStockBit);
}

Fixed::Fixed(const float n)
{
	std::cout << "\033[36mFloat constructor called\033[0m" << std::endl;
	this->mFixedPoint = (std::roundf(n * (1 << this->mStockBit)));
}

float Fixed::toFloat(void) const
{
	return ((float)this->mFixedPoint / (float)(1 << this->mStockBit));
}

int Fixed::toInt(void) const
{
	return (this->mFixedPoint >> this->mStockBit);
}

int	Fixed::getRawBits(void) const
{
	return this->mFixedPoint;
}

void Fixed::setRawBits(const int raw)
{
	this->mFixedPoint = raw;
}

std::ostream& operator<<(std::ostream &ost, const Fixed& ref)
{
	ost << ref.toFloat();
	return ost;
}
