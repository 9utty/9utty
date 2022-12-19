/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:38:55 by gulee             #+#    #+#             */
/*   Updated: 2022/12/19 23:11:53 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
	: mIdeasIndex(0)
{
	std::cout << GREEN << "Default Brain Create." << RESET << std::endl;
}

Brain::Brain(const Brain& ref)
	: mIdeasIndex(0)
{
	for (int i = 0; i < ref.mIdeasIndex; ++i)
	{
		this->ideas[i].assign(ref.ideas[i]);
	}
	for (int i = ref.mIdeasIndex; i < 100; ++i)
	{
		ideas[i].clear();
	}
	this->mIdeasIndex = ref.mIdeasIndex;
	std::cout << BLUE << "Brain Copy Create." << RESET << std::endl;
}

Brain::~Brain(void)
{
	std::cout << RED << "Brain Delete." << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < ref.mIdeasIndex; ++i)
		{
			this->ideas[i].assign(ref.ideas[i]);
		}
		for (int i = ref.mIdeasIndex; i < IDEA_MAX; ++i)
		{
			ideas[i].clear();
		}
		this->mIdeasIndex = ref.mIdeasIndex;
	}
	else
	{
		std::cout << BACK_RED << "Error: Brain Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
	return *this;
}

void Brain::mThinking(const std::string thinking)
{
	this->ideas[this->mIdeasIndex].assign(thinking);
	this->mIdeasIndex += 1;
}
