/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:06:24 by gulee             #+#    #+#             */
/*   Updated: 2022/12/09 16:54:39 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: mFixedPoint(0)
{
	std::cout << GREEN << "Default Create." << RESET << std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
	*this = ref;
	std::cout << BLUE << "Copy Create." << RESET << std::endl;
}

Fixed::Fixed(const int n)
{
	this->mFixedPoint = (n << this->mStockBit);
	std::cout << GREEN << "Int Value Create." << RESET << std::endl;
}

Fixed::Fixed(const float n)
{
	this->mFixedPoint = std::roundf(n * (1 << this->mStockBit));
	std::cout << GREEN << "Float Value Create." << RESET << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << RED << "Delete." << RESET << std::endl;
}

Fixed& Fixed::operator=(Fixed const& ref)
{
	std::cout << BLUE << "Operator Insert." << RESET << std::endl;
	this->setRawBits(ref.getRawBits());
	return (*this);
}

float Fixed::toFloat(void) const
{
	return ((float)this->mFixedPoint / (float)(1 << this->mStockBit));
}

int Fixed::toInt(void) const
{
	return (this->mFixedPoint >> this->mStockBit);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a.mFixedPoint < b.mFixedPoint ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.mFixedPoint < b.mFixedPoint ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a.mFixedPoint > b.mFixedPoint ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.mFixedPoint > b.mFixedPoint ? a : b);
}

int	Fixed::getRawBits(void) const
{
	return this->mFixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->mFixedPoint = raw;
}

Fixed Fixed::operator+ (const Fixed &ref) const
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed Fixed::operator- (const Fixed &ref) const
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed Fixed::operator* (const Fixed &ref) const
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed Fixed::operator/ (const Fixed &ref) const
{
	if (ref.toInt() != 0)
	{
		return (Fixed(this->toFloat() / ref.toFloat()));
	}
	else
	{
		std::cout << BACK_RED << "Divison Impossible." << RESET << std::endl;
		return (Fixed(this->toFloat()));
	}
}

Fixed& Fixed::operator++ (void)
{
	this->mFixedPoint += 1;
	return *this;
}

Fixed& Fixed::operator-- (void)
{
	this->mFixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator++ (int)
{
	Fixed tmp(*this);
	tmp.mFixedPoint += 1;
	return tmp;
}

Fixed Fixed::operator-- (int)
{
	Fixed tmp(*this);
	tmp.mFixedPoint -= 1;
	return tmp;
}

bool Fixed::operator== (const Fixed &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool Fixed::operator!= (const Fixed &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

bool Fixed::operator< (const Fixed &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool Fixed::operator> (const Fixed &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool Fixed::operator>= (const Fixed &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool Fixed::operator<= (const Fixed &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

std::ostream& operator<<(std::ostream &ost, const Fixed& ref)
{
	ost << ref.toFloat();
	return ost;
}
