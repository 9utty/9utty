/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:06:39 by gulee             #+#    #+#             */
/*   Updated: 2022/12/09 16:16:06 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

class Fixed
{
private:
	int mFixedPoint;
	static const int mStockBit = 8;
public:
	Fixed(void);
	Fixed(Fixed const& ref);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed(void);
	Fixed& operator=(Fixed const &ref);

	float				toFloat(void) const;
	int					toInt(void) const;
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed& 		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	Fixed	operator+ (const Fixed &ref) const;
	Fixed	operator- (const Fixed &ref) const;
	Fixed	operator* (const Fixed &ref) const;
	Fixed	operator/ (const Fixed &ref) const;
	Fixed&	operator++ (void);
	Fixed&	operator-- (void);
	Fixed	operator++ (int);
	Fixed	operator-- (int);
	bool	operator== (const Fixed &ref) const;
	bool	operator!= (const Fixed &ref) const;
	bool	operator< (const Fixed &ref) const;
	bool	operator> (const Fixed &ref) const;
	bool	operator>= (const Fixed &ref) const;
	bool	operator<= (const Fixed &ref) const;
};

std::ostream&	operator<<(std::ostream &ost, const Fixed& ref);

#endif
