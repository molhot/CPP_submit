/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:37:50 by user              #+#    #+#             */
/*   Updated: 2023/06/19 20:52:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("no_name"), _grade(150)
{
	std::cout << "Bureaucrat with no argment constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat with argment constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &sub): _name(sub._name), _grade(sub._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &sub)
{
	std::cout << "copy assignment called" << std::endl;
	if (this == &sub)
		return (*this);
	this->_name = sub._name;
	this->_grade = sub._grade;
	return (*this);
}

std::string	Bureaucrat::getName()
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade - 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = this->_grade - 1;
}

void	Bureaucrat::increaseGrade(int grade)
{
	while (grade != 0)
	{
		this->_grade = this->_grade - 1;
		grade = grade - 1;
		if (this->_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (this->_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade + 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = this->_grade + 1;
}

void	Bureaucrat::decreaseGrade(int grade)
{
	while (grade != 0)
	{
		this->_grade = this->_grade + 1;
		grade = grade - 1;
		if (this->_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (this->_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	}
}

//High error crass

void	Bureaucrat::executeForm(AForm const &sub)
{
	size_t len = this->getName().length() + sub.getName().length() + 19;
	std::string line = "-";

	while (true)
	{
		if (line.length() == len)
			break;
		line = line + '-';
	}
	std::cout << line << std::endl;
	std::cout << "|| " << this->getName() << " try execute " << sub.getName() << " ||" << std::endl;
	std::cout << line << std::endl;
	try
	{
		sub.execute(*this);
		std::cout << *this << " executed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " cannnot executed" << std::endl;
	}
	
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "GradeTooHighException constructor called" << std::endl;
}

// Bureaucrat::GradeTooHighException::~GradeTooHighException()
// {
// 	std::cout << "GradeTooHighException destructor called" << std::endl;
// }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grede is over 1");
}

//Low error crass

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "GradeTooLowException constructor called" << std::endl;
}

// Bureaucrat::GradeTooLowException::~GradeTooLowException()
// {
// 	std::cout << "GradeTooLowException destructor called" << std::endl;
// }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grede is under 150");
}

//override output func

//与えられた文字のどちらが長いかをまずは確認
//長い方が起点になる（大きい括り）
//短い方は長い方に合わせて空白を入れることで体裁を整える

bool	left_is_over(std::string str1, std::string str2)
{
	size_t	str1len;
	size_t	str2len;

	str1len = str1.length();
	str2len = str2.length();

	if (str1len > str2len)
		return (true);
	else
		return (false);
}

std::string	shape_output(std::string long_str, std::string short_str, bool name_is_upper)
{
	std::string	tmp_emp_1 = "||  ";
	std::string	tmp_emp_2 = "  ||";
	std::string name_show;
	std::string	grade_show;

	if (name_is_upper == true)
	{
		std::string	separator = "-";
		std::string	emp = " ";
		name_show = tmp_emp_1 + long_str + tmp_emp_2;
		while (true)
		{
			if (separator.length() == name_show.length())
				break;
			separator = separator + "-";
		}
		while (true)
		{
			if (emp.length() == (separator.length() - 6) / 2)
				break;
			emp = emp + " ";
		}
		if (short_str.length() == 1)
			emp = emp + " ";
		return (separator + "\n" + name_show + "\n" + separator + "\n" + "|>" + emp + short_str + emp + "<|" + "\n" + separator + "\n");
	}
	else
	{
		std::string	separator = "-";
		std::string	emp = " ";
		grade_show = "|>  " + long_str + "  <|";
		while (true)
		{
			if (separator.length() == grade_show.length())
				break;
			separator = separator + "-";
		}
		while (true)
		{
			if (emp.length() == (separator.length() - 6) / 2)
				break;
			emp = emp + " ";
		}
		return (separator + "\n" + tmp_emp_1 + short_str + tmp_emp_2 + "\n" + separator + "\n" + grade_show + "\n" + separator + "\n");
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &tgt)
{
	std::string line = "-";
	std::string	name = tgt.getName();
	std::string	grade = std::to_string(tgt.getGrade());

	if (left_is_over(name, grade) == true)
		out << shape_output(name, grade, true);
	else
		out << shape_output(grade, name, false);
	return (out);		
}
