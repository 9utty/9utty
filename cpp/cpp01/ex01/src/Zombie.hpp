/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:14:11 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 09:22:30 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
private:
	std::string mName;
public:
	Zombie(void);
	Zombie(std::string name);
	virtual ~Zombie(void);
	void announce(void);
	std::string mGetName(void);
	void mSetName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
