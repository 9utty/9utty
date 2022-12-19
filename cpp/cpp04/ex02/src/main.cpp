/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 02:23:05 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 00:19:55 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal *k = new Animal();
	k->makeSound();
	delete k;

	const Animal* j = new Dog();
	j->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;
	const Animal* i = new Cat();
	i->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;


	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;

	system("leaks abstract");

	return 0;
}
