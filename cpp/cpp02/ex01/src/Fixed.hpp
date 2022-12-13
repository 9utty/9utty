/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:05:25 by gulee             #+#    #+#             */
/*   Updated: 2022/12/09 15:01:18 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <cstdlib>

class Fixed
{
private:
	int mFixedPoint;
	static const int mStockBit = 8;
public:
	Fixed(void);
	Fixed(Fixed const& src);
	Fixed& operator=(Fixed const& rhs);
	virtual ~Fixed(void);
	Fixed(const int n);
	Fixed(const float n);

	float				toFloat(void) const;
	int					toInt(void) const;
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream &ost, const Fixed& ref);

#endif
