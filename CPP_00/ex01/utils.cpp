/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:16:15 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 18:22:08 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	ft_isdigit(std::string sub)
{
	size_t  pos;

	pos = 0;
	while (sub[pos] != '\0')
	{
		if ('0' <= sub[pos] && sub[pos] <= '9')
			pos++;
		else
			return (false);
	}
	return (true);
}
