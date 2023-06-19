/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:45:36 by user              #+#    #+#             */
/*   Updated: 2023/06/19 21:28:55 by user             ###   ########.fr       */
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
	Intern  someRandomIntern;
	Form*   rrf;

	rrf = someRandomIntern.makeForm("NoForm", "Bender");
	if (rrf != NULL)
		std::cout << rrf->getName() << std::endl;

	Form*	pre;
	pre = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	if (pre != NULL)
		std::cout << pre->getName() << std::endl;
}