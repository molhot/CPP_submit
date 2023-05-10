/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:45:36 by user              #+#    #+#             */
/*   Updated: 2023/05/10 19:22:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	// srand(time(NULL));
    // //Form        		form("form1", 10, 10);
    // Bureaucrat		  	user("user1", 1);
	// Bureaucrat			user2("user2", 145);

	// std::cout << "user grade is " << user.getGrade() << std::endl;
	// std::cout << "user2 grade is " << user2.getGrade() << std::endl;
	// std::cout << std::endl;

	// //Shrubbery test
	// ShrubberyCreationForm Sh_form("sh1");
	// std::cout << "Sh_form required info is " << Sh_form.get_Grade4Sign() << " " << Sh_form.get_Grade4excete() << std::endl;
	// Sh_form.beSigned(user);
	// user.executeForm(Sh_form);
	// std::cout << std::endl;
	// Sh_form.beSigned(user2);
	// user2.executeForm(Sh_form);
	// std::cout << std::endl;
	// //Sh_form.beSigned(user);

	// //Robotomy test
	// RobotomyRequestForm Ro_form("Ro1");
	// std::cout << "Ro_form required info is " << Ro_form.get_Grade4Sign() << " " << Ro_form.get_Grade4excete() << std::endl;
	// Ro_form.beSigned(user);
	// user.executeForm(Ro_form);
	// std::cout << std::endl;
	// Ro_form.beSigned(user2);
	// user2.executeForm(Ro_form);
	// std::cout << std::endl;

	// //Presidental test
	// PresidentialPardonForm Pr_form("Pre1");
	// std::cout << "Pre_form required info is " << Pr_form.get_Grade4Sign() << " " << Pr_form.get_Grade4excete() << std::endl;
	// Pr_form.beSigned(user);
	// user.executeForm(Pr_form);
	// std::cout << std::endl;
	// Pr_form.beSigned(user2);
	// user2.executeForm(Pr_form);
	// std::cout << std::endl;

	Intern  someRandomIntern;
	Form*   rrf;

	rrf = someRandomIntern.makeForm("NoForm", "Bender");
	if (rrf != NULL)
		std::cout << rrf->getName() << std::endl;
}