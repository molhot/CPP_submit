/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:21:04 by user              #+#    #+#             */
/*   Updated: 2023/06/21 15:55:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename Temp>

void	swap(Temp &sub, Temp &heb)
{
	Temp	temp;

	temp = sub;
	sub = heb;
	heb = temp;
}

template <typename Temp>

Temp	min(Temp &sub, Temp &heb)
{
	if (sub >= heb)
		return (heb);
	return (sub);
}

template <typename Temp>

Temp	max(Temp &sub, Temp &heb)
{
	if (sub > heb)
		return (sub);
	return (heb);
}

#endif