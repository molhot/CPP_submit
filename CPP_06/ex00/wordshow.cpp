/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordshow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:40:10 by user              #+#    #+#             */
/*   Updated: 2023/06/21 11:21:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int ScalarConverter::_int;
char ScalarConverter::_char;
float ScalarConverter::_float;
double ScalarConverter::_double;

void	ScalarConverter::ch_showswitch(char _ch)
{
	std::cout << "ch: ";
	if (std::isprint(_ch) == false)
        std::cout << "None displayable";
    else
        std::cout << "'" << _ch << "'";
    std::cout << std::endl;
}

void	ScalarConverter::float_showswitch(float _float)
{
	std::cout << "float: ";
	if (_float - static_cast<int>(_float) == 0)
		std::cout << _float << ".0f";
	else
		std::cout << _float << "f";
	std::cout << std::endl;
}

void	ScalarConverter::double_showswitch(double _double)
{
	std::cout << "double: ";
	if (_double - static_cast<int>(_double) == 0)
		std::cout << _double << ".0";
	else
		std::cout << _double;
	std::cout << std::endl;
}

void	ScalarConverter::ch_show(const std::string &literal)
{
	_char = literal[0];
	_int = static_cast<int>(_char);
	_double = static_cast<double>(_char);
	_float = static_cast<float>(_char);
	
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;
	ch_showswitch(_char);
	std::cout << "int is " << _int << std::endl;
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::int_show(const std::string &literal)
{
	_int = std::stoi(literal);
	_char = static_cast<char>(_int);
	_double = static_cast<double>(_int);
	_float = static_cast<float>(_int);
	
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;
	ch_showswitch(_char);
	std::cout << "int is " << _int << std::endl;
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::float_show(const std::string &literal)
{
	_float = std::stof(literal);
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
	
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;
	ch_showswitch(_char);
	std::cout << "int is " << _int << std::endl;
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::double_show(const std::string &literal)
{
	_double = std::stod(literal);
	_float = static_cast<float>(_double);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;
	ch_showswitch(_char);
	std::cout << "int is " << _int << std::endl;
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}