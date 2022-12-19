/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:05:06 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:45:37 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

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

class ClapTrap
{
protected:
	std::string mName;
	unsigned int mHitPoints;
	unsigned int mEnergyPoints;
	unsigned int mAttackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& ref);
	ClapTrap(unsigned int hp, unsigned int ep, unsigned int ad);
	ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
	ClapTrap& operator=(const ClapTrap& ref);
	virtual~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string mGetName(void) const;
	unsigned int mGetHitPoints(void) const;
	unsigned int mGetEnergyPoints(void) const;
	unsigned int mGetAttackDamage(void) const;

	void mSetName(std::string ReName);
	void mSetHitPoints(unsigned int Hit);
	void mSetEnergyPoints(unsigned int Energy);
	void mSetAttackDamage(unsigned int Damage);
};

std::ostream& operator<<(std::ostream& o, const ClapTrap& ref);

#endif
