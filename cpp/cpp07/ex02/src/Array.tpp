/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:05:17 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 10:32:28 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T> &arr)
{
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << std::endl;
	return (os);
}

template <typename T>
Array<T>::Array(void)
	: num(0), arr(new T[0])
{
	std::cout << "Array Default Create." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
	: num(n), arr(new T[n])
{
	std::cout << "Array Create." << std::endl;
}

template <typename T>
Array<T>::Array(const Array& ref)
	: num(ref.num), arr(new T[ref.num])
{
	for (unsigned int i = 0; i < num; ++i)
		this->arr[i] = ref.arr[i];
	std::cout << "Array copy Create." << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (this == &ref)
		return (*this);
	delete[] this->arr;
	this->num = ref.num;
	arr = new T[num];

	for (unsigned int i = 0; i < num; ++i)
		this->arr[i] = ref.arr[i];

	return *this;
}

template <typename T>
Array<T>::~Array<T>(void)
{
	std::cout << "Array Delete." << std::endl;
	delete[] this->arr;
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (n >= num)
		throw(OutIndexException());
	else
		return (this->arr[n]);
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= num)
		throw(OutIndexException());
	else
		return (this->arr[n]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->num);
}

template <typename T>
const char* Array<T>::OutIndexException::what(void) const throw()
{
	return ("Danger!!!!! index of out(?)");
}

#endif
