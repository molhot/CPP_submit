/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:38:55 by user              #+#    #+#             */
/*   Updated: 2023/06/21 21:44:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	private:

	public:
		typedef	std::stack<T> mutantstack;
		typedef typename mutantstack::container_type::iterator iterator;
		
		MutantStack(): mutantstack()
		{
			std::cout << "Mutant stack constructor called" << std::endl;
		}
		~MutantStack()
		{
			std::cout << "Mutant stack destructor called" << std::endl;
		}
		MutantStack(MutantStack const &sub):mutantstack(sub)
		{
			std::cout << "Mutant stack constructor called" << std::endl;
		}
		MutantStack &operator=(MutantStack const &sub)
		{
			if (this == &sub)
				return (*this);
			this->c = sub.c;
			return (*this);
		}
		iterator begin()
		{
			//mutantstack::d.begin(); d is not exist
			return (mutantstack::c.begin());
		}
		iterator end()
		{
			return (mutantstack::c.end());
		}
};

#endif