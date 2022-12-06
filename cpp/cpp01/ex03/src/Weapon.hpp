/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:24:47 by gulee             #+#    #+#             */
/*   Updated: 2022/11/29 10:47:16 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
private:
	std::string mType;
	Weapon();
public:
	Weapon(std::string type);
	~Weapon();
	void setType(std::string type);
	std::string mGetType();
};

#endif
