/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:06:43 by gulee             #+#    #+#             */
/*   Updated: 2022/12/09 17:01:27 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a : ";
	std::cout << a << std::endl;
	std::cout << "++a : ";
	std::cout << ++a << std::endl;
	std::cout << "a : ";
	std::cout << a << std::endl;
	std::cout << "a++ : ";
	std::cout << a++ << std::endl;
	std::cout << "a : ";
	std::cout << a << std::endl;

	std::cout << "b : ";
	std::cout << b << std::endl;

	std::cout << "Fixed::max : ";
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c(-2.1f);
	Fixed d(-2);
	std::cout << "c * d : ";
	std::cout << c * d << std::endl;
	std::cout << "2.1f * 2.0f : ";
	std::cout << 2.1f * 2.0f<< std::endl;
	std::cout << "c > b : ";
	std::cout << (c > d) << std::endl;
	Fixed e = Fixed(4.5f);
	Fixed f = Fixed(2.0f);
	std::cout << "e / f : ";
	std::cout << (e / f) << std::endl;
}
