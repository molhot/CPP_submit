/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:38:17 by user              #+#    #+#             */
/*   Updated: 2023/07/06 19:40:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::skipping_emp(std::string const &line, size_t *pos)
{
	while (line[*pos] == ' ' || line[*pos] == '\t')
	{
		*pos = *pos + 1;
		if (line[*pos] == '\0')
			return ;
	}
}

void RPN::skipping_emp_and_int(std::string const &line, size_t *pos)
{
	while (line[*pos] == ' ' || line[*pos] == '\t' || num_ch(line[*pos]) == true)
	{
		*pos = *pos + 1;
		if (line[*pos] == '\0')
			break;
	}
}

bool RPN::num_ch(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (true);
	return (false);
}

bool RPN::operator_ch(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return (true);
	return (false);
}

bool RPN::check_ch(char ch, size_t *pos)
{
	if (operator_ch(ch) == false && num_ch(ch) == false)
		return (false);
	*pos = *pos + 1;
	return (true);
}

void RPN::line_ch(std::string const &line)
{
	size_t	pos = 0;

	while (line[pos] != '\0')
	{
		if (line[pos] == ' ' || line[pos] == '\t')
			skipping_emp(line, &pos);
		else if (check_ch(line[pos], &pos) == false)
		{
			this->rpn_ready = false;
			return ;
		}
	}
	this->rpn_ready = true;
}

bool RPN::int_ch(std::string const &num_str)
{
	size_t	num = 0;
	size_t	pos = 0;

	while (num_str[pos] != '\0')
	{
		num = (num * 10) + static_cast<size_t>(num_str[pos] - 48);
		pos++;
		if (num > static_cast<size_t>(INT_MAX))
			return (false);
	}
	return (true);
}

int RPN::stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    int result;
    iss >> result;
    return result;
}

bool RPN::ready_numstack(std::string const &line, size_t *pos)
{
	std::string num_string = "";

	while ('0' <= line[*pos] && line[*pos] <= '9')
	{
		num_string = num_string + line[*pos];
		*pos = *pos + 1;
	}
	std::cout << "num string is -> " << num_string << std::endl;
	if (int_ch(num_string) == false)
		return (false);

	this->num_stack.push(stringToInt(num_string));
	return (true);
}

bool RPN::ready_stack(std::string const &line)
{
	size_t	pos = 0;

	while (line[pos] != '\0')
	{
		std::cout << "pos is " << pos << std::endl;
		if (line[pos] == ' ' || line[pos] == '\t')
			skipping_emp(line, &pos);
		else if (operator_ch(line[pos]) == true)
			pos++;
		else if (num_ch(line[pos]) == true)
		{
			if (ready_numstack(line, &pos) == false)
				return (false);
		}
	}
	return (true);
}

RPN::RPN(std::string line)
{
	std::cout << "RPN constructor called" << std::endl;
	line_ch(line);
	if (this->rpn_ready == true)
	{
		std::cout << "stack func ready" << std::endl;
		this->rpn_ready = ready_stack(line);
		std::cout << "line size is " << this->obtain_stacksize() << std::endl;
	}
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

bool	RPN::get_readystatus() const
{
	return (this->rpn_ready);
}