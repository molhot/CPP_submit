/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:51:14 by user              #+#    #+#             */
/*   Updated: 2023/05/08 19:15:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static	bool spchar_ch_float(std::string sub)
{
	if (sub.compare("nanf") == 0 || sub.compare("+nanf") == 0 || sub.compare("-nanf"))
		return (true);
	if (sub.compare("inff") == 0 || sub.compare("+inff") == 0 || sub.compare("-inff"))
		return (true);
	return (false);
}

static	bool	spchar_ch_double(std::string sub)
{
	if (sub.compare("nan") == 0 || sub.compare("+nan") == 0 || sub.compare("-nan") == 0)
		return (true);
	if (sub.compare("inf") == 0 || sub.compare("+inf") == 0 || sub.compare("-inf") == 0)
		return (true);
	return (false);
}

static	std::string string_tolow(std::string sub)
{
	size_t	pos;

	pos = 0;
	while (sub[pos] != '\0')
	{
		if ('A' <= sub[pos] && sub[pos] <= 'Z')
			sub[pos] = sub[pos] + 32;
		pos++;
	}
	return (sub);
}

void	Convert::set_chartype()
{
	char	c;

	c = (this->get_sub())[0];
	this->_ch = c;
	this->ch_impossible = false;
	this->ch_notdisable = false;
	this->_nb = static_cast<int>(c);
	this->_f = static_cast<float>(c);
	this->_d = static_cast<double>(c);
}

void	Convert::set_inttype()
{
	this->_nb = std::stoi(this->get_sub());
	this->_f = static_cast<float>(this->_nb);
	this->_d = static_cast<double>(this->_nb);
	if (32 <= _nb && _nb <= 127)
		this->_ch = static_cast<char>(this->_ch);
	else
	{
		this->_ch = 0;
		this->ch_notdisable = true;
		this->ch_impossible = false;
	}
}

void	Convert::set_floattype()
{
	if (spchar_ch_float(this->get_sub()) == true)
	{
		this->_f = std::stof(this->get_sub());
		this->_d = static_cast<double>(this->_f);
		this->_ch = 0;
		this->_nb = 0;
		this->ch_impossible = true;
		this->ch_notdisable = false;
		this->int_impossible = true;
		return ;
	}
	this->_f = std::stof(this->get_sub());
	this->_nb = static_cast<int>(this->_f);
	this->int_impossible = false;
	this->_d = static_cast<double>(this->_f);
	if (32 <= this->_nb && this->_nb <= 127)
		this->_ch = static_cast<char>(this->_nb);
	else
	{
		this->_ch = 0;
		this->ch_notdisable = true;
		this->ch_impossible = false;
	}
}

void	Convert::set_doubletype()
{
	if (spchar_ch_double(this->get_sub()) == true)
	{
		this->_d = std::stod(this->get_sub());
		this->_f = static_cast<float>(this->_d);
		this->_ch = 0;
		this->_nb = 0;
		this->ch_impossible = true;
		this->ch_notdisable = false;
		this->int_impossible = true;
		return ;
	}
	this->_d = std::stod(this->get_sub());
	this->_f = static_cast<float>(this->_d);
	this->_nb = static_cast<int>(this->_d);
	this->int_impossible = false;
	if (32 <= _nb && _nb <= 127)
		this->_ch = static_cast<char>(this->_nb);
	else
	{
		this->_ch = 0;
		this->ch_notdisable = true;
		this->ch_impossible = false;
	}
}

Convert::Convert(std::string sub): _sub(string_tolow(sub)), _ch('a'), _nb(0), _f(0.0f), _d(0.0)
{
	std::cout << "Convert constructor called" << std::endl;
	if (char_ch() == CHAR)
		set_chartype();
	else if (int_ch() == INT)
		set_inttype();
	else if (float_ch() == FLOAT)
		set_floattype();
	else if (double_ch() == DOUBLE)
		set_doubletype();
}

Convert::Convert(Convert const &sub): _sub(sub.get_sub())
{
	std::cout << "Convert COPY constructor called" << std::endl;
}

Convert& Convert::operator=(Convert const &sub)
{
	if (this == &sub)
		return (*this);
	this->set_sub(sub.get_sub());
	return (*this);
}

Convert::~Convert()
{
	std::cout << "Convert destructor called" << std::endl;
}

std::string	Convert::get_sub() const
{
	return (this->_sub);
}

char	Convert::get_char() const
{
	return (this->_ch);
}

int	Convert::get_int() const
{
	return (this->_nb);
}

float	Convert::get_float() const
{
	return (this->_f);
}

double	Convert::get_double() const
{
	return (this->_d);
}

bool	Convert::get_displayornot() const
{
	return (this->ch_notdisable);
}

bool	Convert::get_impossibleornot() const
{
	return (this->ch_impossible);
}

bool	Convert::get_intimpossibleornot() const
{
	return (this->int_impossible);
}

void	Convert::set_sub(std::string sub)
{
	this->_sub = sub;
}

int	Convert::char_ch()
{
	std::string	sub;

	sub = this->get_sub();
	if (sub.length() == 1 && std::isalpha(sub[0]) && std::isprint(sub[0]))
		return (CHAR);
	return (0);
}

int	Convert::int_ch()
{
	std::string	sub;
	size_t		pos;

	sub = this->get_sub();
	pos = 0;
	if (sub[pos] == '+' || sub[pos] == '-')
		pos++;
	while (sub[pos] != '\0')
	{
		if (std::isdigit(sub[pos]) == false)
			return (0);
		pos++;
	}
	return (INT);
}

int Convert::float_ch()
{
	std::string sub;
	size_t		str_len;
	size_t		point_countup;
	size_t		pos;

	sub = this->get_sub();
	if (spchar_ch_float(sub) == true)
		return (FLOAT);
	str_len = sub.length();
	pos = 0;
	point_countup = 0;
	if (sub[str_len - 1] != 'f')
		return (0);
	while (sub[pos] == '+' || sub[pos] == '-')
		pos++;
	while (pos != str_len - 1)
	{
		if (point_countup > 1)
			return (0);
		if (sub[pos] == '.')
			point_countup++;
		if (std::isdigit(sub[pos]) == false && sub[pos] != '.')
			return (0);
		pos++;
	}
	return (FLOAT);
}

int Convert::double_ch()
{
	std::string sub;
	size_t		point_countup;
	size_t		pos;

	sub = this->get_sub();
	if (spchar_ch_double(sub) == true)
		return (true);
	point_countup = 0;
	pos = 0;
	while (sub[pos] == '+' || sub[pos] == '-')
		pos++;
	while (sub[pos] != '\0')
	{
		if (point_countup > 1)
			return (0);
		if (sub[pos] == '.')
			point_countup++;
		if (std::isdigit(sub[pos]) == false && sub[pos] != '.')
			return (0);
		pos++;
	}
	return (DOUBLE);
}

std::ostream &operator<<(std::ostream &out, Convert &tgt)
{
	out << std::endl;
	if (tgt.get_displayornot() == true)
		out << "char is Non displayable :X " << std::endl;
	else if (tgt.get_impossibleornot() == true)
		out << "char is impossible X( " << std::endl;
	else
		out << "char is " << tgt.get_char() << std::endl;
	
	if (tgt.get_intimpossibleornot() == true)
		out << "int is impossible X(" << std::endl;
	else
		out << "int is " << tgt.get_int() << std::endl;
	
	if (tgt.get_float() - static_cast<int>(tgt.get_float()) == 0)
		out << "float is " << tgt.get_float() << ".0f " << std::endl;
	else
		out << "float is " << tgt.get_float() << "f " << std::endl;
	
	if (tgt.get_double() - static_cast<int>(tgt.get_float()) == 0)
		out << "double is " << tgt.get_double() << ".0" << std::endl;
	else
		out << "double is " << tgt.get_double() << std::endl;
	return (out);	
}