/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:11:58 by user              #+#    #+#             */
/*   Updated: 2023/07/01 16:48:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

int	easyfind(T& sub, int nbr)
{
	try
	{
		if (std::find(sub.begin(), sub.end(), nbr) != sub.end())
		{
			std::cout << "FIND!" << std::endl;
			return (0);
		}
		else
		{
			std::cout << "NOTFIND!" << std::endl;
			return (1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}