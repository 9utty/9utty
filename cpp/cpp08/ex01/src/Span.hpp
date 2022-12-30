/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:03:54 by gulee             #+#    #+#             */
/*   Updated: 2022/12/30 19:39:51 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <exception>
# include <numeric>

class Span
{
private:
	std::vector<int> mData;
	unsigned int mCurrSize;
	unsigned int mMaxSize;

public:
	Span(void);
	Span(const unsigned int len);
	Span(const Span &ref);
	Span &operator=(const Span& ref);
	virtual ~Span(void);

	void addNumber(const unsigned int num);
	void addRandomNumber(void);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

	class NoSpaceException: public std::exception {
	public:
		const char *what() const throw();
	};

	class NoSpanException: public std::exception {
	public:
		const char *what() const throw();
	};

};

#endif
