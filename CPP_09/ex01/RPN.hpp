/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:19:00 by user              #+#    #+#             */
/*   Updated: 2023/05/20 00:01:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class	RPN
{
	private:
		std::stack<int>	num_stack;
	
	public:
		RPN();
		~RPN();
		RPN(RPN const &sub);
		RPN &operator=(RPN const &sub);
		void	append(int num);
		int		obtain_top() const;
		void	stack_pop();
		bool	stack_emptych() const;
		size_t	obtain_stacksize() const;
		size_t	obtain_stacksize(RPN const &sub) const;
};

#endif