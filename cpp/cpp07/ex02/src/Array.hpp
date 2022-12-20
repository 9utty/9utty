/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:54:03 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 10:37:22 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <execution>
# include <iostream>
# include <new>

template <typename T>
class Array
{
private:
	unsigned int num;
	T *arr;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array& ref);
	Array& operator=(const Array &ref);
	virtual ~Array(void);

	T& operator[](unsigned int n);
	const T& operator[](unsigned n) const;

	unsigned int size(void) const;

	class OutIndexException : public std::exception
	{
		const char* what(void) const throw();
	};
};

#include "Array.tpp"

#endif
