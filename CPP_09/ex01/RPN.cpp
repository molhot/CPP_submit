/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:38:17 by user              #+#    #+#             */
/*   Updated: 2023/05/20 00:02:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN constructor called" << std::endl;
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN(RPN const &sub)
{
	if (sub.stack_emptych() == false)
		this->num_stack = sub.num_stack;
	std::cout << "RPN copyconstructor called" << std::endl;
}

RPN& RPN::operator=(RPN const &sub)
{
	this->num_stack = sub.num_stack;
	std::cout << "RPN operand called" << std::endl;
	return (*this);
}

void	RPN::append(int num)
{
	this->num_stack.push(num);
}

int		RPN::obtain_top() const
{
	return (this->num_stack.top());
}

void	RPN::stack_pop()
{
	this->num_stack.pop();
}

bool	RPN::stack_emptych() const
{
	if (this->num_stack.empty() == true)
		return (true);
	return (false);
}

size_t	RPN::obtain_stacksize() const
{
	return (this->num_stack.size());
}

size_t	RPN::obtain_stacksize(RPN const &sub) const
{
	return (sub.obtain_stacksize());
}