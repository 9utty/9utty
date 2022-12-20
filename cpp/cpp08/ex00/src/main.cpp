/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:56:20 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 11:02:12 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> arg;
	arg.push_back(1);
	arg.push_back(2);
	arg.push_back(3);
	arg.push_back(4);
	arg.push_back(5);

	try
	{
		std::cout << easyfind(arg, 3) << std::endl;
		std::cout << easyfind(arg, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Not found" << '\n';
	}


	return 0;
}
