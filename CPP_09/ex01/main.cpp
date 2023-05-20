/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:29:57 by user              #+#    #+#             */
/*   Updated: 2023/05/20 13:42:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static	bool append_num_tostack(std::string string, RPN *line)
{
	try
	{
		line->append(std::stoi(string));
	}
	catch(const std::exception& e)
	{
		std::cout << "input is wrong, your input " << string << " is not good for int" << std::endl;
		return (false);
	}
	return (true);
}

static	bool operator_ch(char sub)
{
	if (sub == '+' || sub == '-' || sub == '*' || sub == '/')
		return (true);
	return (false);
}

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
		exec_divide(first, second, line);
	return (true);
}

static	bool input_int_ch(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (true);
	return (false);
}

static	bool input_ch(char ch)
{
	if (input_int_ch(ch) == true)
		return (true);
	if (operator_ch(ch) == true)
		return (true);
	if (ch == ' ')
		return (true);
	return (false);
}

static	bool not_good_input(char ch)
{
	std::cout << "this input word " << ch << " is not good" << std::endl;
	std::cout << "please input int or [+, -, *, /]" << std::endl;
	return (false);
}

static	bool string_split(std::string input, RPN *line)
{
	size_t		pos;
	std::string	token;

	pos = 0;
	while (input[pos] != '\0')
	{
		if (input_ch(input[pos]) == false)
			return (not_good_input(input[pos]));
		if (input_int_ch(input[pos]) == true)
		{
			while(input_int_ch(input[pos]) == true)
				token = token + input[pos++];
			append_num_tostack(token, line);
			token = "";
		}
		if (operator_ch(input[pos]) == true)
		{
			if (exec_operator(input[pos], line) == false)
				return (false);
			pos++;
		}
		if (input[pos] == '\0')
			break;
		if (input[pos] != ' ')
		{
			std::cout << "you must separate int or operator with [ ]" << std::endl;
			return (false);
		}
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
	RPN line;

	if (argc != 2)
	{
		std::cout << "you must write calculator" << std::endl;
		return (1);
	}
	if (string_split(argv[1], &line) == false)
		return (1);
}