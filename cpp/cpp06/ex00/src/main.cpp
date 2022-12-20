/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:55:05 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 08:01:32 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << BACK_RED << "Check argument number" << RESET << std::endl;
		return 1;
	}
	try
	{
		Convert conv(argv[1]);
		conv.toChar();
		conv.toInt();
		conv.toFloat();
		conv.toDouble();
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return 0;
}
