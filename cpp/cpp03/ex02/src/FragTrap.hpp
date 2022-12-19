/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:07:04 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 01:49:01 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
	FragTrap(void);
	FragTrap(const FragTrap& ref);
	FragTrap(const std::string& Name);
	virtual~FragTrap(void);
	FragTrap& operator=(const FragTrap& ref);

	void attack(const std::string& Name);
	void highFivesGuys(void);
};

#endif
