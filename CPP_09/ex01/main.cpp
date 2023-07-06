/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:29:57 by user              #+#    #+#             */
/*   Updated: 2023/07/06 21:30:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	exec_plus(int first, int second, RPN *line)
{
	if ((first > 0 && second > 0) && INT_MAX - first < second)
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	else if ((first < 0 && second < 0) && (INT_MIN - first) > second)
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	line->append(first + second);
	return (true);
}

static bool	exec_minus(int first, int second, RPN *line)
{
	if ((first > 0 && second < 0) && INT_MAX - first < (-1 * second))
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	else if ((first < 0 && second > 0) && (INT_MIN - second) > (-1 * second))
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	line->append(second - first);
	return (true);
}

static bool	exec_times(int first, int second, RPN *line)
{
	if ((first > 0 && second > 0) && (INT_MAX / first) < second)
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	else if ((first > 0 && second < 0) && (INT_MIN / first) > second)
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	else if ((first < 0 && second > 0) && (INT_MIN / first) < second)
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	else if ((first < 0 && second < 0) && (INT_MAX / first) > second)
	{
		std::cout << "first -> " << first << " and second -> " << second << " times is over INT_MAX" << std::endl;
		return (false);
	}
	line->append(first * second);
	return (true);
}

static bool	exec_divide(int first, int second, RPN *line)
{
	if (first == 0)
	{
		std::cout << "divide zero error" << std::endl;
		return (false);
	}
	line->append(second / first);
	return (true);
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
		return (exec_plus(first, second, line));
	else if (sub == '-')
		return (exec_minus(first, second, line));
	else if (sub == '*')
		return (exec_times(first, second, line));
	else if (sub == '/')
		return (exec_divide(first, second, line));
	return (true);
}

static	void	show_stack(std::stack<int> num_stack)
{
	std::cout << "=========" << std::endl;
	while (num_stack.size() != 0)
	{
		std::cout << num_stack.top() << std::endl;
		num_stack.pop();
	}
}

static	bool exec_calc(std::string input, RPN *line)
{
	size_t		pos;
	std::string	token;

	pos = 0;
	while (input[pos] != '\0')
	{
		line->skipping_emp(input, &pos);
		if (input[pos] == '\0')
			break;
		if (line->num_ch(input[pos]) == true)
		{
			if (line->ready_numstack(input, &pos) == false)
				return (false);
		}
		else if (exec_operator(input[pos], line) == false)
			return (false);
		else
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
	if (exec_calc(argv[1], &line) == false)
		return (1);
}