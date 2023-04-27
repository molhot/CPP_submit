/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:48:39 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/27 14:48:00 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanage.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "you must write three argument, filename replaceword, replaceword2" << std::endl;
	else
	{
		ReplaceInfo	replaceinfo = ReplaceInfo(argv[2], argv[3]);
		Fileinfo	f_info = Fileinfo(argv[1], replaceinfo);
		f_info.replace_wd();
	}
}