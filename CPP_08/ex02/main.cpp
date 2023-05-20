/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:38:07 by user              #+#    #+#             */
/*   Updated: 2023/05/11 14:35:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5); 
	mstack.push(17);
	
	std::cout << "top is " << mstack.top() << std::endl; 
	mstack.pop();
	std::cout << "size is " << mstack.size() << std::endl;
	
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); //[...] mstack.push(0);

	std::cout << "top is " << mstack.top() << std::endl; 
	std::cout << "size is " << mstack.size() << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "~~~~~" << std::endl;
	
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack); 
	return 0;
}