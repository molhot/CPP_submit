/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:45:36 by user              #+#    #+#             */
/*   Updated: 2023/06/19 20:38:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

void	Sh_formtest(Bureaucrat user1, Bureaucrat user2)
{
	ShrubberyCreationForm Sh_form("sh1");
	ShrubberyCreationForm Sh_form2("sh2");
	std::cout << "Sh_form required info is " << Sh_form.get_Grade4Sign() << " " << Sh_form.get_Grade4excete() << std::endl;
	std::cout << std::endl;
	try
	{
		Sh_form.execute(user1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	Sh_form.beSigned(user1);
	try
	{
		Sh_form.execute(user1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Sh_form2.execute(user2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	Sh_form2.beSigned(user2);
	try
	{
		Sh_form2.execute(user2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void	Ro_formtest(Bureaucrat user, Bureaucrat user2)
{
	RobotomyRequestForm Ro_form("Ro1");
	std::cout << "Ro_form required info is " << Ro_form.get_Grade4Sign() << " " << Ro_form.get_Grade4excete() << std::endl;
	Ro_form.beSigned(user);
	user.executeForm(Ro_form);
	std::cout << std::endl;
	Ro_form.beSigned(user2);
	user2.executeForm(Ro_form);
	std::cout << std::endl;
}

void	Pre_formtest(Bureaucrat user, Bureaucrat user2)
{
	PresidentialPardonForm Pr_form("Pre1");
	std::cout << "Pre_form required info is " << Pr_form.get_Grade4Sign() << " " << Pr_form.get_Grade4excete() << std::endl;
	Pr_form.beSigned(user);
	user.executeForm(Pr_form);
	std::cout << std::endl;
	Pr_form.beSigned(user2);
	user2.executeForm(Pr_form);
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));
    //Form        		form("form1", 10, 10);
    Bureaucrat		  	user("user1", 1);
	Bureaucrat			user2("user2", 145);

	std::cout << "============ user info ==================" << std::endl;
	std::cout << user << std::endl;
	std::cout << std::endl;
	std::cout << user2<< std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << std::endl;

	std::cout << " < ShrubberyCreationForm test > " << std::endl;
	std::cout << std::endl;
	Sh_formtest(user, user2);
	std::cout << " ======================================== " << std::endl;
	std::cout << std::endl;

	std::cout << " < ShrubberyCreationForm test > " << std::endl;
	std::cout << std::endl;
	Ro_formtest(user, user2);
	std::cout << " ======================================== " << std::endl;
	std::cout << std::endl;

	std::cout << " < ShrubberyCreationForm test > " << std::endl;
	std::cout << std::endl;
	Pre_formtest(user, user2);
	std::cout << " ======================================== " << std::endl;

	//cannot instance
	//Form testform("nanka");
}