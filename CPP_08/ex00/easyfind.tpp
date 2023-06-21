/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:11:58 by user              #+#    #+#             */
/*   Updated: 2023/06/21 18:10:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

void	easyfind(T& sub, int nbr)
{
	try
	{
		if (std::find(sub.begin(), sub.end(), nbr) != sub.end())
			std::cout << "FIND!" << std::endl;
		else
			std::cout << "NOTFIND!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}