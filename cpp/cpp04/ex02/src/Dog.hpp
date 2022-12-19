/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:56:42 by gulee             #+#    #+#             */
/*   Updated: 2022/12/19 22:57:44 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog(void);
	Dog(std::string name);
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	virtual ~Dog(void);

	void makeSound(void) const;
	void mThinking(const std::string thinking) const;
};

#endif
