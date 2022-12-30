/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:03:47 by gulee             #+#    #+#             */
/*   Updated: 2022/12/30 19:46:41 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
	:
		mData(std::vector<int>(100, 0)),
		mCurrSize(0),
		mMaxSize(100)
{
	std::cout << "Default Create." << std::endl;
}

Span::Span(const unsigned len)
	:
		mData(std::vector<int>(len, 0)),
		mCurrSize(0),
		mMaxSize(len)
{
	std::cout << "Span Create." << std::endl;
}

Span::Span(const Span &ref)
	:
		mData(ref.mData),
		mCurrSize(ref.mCurrSize),
		mMaxSize(ref.mMaxSize)
{
	std::cout << "Span Copy Create." << std::endl;
}

Span &Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		mData = ref.mData;
		mCurrSize = ref.mCurrSize;
		mMaxSize = ref.mMaxSize;
		return *this;
	}
	else
	{
		std::cout << "Error: Bureaucrat Insert Type Error! FAIL!!!!!!!!!." << std::endl;
		return *this;
	}
}

Span::~Span(void)
{
	std::cout << "Span Delete." << std::endl;
}

void Span::addNumber(const unsigned int num)
{
	if (this->mCurrSize == this->mMaxSize)
		throw NoSpaceException();
	mData[mCurrSize] = num;
	mCurrSize += 1;
}

void Span::addRandomNumber(void)
{
	std::srand(std::time(NULL));
	for(unsigned int i = this->mCurrSize; i < this->mMaxSize; ++i)
	{
		addNumber(rand());
	}
}

unsigned int Span::shortestSpan(void) const
{
	if (this->mCurrSize <= 1)
		throw NoSpanException();
	std::vector<int> tmp;
	int result[this->mMaxSize - 1];
	tmp.assign(this->mData.begin(),this->mData.end());
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), result);
	return (*std::min_element(result, result + this->mMaxSize - 1));
}

unsigned int Span::longestSpan(void) const
{
	if (this->mCurrSize <= 1)
		throw NoSpanException();

	unsigned int result = abs(*std::max_element(this->mData.begin(), this->mData.end()) - *std::min_element(this->mData.begin(), this->mData.end()));
	return result;
}

const char *Span::NoSpaceException::what() const throw() {
	return "This Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "This Span has 0 or 1 element";
}
