/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:39:54 by gulee             #+#    #+#             */
/*   Updated: 2022/12/14 02:06:51 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

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

# define IDEA_MAX (100)
class Brain
{
public:
	std::string ideas[IDEA_MAX];
	int mIdeasIndex;

	Brain(void);
	Brain(const Brain& ref);
	virtual ~Brain(void);
	Brain& operator=(const Brain& ref);

	std::string* mGetIdeas(void);
	void mSetIdeas(const Brain& ref);
	void mThinking(const std::string idea);
	void mShowAllIdea(void) const;
};

#endif
