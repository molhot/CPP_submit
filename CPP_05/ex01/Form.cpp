/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:43:45 by user              #+#    #+#             */
/*   Updated: 2023/05/07 15:24:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int sign, int execute): _name(name), _grade4sign(sign), _grade4execute(execute), _signed(false)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &sub): _name(sub._name), _grade4sign(sub._grade4sign), _grade4execute(sub._grade4execute), _signed(sub._signed)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(Form const &sub)
{
	std::cout << "Form operand called" << std::endl;
	if (this == &sub)
		return (*this);
	this->_name = sub._name;
	this->_grade4sign = sub._grade4sign;
	this->_grade4execute = sub._grade4execute;
	this->_signed = sub._signed;
	return (*this);
}

void	Form::beSigned(Breaucrat const &sub)
{
	if (sub.getGrade() <= this->_grade4sign)
	{
		std::cout << "this is signed!" << std::endl;
		this->_signed = true;
	}
	else
		std::cout << "this is not satisfied the rule" << std::endl;
}

bool	Form::get_Signstatus() const
{
	return (this->_signed);
}

int	Form::get_Grade4Sign() const
{
	return (this->_grade4sign);
}

int Form::get_Grade4excete() const
{
	return (this->_grade4execute);
}