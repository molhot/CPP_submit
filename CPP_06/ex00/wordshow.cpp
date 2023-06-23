/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordshow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:40:10 by user              #+#    #+#             */
/*   Updated: 2023/06/24 01:55:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int ScalarConverter::_int;
char ScalarConverter::_char;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_int_overflaw = false;
bool ScalarConverter::_double_overflaw = false;
bool ScalarConverter::_float_overflaw = false;
bool ScalarConverter::_int_overflaw_minus = false;
bool ScalarConverter::_double_overflaw_minus = false;
bool ScalarConverter::_float_overflaw_minus = false;

void	ScalarConverter::show_nan()
{
	std::cout << std::endl;
	std::cout << "ch : impossible" << std::endl;
	std::cout << "int : " << "impossible" << std::endl;
	std::cout << "float : " << "nanf" << std::endl;
	std::cout << "double : " << "nan" << std::endl;
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::show_inf(const std::string &literal)
{
	if (literal.compare("+inf") == 0 || literal.compare("+inff") == 0)
	{
		std::cout << std::endl;
		std::cout << "ch : impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << "+inff" << std::endl;
		std::cout << "double : " << "+inf" << std::endl;
		std::cout << std::endl;
		std::cout << "=========================" << std::endl;
	}
	else if (literal.compare("-inf") == 0 || literal.compare("-inff") == 0)
	{
		std::cout << std::endl;
		std::cout << "ch : impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << "-inff" << std::endl;
		std::cout << "double : " << "-inf" << std::endl;
		std::cout << std::endl;
		std::cout << "=========================" << std::endl;
	}
}

void	ScalarConverter::ch_showswitch(char _ch)
{
	std::cout << "ch: ";
	if (std::isprint(_ch) == false)
        std::cout << "None displayable";
    else
        std::cout << "'" << _ch << "'";
    std::cout << std::endl;
}

void	ScalarConverter::int_showswitch(int _int)
{
	std::cout << "int: ";
	if (_int_overflaw == true)
		std::cout << "impossible";
    else
        std::cout << _int;
    std::cout << std::endl;
}

void	ScalarConverter::float_showswitch(float _float)
{
	std::cout << "float: ";
	if (_float_overflaw == true)
		std::cout << "+inff(overflaw)";
	else if (_float_overflaw_minus == true)
		std::cout << "-inff(overflaw)";
	else if (_float - static_cast<int>(_float) == 0)
		std::cout << _float << ".0f";
	else
		std::cout << std::to_string(_float) << "f";
	std::cout << std::endl;
}

void	ScalarConverter::double_showswitch(double _double)
{
	std::cout << "double: ";
	if (_double_overflaw == true)
		std::cout << "+inf(overflaw)";
	else if (_double_overflaw_minus == true)
		std::cout << "-inff(overflaw)";
	else if (_double - static_cast<int>(_double) == 0)
		std::cout << _double << ".0";
	else
		std::cout << std::to_string(_double);
	std::cout << std::endl;
}

void	ScalarConverter::ch_show(const std::string &literal)
{
	_char = literal[0];
	_int = static_cast<int>(_char);
	_double = static_cast<double>(_char);
	_float = static_cast<float>(_char);
	
	std::cout << std::endl;
	ch_showswitch(_char);
	int_showswitch(_int);
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::int_show(const std::string &literal)
{
	try
	{
		_int = std::stoi(literal);
		_char = static_cast<char>(_int);
		_double = static_cast<double>(_int);
		_float = static_cast<float>(_int);
	}
	catch(const std::exception& e)
	{
		_int = 0;
		_int_overflaw = true;
		_char = 0;
		try
		{
			_double = std::stod(literal + ".0");
		}
		catch(const std::exception& e)
		{
			_double = 0.0;
			if (literal[0] != '-')
				_double_overflaw_minus = true;
			else
				_double_overflaw = true;
		}
		try
		{
			_float = std::stof(literal + ".0f");
		}
		catch(const std::exception& e)
		{
			_float = 0.0;
			if (literal[0] == '-')
				_float_overflaw_minus = true;
			else
				_float_overflaw = true;
		}
	}
	std::cout << std::endl;
	ch_showswitch(_char);
	int_showswitch(_int);
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::float_show(const std::string &literal)
{
	try
	{
		_float = std::stof(literal);
		try
		{
			std::stoi(literal);
			_int = static_cast<int>(_float);
			if (_float - _int == 0)
				_char = static_cast<char>(_int);
			else
				_char = 0;
		}
		catch(const std::exception& e)
		{
			_int = 0;
			_int_overflaw = true;
			_char = 0;
		}
		_double = static_cast<double>(_float);
	}
	catch(const std::exception& e)
	{
		_float = 0.0;
		_int = 0;
		_char = 0;
		if (literal[0] == '-')
		{
			_float_overflaw_minus = true;
			_int_overflaw_minus = true;
		}
		else
		{
			_float_overflaw = true;
			_int_overflaw = true;
		}
		try
		{
			_double = std::stod(literal);
		}
		catch(const std::exception& e)
		{
			_double = 0.0;
			if (_float_overflaw == true)
				_double_overflaw = true;
			else
				_double_overflaw_minus = true;
		}
	}
	std::cout << std::endl;
	ch_showswitch(_char);
	int_showswitch(_int);
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}

void	ScalarConverter::double_show(const std::string &literal)
{
	try
	{
		_double = std::stod(literal);
		try
		{
			std::stoi(literal);
			_int = static_cast<int>(_double);
			if (_double - _int == 0)
				_char = static_cast<char>(_int);
			else
				_char = 0;
		}
		catch(const std::exception& e)
		{
			std::cout << "here" << std::endl;
			_int = 0;
			_int_overflaw = true;
			_char = 0;
		}
		try
		{
			std::stof(literal);
			_float = static_cast<float>(_double);
		}
		catch(const std::exception& e)
		{
			_float = 0.0;
			if (literal[0] == '+')
				_float_overflaw = true;
			else
				_float_overflaw = false;
		}
	}
	catch(const std::exception& e)
	{
		_int = 0;
		_int_overflaw = true;
		_double = 0;
		_float = 0;
		_char = 0;
		if (literal[0] != '-')
		{
			_double_overflaw = true;
			_float_overflaw = true;
		}
		else
		{
			_double_overflaw_minus = true;
			_float_overflaw_minus = true;
		}
	}
	std::cout << std::endl;
	ch_showswitch(_char);
	int_showswitch(_int);
	float_showswitch(_float);
	double_showswitch(_double);
	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
}