/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:15 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:46:23 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap(void);
	ScavTrap(const ScavTrap& ref);
	ScavTrap(const std::string& Name);
	virtual~ScavTrap();
	ScavTrap& operator=(const ScavTrap& ref);

	void attack(const std::string& Name);
	void guardGate(void);
};

#endif
