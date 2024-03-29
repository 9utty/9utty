/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 02:23:05 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 00:20:02 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal *k = new Animal();
	delete k;

	const Animal* j = new Dog();
	std::cout << std::endl;
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << std::endl;


	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	const Animal *arr[100];
	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << "[" << i << "]" <<std::endl;
		delete arr[i];
		std::cout << std::endl;
	}

	const Dog *test = new Dog();

	std::cout << "test start" << std::endl;
	test->makeSound();
	test->mThinking("i'm hungry");
	test->makeSound();
	test->mThinking("i'm sleep~~");
	test->makeSound();
	test->mThinking("it's good");
	test->makeSound();
	test->mThinking("im hungry");
	test->makeSound();


	std::cout << std::endl;

	const Dog test2 = *test;


	std::cout << std::endl;
	test2.makeSound();

	std::cout << "*********************test1**********************" << std::endl;
	test2.mThinking("test1");
	test2.makeSound();
	std::cout << "*********************test2********************" << std::endl;
	test2.mThinking("test2");
	test2.makeSound();

	delete test;
	system("leaks Brain");
	return 0;
}
