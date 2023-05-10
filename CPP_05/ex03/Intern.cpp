/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:58:03 by user              #+#    #+#             */
/*   Updated: 2023/05/10 19:12:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &sub)
{
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(Intern const &sub)
{
	std::cout << "Intern Operator constructor called" << std::endl;
	return (*this);
}

static	Form	*President(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static	Form	*Robot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static	Form	*Shurubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(std::string form_name, std::string target)
{
	size_t	pos;

	Form	*(*forms[])(const std::string name) = {
		&President,
		&Robot,
		&Shurubbery
	};

	std::string form_names[] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};

	pos = 0;
	while (pos != 3)
	{
		if (form_name == form_names[pos])
		{
			std::cout << "form is made" << std::endl;
			return (forms[pos](target));
		}
		pos++;
	}
	std::cout << "Form is not exist" << std::endl;
	return (NULL);
}