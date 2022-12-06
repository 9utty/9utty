/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:25:36 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 10:47:08 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
private:
	std::string mName;
	Weapon &mWeapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif
