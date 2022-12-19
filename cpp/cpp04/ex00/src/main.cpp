/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:43:33 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 00:19:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->mGetType() << " " << std::endl;
	std::cout << i->mGetType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);

	std::cout << "\n\n\n";

	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->mGetType() << " " << std::endl;
	wrong->makeSound();

	const WrongCat* WCat = new WrongCat();
	std::cout << WCat->mGetType() << " " << std::endl;
	WCat->makeSound();

	delete(WCat);
	delete(wrong);

	system("leaks Poly");
	return 0;
}
