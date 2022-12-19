/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:59 by gulee             #+#    #+#             */
/*   Updated: 2022/12/13 21:41:46 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a;
	ScavTrap b("gulee");

	a = b;
	std::cout << "Name :" << a.mGetName() << std::endl;
	std::cout << "Name :" << b.mGetName() << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	a.takeDamage(99);
	a.beRepaired(42);

	a.attack("gulee1");
	b.attack("gulee2");

	a.guardGate();
	b.guardGate();
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}
