/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:53:55 by gulee             #+#    #+#             */
/*   Updated: 2022/12/29 16:29:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try{
		Array<int> b(5);
		b[0] = 1;
		b[1] = 2;
		b[2] = 3;
		b[3] = 4;
		b[4] = 5;
		std::cout << b << std::endl;
		b[5] = 6;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		Array<std::string> c;
		std::cout << c.size() << std::endl;
		std::cout << c[0] << std::endl;
	}
	catch (std::exception& e){
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try{
		Array<std::string> c(4);
		Array<std::string> d(c);
		Array<std::string> e;
		e = d;
		d[0] = "Construction";
		d[1] = "by";
		d[2] = "copy";
		d[3] = "good";
		std::cout << d << std::endl;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
