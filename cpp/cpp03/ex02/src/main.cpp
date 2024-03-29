/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:59 by gulee             #+#    #+#             */
/*   Updated: 2022/12/13 21:41:20 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap a;
	FragTrap b("gulee");

	a = b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "Name : " <<b.mGetName() << std::endl;

	a.takeDamage(20);
	a.beRepaired(1);

	a.attack("gulee1");
	b.attack("gulee2");

	a.highFivesGuys();
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
}
