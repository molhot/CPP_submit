/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:51:37 by user              #+#    #+#             */
/*   Updated: 2023/06/24 01:08:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#define CHAR	1
#define INT		2
#define FLOAT	3
#define DOUBLE	4
#define DBL_MAX 1.79769e+308

class ScalarConverter
{
	private:
		static	char	_char;
		static	int		_int;
		static	bool	_int_overflaw;
		static	bool	_int_overflaw_minus;
		static	double	_double;
		static	bool	_double_overflaw;
		static	bool	_double_overflaw_minus;
		static	float	_float;
		static	bool	_float_overflaw;
		static	bool	_float_overflaw_minus;
	
	public:
		static	void	convert(const std::string &literal);

		static	void	show_nan();
		static	void	show_inf(const std::string &literal);

		static	bool	check_literal_char(const std::string &literal);
		static	bool	check_literal_int(const std::string &literal);
		static	bool	check_literal_double(const std::string &literal);
		static	size_t	count_coronnum(const std::string &literal);
		static	bool	check_literal_float(const std::string &literal);
		static	size_t	count_fnum(const std::string &literal);

		static	void	ch_show(const std::string &literal);
		static	void	int_show(const std::string &literal);
		static	void	float_show(const std::string &literal);
		static	void	double_show(const std::string &literal);

		static	void	ch_showswitch(char _ch);
		static	void	int_showswitch(int _int);
		static	void	float_showswitch(float _float);
		static	void	double_showswitch(double _double);

		// class	Error_Convert
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

#endif