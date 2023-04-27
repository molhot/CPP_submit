/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filemanage.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:26 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 11:10:30 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include "replace_file.hpp"

class	Fileinfo
{
	private:
		std::string	file_name;
		std::string	file_name_s;
		std::string	replaced_fileinfo;
		ReplaceInfo	replaceinfo;
	
	public:
		Fileinfo(std::string fn, ReplaceInfo ri);
		~Fileinfo();
		std::string	obtain_filecontent(void);
		void		replace_wd(void);
};

#endif