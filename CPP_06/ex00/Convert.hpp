/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:51:37 by user              #+#    #+#             */
/*   Updated: 2023/05/08 14:28:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Show_Static_HPP
#define Show_Static_HPP

#include <iostream>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

class Convert
{
	private:
		std::string	_sub;
		int			_type;

		char		_ch;
		bool		ch_notdisable;
		bool		ch_impossible;
		int			_nb;
		bool		int_impossible;
		float		_f;
		double		_d;

	public:
		Convert(std::string sub);
		Convert(Convert const &sub);
		Convert& operator=(Convert const &sub);
		~Convert();
		std::string	get_sub() const;
		char		get_char() const;
		int			get_int() const;
		float		get_float() const;
		double		get_double() const;
		bool		get_displayornot() const;
		bool		get_impossibleornot() const;
		bool		get_intimpossibleornot() const;

		void		set_sub(std::string sub);

		int			char_ch();
		int			int_ch();
		int			float_ch();
		int			double_ch();

		void		set_chartype();
		void		set_inttype();
		void		set_floattype();
		void		set_doubletype();

		class	Error_Convert
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Convert &sub);

#endif