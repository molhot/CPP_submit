/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:14:43 by user              #+#    #+#             */
/*   Updated: 2023/06/21 21:10:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_array;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &sub);
		Span& operator=(Span const &sub);
		~Span();
		void				addNumber(int num);
		void				addNumbers_random(unsigned int count);
		int					shortestSpan();
		int					longestSpan();
		unsigned int		get_n() const;
		std::vector<int>	get_array() const;
};

#endif