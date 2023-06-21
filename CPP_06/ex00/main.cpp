/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:40:05 by user              #+#    #+#             */
/*   Updated: 2023/06/21 11:27:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main()
{
	ScalarConverter::convert("a");
	ScalarConverter::convert("0");
	ScalarConverter::convert("45");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("4.2");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("-3.000001f");
	return (0);
}