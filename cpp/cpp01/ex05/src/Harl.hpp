/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:41 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 16:24:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warnig(void);
	void error(void);
public:
	Harl(void);
	~Harl(void);
	void complain(std::string cmd);
};

#endif
