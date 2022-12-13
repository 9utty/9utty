/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:59 by gulee             #+#    #+#             */
/*   Updated: 2022/12/09 18:25:32 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1;
	ClapTrap c2("c2");
	ClapTrap c3(c2);

	c1.attack("c2");
	std::cout << c1 << std::endl;

	c1.beRepaired(5000000);
	std::cout << c1 << std::endl;


	c1.beRepaired(2147483648);
	std::cout << c1 << std::endl;


	c1.beRepaired(2147483648);
	std::cout << c1 << std::endl;


	c1.beRepaired(2147483648);
	c1.beRepaired(2147483648);
	c1.beRepaired(2147483648);
	c1.beRepaired(2147483648);
	std::cout << c1 << std::endl;


	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;

	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;


	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;


	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;


	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;

	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;

	c1.attack("c3");
	std::cout << c1 << std::endl;
	std::cout << c3 << std::endl;

	return 0;
}
