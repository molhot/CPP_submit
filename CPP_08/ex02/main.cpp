/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:38:07 by user              #+#    #+#             */
/*   Updated: 2023/07/01 21:46:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>

void	check_anothercontainer()
{
	std::list<int> some;

	some.push_back(5);
	some.push_back(17);

	std::cout << "top is " << some.back() << std::endl; 
	some.pop_back();
	std::cout << "size is " << some.size() << std::endl;

	some.push_back(3); 
	some.push_back(5); 
	some.push_back(737); //[...]
	some.push_back(0);

	std::cout << "top is " << some.back() << std::endl; 
	std::cout << "size is " << some.size() << std::endl;

	std::list<int>::iterator it = some.begin();
	std::list<int>::iterator ite = some.end();

	std::cout << "~~~~~" << std::endl;
	
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	copy_constructor_test(MutantStack<int> some)
{
	some.push(2000);
	MutantStack<int>::iterator it = some.begin();
	MutantStack<int>::iterator ite = some.end();

	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	copy_assignement_test(MutantStack<int> some)
{
	some.push(100);
	MutantStack<int>::iterator it = some.begin();
	MutantStack<int>::iterator ite = some.end();

	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	MutantStack<int> mstack;
	MutantStack<int> test2;

	
	mstack.push(5); 
	mstack.push(17);

	std::cout << "====== ======" << std::endl;
	test2 = mstack;
	copy_assignement_test(test2);
	std::cout << "====== ======" << std::endl;

	std::cout << "====== ======" << std::endl;
	MutantStack<int> test(mstack);
	copy_constructor_test(test);
	std::cout << "====== ======" << std::endl;
	
	std::cout << "top is " << mstack.top() << std::endl; 
	mstack.pop();
	std::cout << "size is " << mstack.size() << std::endl;
	
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737);
	mstack.push(0);

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
	std::cout << "check under" << std::endl;
	check_anothercontainer();

	system("leaks -q ex02");
	return 0;
}