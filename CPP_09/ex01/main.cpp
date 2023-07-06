/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:29:57 by user              #+#    #+#             */
/*   Updated: 2023/07/06 19:36:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void	exec_plus(int first, int second, RPN *line)
{
	line->append(first + second);
}

static void	exec_minus(int first, int second, RPN *line)
{
	line->append(second - first);
}

static void	exec_times(int first, int second, RPN *line)
{
	line->append(first * second);
}

static void	exec_divide(int first, int second, RPN *line)
{
	line->append(second / first);
}

bool	exec_operator(char sub, RPN *line)
{
	int	first;
	int	second;

	if (line->obtain_stacksize() == 1)
	{
		std::cout << "this is not for rev porand writing" << std::endl;
		return (false);
	}
	first = line->obtain_top();
	line->stack_pop();
	second = line->obtain_top();
	line->stack_pop();
	if (sub == '+')
		exec_plus(first, second, line);
	else if (sub == '-')
		exec_minus(first, second, line);
	else if (sub == '*')
		exec_times(first, second, line);
	else if (sub == '/')
	{
		if (first == 0)
		{
			std::cout << "divide zero error" << std::endl;
			return (false);
		}
		exec_divide(first, second, line);
	}
	return (true);
}

static	bool exec_calc(std::string input, RPN *line)
{
	size_t		pos;
	std::string	token;

	pos = 0;
	while (input[pos] != '\0')
	{
		line->skipping_emp_and_int(input, &pos);
		if (exec_operator(input[pos], line) == false)
			return (false);
		pos++;
	}
	if (line->obtain_stacksize() != 1)
		std::cout << "this stack not good" << std::endl;
	else
		std::cout << "anser is " << line->obtain_top() << std::endl;
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "you must write calculator" << std::endl;
		return (1);
	}
	RPN line(argv[1]);
	if (line.get_readystatus() == false)
	{
		std::cout << "your input is incorrect" << std::endl;
		return (1);
	}
	std::cout << "cals ready" << std::endl;
	if (exec_calc(argv[1], &line) == false)
		return (1);
}