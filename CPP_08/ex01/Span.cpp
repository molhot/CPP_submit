/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:14:40 by user              #+#    #+#             */
/*   Updated: 2023/07/01 18:11:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _n(0)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N): _n(N)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const &sub): _n(sub.get_n()), _array(sub._array)
{
	std::cout << "Span COPYconstructor called" << std::endl;
}

Span& Span::operator=(Span const &sub)
{
	std::cout << "Span operator called" << std::endl;
	if (this == &sub)
		return (*this);
	this->_n = sub.get_n();
	this->_array = sub._array;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span denstructor called" << std::endl;
}

unsigned int	Span::get_n() const
{
	return (this->_n);
}

void	Span::addNumber(int num)
{
	if (this->_array.size() == this->get_n())
		throw std::runtime_error("Missed because this is full");
	this->_array.push_back(num);
}

void	Span::addNumbers_random(unsigned int num)
{
	if (num > this->get_n())
		throw std::runtime_error("size is over!");
	if (num + this->get_array().size() > this->get_n())
		throw std::runtime_error("size is over!");
	std::srand(std::time(NULL));
	while (num != 0)
	{
		this->_array.push_back(std::rand());
		num--;
	}
}

unsigned int	Span::comparison_min(unsigned int left, unsigned int right)
{
	if (left >= right)
		return (right);
	else
		return (left);
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>		tmp;
	size_t					tmp_size;
	size_t					pos;
	unsigned int			tmp_diff;
	unsigned int			mini;

	if (this->get_array().size() == 0)
		throw std::runtime_error("this length is 0");
	else if (this->get_array().size() == 1)
		throw std::runtime_error("this length is 1");
	tmp = this->get_array();
	tmp_size = tmp.size();
	pos = 0;
	std::sort(tmp.begin(), tmp.end());
	mini = static_cast<unsigned int>(INT_MAX) + static_cast<unsigned int>(INT_MAX) + 1;
	while (pos != tmp_size - 1)
	{
		tmp_diff = static_cast<unsigned int>(tmp[pos + 1] - tmp[pos]);
		mini = comparison_min(mini, tmp_diff);
		pos++;
	}
	return (mini);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>	tmp;
	size_t				tmp_size;
	size_t				pos;

	if (this->get_array().size() == 0)
		throw std::runtime_error("this length is 0");
	else if (this->get_array().size() == 1)
		throw std::runtime_error("this length is 1");
	tmp = this->get_array();
	tmp_size = tmp.size();
	pos = 0;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

std::vector<int>	Span::get_array() const
{
	return (this->_array);
}
