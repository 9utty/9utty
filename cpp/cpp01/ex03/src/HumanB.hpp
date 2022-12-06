/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:25:27 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 11:24:07 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
private:
	std::string mName;
	Weapon *mWeapon;
public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif
