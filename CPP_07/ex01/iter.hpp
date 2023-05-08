/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:51:54 by user              #+#    #+#             */
/*   Updated: 2023/05/08 21:29:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename Tem>

void	iter(Tem *arr, size_t size, void (*f)(Tem &))
{
	size_t	pos;

	pos = 0;
	while (pos != size)
	{
		f(arr[pos]);
		pos++;
	}
}

template <typename Tem>

void	print(Tem &nanka)
{
	std::cout << nanka << std::endl;
}