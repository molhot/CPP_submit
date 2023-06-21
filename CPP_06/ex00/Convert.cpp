/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:51:14 by user              #+#    #+#             */
/*   Updated: 2023/06/21 12:01:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	ScalarConverter::convert(const std::string &literal)
{
	std::cout << "--------------" << std::endl;
	std::cout << "input >> " << literal << std::endl;
	std::cout << "--------------" << std::endl;
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
	{
		show_nan();
		return ;
	}
	else if (literal.compare("+inff") == 0 || literal.compare("+inf") == 0 || literal.compare("-inff") == 0 || literal.compare("-inf") == 0)
	{
		show_inf(literal);
		return ;
	}
	else if (check_literal_char(literal) == true)
	{
		std::cout << "this is char" << std::endl;
		ch_show(literal);
	}
	else if (check_literal_int(literal) == true)
	{
		std::cout << "this is int" << std::endl;
		int_show(literal);
	}
	else if (check_literal_float(literal) == true)
	{
		std::cout << "this is float" << std::endl;
		float_show(literal);
	}
	else if (check_literal_double(literal) == true)
	{
		std::cout << "this is double" << std::endl;
		double_show(literal);
	}
	else
	{
		std::cout << std::endl;
		std::cout << "ch : impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << "impossible" << std::endl;
		std::cout << "double : " << "impossible" << std::endl;
		std::cout << std::endl;
		std::cout << "=========================" << std::endl;
	}
}