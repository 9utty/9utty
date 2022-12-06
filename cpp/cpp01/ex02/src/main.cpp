/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:00:40 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 10:22:38 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "The momory address held by stringREF : " << &stringREF << std:: endl;
	std::cout << "====================== And then ======================" << std::endl;
	std::cout << "The value of the string variable : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;

	return 0;
}
