/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:55:37 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 08:09:14 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void)
	: value()
{
	throw std::invalid_argument("Invalid Argument");
}

Convert::Convert(char* argv)
{
	this->value = std::strtod(argv, &(this->ptr));
	if ((this->value == 0.0 && argv[0] != '-' && argv[0] != '+' && !std::isdigit(argv[0])) \
		|| (*(this->ptr) != '\0' && std::strcmp(ptr, "f") != 0))
		throw std::invalid_argument("Invalid Argument");
	std::cout << GREEN << "Create." << RESET << std::endl;
}

Convert::Convert(const Convert& ref)
{
	(void)ref;
}

Convert& Convert::operator=(const Convert& ref)
{
	(void)ref;
	return *this;
}

Convert::~Convert(void)
{
	std::cout << "good delete." << std::endl;
}

void Convert::toChar(void)
{
	std::cout << YELLOW << "char: ";
	if (this->value > CHAR_MAX || this->value < CHAR_MIN || isnan(this->value))
		std::cout << "impossible" << RESET << std::endl;
	else if (!isprint(value))
		std::cout << "Non displayable" << RESET << std::endl;
	else
		std::cout << "\'" << static_cast<char>(value) << "\'\n" << RESET;
}

void Convert::toInt(void)
{
	std::cout << BLUE << "int: ";
	if (this->value > INT_MAX || this->value < INT_MIN || isnan(this->value))
		std::cout << "impossible" << RESET << std::endl;
	else
		std::cout << static_cast<int>(value) << RESET << std::endl;
}

void Convert::toFloat(void)
{
	std::cout << RED << "float: ";
	if ((static_cast<float>(this->value) == static_cast<int64_t>(static_cast<float>(value))) \
		&& (-100000 < static_cast<float>(value) && static_cast<float>(value) < 100000))
		std::cout << static_cast<float>(value) << ".0f" << RESET << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << RESET << std::endl;
}

void Convert::toDouble(void)
{
	std::cout << GREEN << "double: ";
	if ((static_cast<double>(this->value) == static_cast<int64_t>(static_cast<double>(value))) \
		&& (-100000 < static_cast<double>(value) && static_cast<double>(value) < 100000))
		std::cout << static_cast<double>(value) << ".0" << RESET << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << static_cast<double>(value) << RESET << std::endl;
}
