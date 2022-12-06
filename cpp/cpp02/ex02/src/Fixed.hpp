/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:06:39 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 19:37:41 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int mFiexdPoint;
	static const int StockBit = 8;
public:
	Fixed(void);
	Fixed(Fixed const& rhs);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed(void);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed& operator=(Fixed const &rhs);


};


#endif
