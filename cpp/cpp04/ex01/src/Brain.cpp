/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:38:55 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 02:14:15 by gulee            ###   ########.fr       */
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
	mSetIdeas(ref);
	std::cout << BLUE << "Brain Copy Create." << RESET << std::endl;
}

Brain::~Brain(void)
{
	std::cout << RED << " Brain Delete." << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	if (this != &ref)
	{
		mSetIdeas(ref);
		std::cout << BLUE << "Brain Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: Brain Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
	return *this;
}

std::string* Brain::mGetIdeas(void)
{
	return this->ideas;
}

void Brain::mSetIdeas(const Brain& ref)
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
}

void Brain::mThinking(const std::string idea)
{
	if (this->mIdeasIndex == IDEA_MAX)
		std::cout << RED << "Error : Brain is full......." << RESET <<std::endl;
	else
		this->ideas[this->mIdeasIndex++].assign(idea);
}

void Brain::mShowAllIdea(void) const
{
	for (int i = 0; i < this->mIdeasIndex; ++i)
	{
		std::cout << BACK_GREEN << this->ideas[i] << RESET <<std::endl;
	}
}
