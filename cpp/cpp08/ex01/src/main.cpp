/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:03:38 by gulee             #+#    #+#             */
/*   Updated: 2022/12/30 19:06:59 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	const int size = 10;
	Span test(size);
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		unsigned int num = rand() % 1000;
		test.addNumber(num);
		std::cout << num << " ";
	}
	// std::cout << "\nadd end\n";
	try
	{
		std::cout << "\nLONG IS " << test.longestSpan() << std::endl;
		std::cout << "SHORT IS " << test.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span test2(10);
	try
	{
		test2.addRandomNumber();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		std::cout << "\nLONG IS " << test2.longestSpan() << std::endl;
		std::cout << "SHORT IS " << test2.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// overflow test
	{
		Span test3(3);
		test3.addNumber(INT_MAX);
		test3.addNumber(INT_MIN);
		test3.addNumber(INT_MAX);

		std::cout << "\nLONG IS " << test3.longestSpan() << std::endl;
		std::cout << "SHORT IS " << test3.shortestSpan() << std::endl;
	}

	return (0);
}
