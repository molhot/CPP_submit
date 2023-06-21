/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordch.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:40:48 by user              #+#    #+#             */
/*   Updated: 2023/06/20 23:37:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

bool	ScalarConverter::check_literal_char(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (std::isalpha(literal[0]) == false)
		return (false);
	if (std::isprint(literal[0]) == false)
		return (false);
	return (true);
}

bool	ScalarConverter::check_literal_int(const std::string &literal)
{
	size_t	pos;
	size_t	literal_len;

	pos = 0;
	literal_len = literal.length();
	if (literal[pos] == '-' || literal[pos] == '+')
		pos++;
	while (pos != literal_len)
	{
		if (std::isdigit(literal[pos]) == false)
			return (false);
		pos++;
	}
	return (true);
}

bool	ScalarConverter::check_literal_double(const std::string &literal)
{
	size_t	coron_pos;
	size_t	pos;
	size_t	literal_len;

	if (literal.compare("-inf") == 0 || literal.compare("+inf") == 0 || literal.compare("nan") == 0)
		return (true);
	literal_len = literal.length();
	coron_pos = literal.find('.');
	if (coron_pos == std::string::npos || coron_pos == 0 || coron_pos == literal_len - 1)
		return (false);
	if (count_coronnum(literal) != 1)
		return (false);
	pos = 0;
	if (literal[pos] == '-' || literal[pos] == '+')
		pos++;
	while (pos != literal_len)
	{
		if (literal[pos] == '.')
			pos++;
		if (std::isdigit(literal[pos]) == false)
			return (false);
		pos++;
	}
	return (true);
}

bool	ScalarConverter::check_literal_float(const std::string &literal)
{
	size_t	coron_pos;
	size_t	f_pos;
	size_t	literal_len;
	size_t	pos;

	if (literal.compare("-inff") == 0 || literal.compare("+inff") == 0 || literal.compare("nanf") == 0)
		return (true);
	coron_pos = literal.find('.');
	f_pos = literal.find('f');
	literal_len = literal.length();
	if (coron_pos == std::string::npos || f_pos == std::string::npos)
		return (false);
	if (coron_pos == 0 || coron_pos == literal_len - 2)
		return (false);
	if (f_pos == 0 || f_pos != literal_len - 1)
		return (false);
	if (count_coronnum(literal) != 1)
		return (false);
	if (count_fnum(literal) != 1)
		return (false);
	pos = 0;
	if (literal[pos] == '-' || literal[pos] == '+')
		pos++;
	while (pos != literal_len - 1)
	{
		if (literal[pos] == '.')
			pos++;
		if (std::isdigit(literal[pos]) == false)
			return (false);
		pos++;
	}
	return (true);
}

//~~helper~~//

size_t	ScalarConverter::count_coronnum(const std::string &literal)
{
	size_t	literal_len;
	size_t	pos;
	size_t	coron_num;

	literal_len = literal.length();
	pos = 0;
	coron_num = 0;
	while (pos != literal_len)
	{
		if (literal[pos] == '.')
			coron_num++;
		pos++;
	}
	return (coron_num);
}

size_t	ScalarConverter::count_fnum(const std::string &literal)
{
	size_t	literal_len;
	size_t	pos;
	size_t	coron_num;

	literal_len = literal.length();
	pos = 0;
	coron_num = 0;
	while (pos != literal_len)
	{
		if (literal[pos] == 'f')
			coron_num++;
		pos++;
	}
	return (coron_num);
}
