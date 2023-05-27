/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filemanage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:17 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/05/28 00:17:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanage.hpp"

Fileinfo::Fileinfo(std::string fn, ReplaceInfo ri):file_name(fn), \
file_name_s(fn + ".replace"), replaceinfo(ri)
{
	this->replaced_fileinfo = this->obtain_filecontent();
}

Fileinfo::~Fileinfo()
{

}

std::string	Fileinfo::obtain_filecontent(void)
{
	std::ifstream	ifs(this->file_name);
	std::string		oneline;
	std::string		allline;

	this->file_name_s = this->file_name + ".replace";
	if (ifs.fail())
	{
		std::cerr << "Fail to open" << std::endl;
		exit(EXIT_FAILURE);
	}
	allline = "";
	while (getline(ifs, oneline))
	{
		allline = allline + oneline;
		allline = allline + "\n";
	}
	return (allline);
}

void	Fileinfo::replace_wd(void)
{
	std::string	replaced_wd = this->replaceinfo.obtain_redwd();
	std::string	replace_wd = this->replaceinfo.obtain_rwd();
	std::string	text = this->replaced_fileinfo;

	if (text == "\0")
	{
		std::cout << "empty file" << std::endl;
		return ;
	}
	size_t		pos = 0;
	pos = text.find(replaced_wd, pos);
	while (pos != std::string::npos)
	{
		//text.replace(pos, replaced_wd.length(), replace_wd);
		text = text.substr(0, pos) + replace_wd + text.substr(pos + replaced_wd.length());
		pos = pos + replace_wd.length();
		pos = text.find(replaced_wd, pos);
	}
	std::ofstream output(this->file_name_s);
	output << text;
	output.close();
}