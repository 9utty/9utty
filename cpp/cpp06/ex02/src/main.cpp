/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 08:42:21 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 09:11:55 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	A* a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << YELLOW << "Class is of type A" << RESET << std::endl;
		return ;
	}
	B* b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << BLUE << "Class is of type B" << RESET << std::endl;
		return ;
	}
	C* c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << CYAN << "Class is of type C" << RESET << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		A& tmp = dynamic_cast<A &>(p);
		std::cout << YELLOW << "Class is of type A" << RESET << std::endl;
		(void)tmp;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& tmp = dynamic_cast<B &>(p);
			std::cout << BLUE << "Class is of type B" << RESET << std::endl;
			(void)tmp;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& tmp = dynamic_cast<C &>(p);
				std::cout << CYAN << "Class is of type C" << RESET << std::endl;
				(void)tmp;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main(void)
{
	Base* randomBase = generate();
	identify(randomBase);
	identify(*randomBase);

	return 0;
}
