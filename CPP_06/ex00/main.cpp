/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:40:05 by user              #+#    #+#             */
/*   Updated: 2023/06/24 03:14:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "you must write argment" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	std::cout << "kantannna check" << std::endl;
	try
	{
		std::cout << std::stoi(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "int is missed" << std::endl;
	}
	try
	{
		std::cout << std::stof(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "float is missed" << std::endl;
	}
	try
	{
		std::cout << std::stod(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "double is missed" << std::endl;
	}
	// // //simple char example//
	// ScalarConverter::convert("a");

	// // //simple int example//
	// ScalarConverter::convert("0");
	// ScalarConverter::convert("45");
	// ScalarConverter::convert("-42");
	// ScalarConverter::convert("2147483648");
	// ScalarConverter::convert("11111111111111111111111111111111111111111111111111111111111111111111111111111111111");//floatは超えてる

	// //simple double example//
	//ScalarConverter::convert("0.0");
	// ScalarConverter::convert("4.2");
	// ScalarConverter::convert("45.0");//これは文字でて欲しいけど
	// ScalarConverter::convert("45.01");//これは出て欲しくないかも
	// ScalarConverter::convert("2147483648.0");
	// ScalarConverter::convert("900071999254740994.0");
	// ScalarConverter::convert("nan");
	// ScalarConverter::convert("+inf");
	// ScalarConverter::convert("-inf");

	// // //simplefloat example//
	// // ScalarConverter::convert("-4.2f");
	// ScalarConverter::convert("42.0f");//これは文字でて欲しいけど
	// ScalarConverter::convert("-3.000001f");//これは出て欲しくないかも
	// ScalarConverter::convert("nanf");
	// ScalarConverter::convert("inff");//こいつはない
	// ScalarConverter::convert("+inff");
	// ScalarConverter::convert("-inff");
	return (0);
}