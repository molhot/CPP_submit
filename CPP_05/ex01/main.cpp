/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:12 by user              #+#    #+#             */
/*   Updated: 2023/05/07 15:25:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Breaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form        		form("form1", 10, 10);
    Breaucrat		  	user("user1", 1);

	std::cout << "grade is " << user.getGrade() << std::endl;
	form.beSigned(user);
	std::cout << std::endl;
	try
	{
		user.decreaseGrade(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "grade is " << user.getGrade() << std::endl;
	form.beSigned(user);
}