/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:08:29 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 03:30:16 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	virtual ~Zombie();
	std::string mGetName(void);
	void mSetName(std::string &name);
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
