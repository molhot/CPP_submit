/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:19:00 by user              #+#    #+#             */
/*   Updated: 2023/07/06 19:04:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <iostream>
#include <sstream>

class	RPN
{
	private:
		bool				rpn_ready;
		std::stack<int>		num_stack;
		void				line_ch(std::string const &line);
		void				skipping_emp(std::string const &line, size_t *pos);
		bool				check_ch(char ch, size_t *pos);
		bool				num_ch(char ch);
		bool				operator_ch(char ch);
		bool				ready_stack(std::string const &line);
		bool				ready_numstack(std::string const &line, size_t *pos);
		bool				int_ch(std::string const &num);
		int					stringToInt(const std::string& str);
	
	public:
		RPN(std::string input);
		~RPN();
		RPN(RPN const &sub);
		RPN &operator=(RPN const &sub);
		void	append(int num);
		int		obtain_top() const;
		void	stack_pop();
		bool	stack_emptych() const;
		bool	get_readystatus() const;
		size_t	obtain_stacksize() const;
		size_t	obtain_stacksize(RPN const &sub) const;
		void	skipping_emp_and_int(std::string const &line, size_t *pos);
};

#endif