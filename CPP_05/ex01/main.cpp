/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:12 by user              #+#    #+#             */
/*   Updated: 2023/06/16 00:32:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	prevent_test()
{
	    //temp check//
    Bureaucrat b("jaeskim", 11);
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << "///////// increase test \\\\\\\\\\\\\\\\" << std::endl;
    std::cout << std::endl;
    try
    {
        b.increaseGrade(9);//2
        std::cout << b << std::endl;
        b.increaseGrade(1);//1
        std::cout << b << std::endl;
        b.increaseGrade(1);//over 1
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "///////// decrease test \\\\\\\\\\\\\\\\" << std::endl;
	std::cout << std::endl;

    try
    {
        b.decreaseGrade(140);//141
        std::cout << b << std::endl;
        b.decreaseGrade(10);//over 150
        std::cout << b << std::endl;
        b.decreaseGrade(9);//150
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Form        		form("form1", 10, 10);
    Bureaucrat		  	user("user1", 1);

	prevent_test();

	std::cout << std::endl;
	std::cout << form << std::endl;
    std::cout << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~//high grade
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << "< grade 1 test >" << std::endl;
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << std::endl;
    form.beSigned(user);
    user.signForm(form);
    std::cout << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~//equal grade
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << "< grade 9 test >" << std::endl;
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << std::endl;
    user.decreaseGrade(9);
    form.beSigned(user);
    user.signForm(form);
	std::cout << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~//under grade
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << "< grade 19 test >" << std::endl;
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << std::endl;
    user.decreaseGrade(9);
    try
    {
        form.beSigned(user);//missed
    }
    catch(const std::exception& e)
    {
        std::cout << "this form sign is missed" << std::endl;
    }
    user.signForm(form);
	std::cout << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~//reover grade
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << "< grade 10 test >" << std::endl;
    std::cout << " ^^^^^^^^^^^^^^" << std::endl;
    std::cout << std::endl;
    user.increaseGrade(9);
    try
    {
        form.beSigned(user);//missed
    }
    catch(const std::exception& e)
    {
        std::cout << "this form sign is missed" << std::endl;
    }
    user.signForm(form);
	std::cout << std::endl;

    std::cout << "====== ng test is starting ! =======" << std::endl;
    std::cout << std::endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~//over value　with Bureaucrat
    std::cout << "====================" << std::endl;
    try
    {
        Bureaucrat  user("user1", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "====================" << std::endl;
    try
    {
        Bureaucrat  user("user1", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~//over value　with sign
    std::cout << "====================" << std::endl;
    try
    {
        Form    form2("form1", 162, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================" << std::endl;
    //form2.beSigned(user);//当然アクセスはできない
    try
    {
        Form    form3("form1", 10, 162);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================" << std::endl;
    try
    {
        Form    form4("form1", 162, 162);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================" << std::endl;
    try
    {
        Form    form5("form1", -162, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================" << std::endl;
    try
    {
        Form    form6("form1", 10, -162);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================" << std::endl;
    try
    {
        Form    form7("form1", -162, -162);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================" << std::endl;
}