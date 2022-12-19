/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:32:01 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 01:38:42 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat gulee("gulee", 1);

		std::cout << gulee;
		for (int i = 0; i < 200; ++i)
			gulee.decrement();

		std::cout << gulee;
		gulee.increment();
		std::cout << gulee;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
