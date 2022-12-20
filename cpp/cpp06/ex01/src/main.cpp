/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 08:10:48 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 08:26:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	uintptr_t ptr;
	Data newData;

	newData.n = 555;

	ptr = serialize(&newData);
	std::cout << BACK_GREEN << "\tptr: " << ptr << RESET << std::endl;
	std::cout.flags(std::ios::hex);
	std::cout << BACK_GREEN << "\tptr(hex): " << ptr << RESET << std::endl;
	std::cout << BACK_GREEN << "\tptr(address): " << reinterpret_cast<void *>(&newData) << RESET << std::endl;
	std::cout.unsetf(std::ios::hex);
	std::cout << BACK_MAGENTA << "\t" << deserialize(ptr)->n << RESET << std::endl;
	return 0;

}
