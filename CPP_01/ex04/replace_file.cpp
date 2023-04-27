/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:23 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 14:50:01 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace_file.hpp"

ReplaceInfo::ReplaceInfo(std::string s1, std::string s2):replacewd(s1), replacedwd(s2)
{

}

ReplaceInfo::~ReplaceInfo()
{

}

std::string	ReplaceInfo::obtain_rwd(void)
{
	return this->replacedwd;
}

std::string	ReplaceInfo::obtain_redwd(void)
{
	return this->replacewd;
}