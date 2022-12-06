/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:49 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 19:19:43 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	mFixedPoint;
	static const int mStockBit = 8;
public:
	Fixed(void);
	Fixed(Fixed const& src);
	virtual ~Fixed(void);
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator=(Fixed const& rhs);
};

#endif
