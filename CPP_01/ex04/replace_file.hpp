/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:29 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 11:11:40 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>


class	ReplaceInfo
{
	private:
		std::string	replacewd;
		std::string replacedwd;
	
	public:
		ReplaceInfo(std::string s1, std::string s2);
		~ReplaceInfo();
		std::string	obtain_rwd(void);
		std::string	obtain_redwd(void);
};

#endif