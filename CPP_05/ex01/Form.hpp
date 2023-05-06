/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:43:41 by user              #+#    #+#             */
/*   Updated: 2023/05/06 14:52:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <stdbool.h>
#include "Breaucrat.hpp"

class Form
{
	private:
		std::string _name;
		bool		_signed;
		int			_grade4sign;
		int			_grade4execute;

	public:
		Form(std::string name, int sign_grade, int execute_grade);
		~Form();
		Form(Form const &sub);
		Form& operator=(Form const &sub);
		void	beSigned(Breaucrat const &sub);
		bool	get_Signstatus() const;
		int		get_Grade4Sign() const;
		int		get_Grade4excete() const;
};

std::ostream &operator<<(std::ostream &out, Form const &sub);

#endif