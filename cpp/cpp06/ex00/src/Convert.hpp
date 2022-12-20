/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:55:47 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 08:25:13 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cmath>
#include <iomanip>
#include <exception>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BACK_RED		"\033[41m"
# define BACK_GREEN		"\033[42m"
# define BACK_YELLOW	"\033[43m"
# define BACK_MAGENTA	"\033[45m"
# define BACK_WHITE		"\033[47m"

class Convert
{
private:
	double value;
	char* ptr;

public:
	Convert(void);
	Convert(char* argv);
	Convert(const Convert& ref);
	Convert& operator=(const Convert& ref);
	virtual ~Convert(void);

	void toChar(void);
	void toInt(void);
	void toFloat(void);
	void toDouble(void);

};

#endif
