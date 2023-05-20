/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:49:07 by user              #+#    #+#             */
/*   Updated: 2023/05/19 09:13:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	show_usage()
{
	std::cout << "you must one file argument" << std::endl;
	std::cout << "like [./btc (filename)]" << std::endl;
	exit (1);
}

bool	file_existch(std::string sub)
{
	std::ifstream	file(sub);
	return (file.good());
}

std::string	file_not_exist(std::string sub)
{
	std::string input;

	std::cout << sub << " does not exist" << std::endl;
	std::cout << "if you want test, input [test mode]" << std::endl;
	std::getline(std::cin, input);
	if (input != "test mode")
	{
		std::cout << "bye" << std::endl;
		exit(1);
	}
	std::cout << "test mode moved !" << std::endl;
	return "test.csv";
}

std::map<std::string, double> read_csvfile(const std::string& filepath, char delim)
{
	std::ifstream						csv_file(filepath.c_str());
	std::string							line;
	
	std::map<std::string, double>		csv_map;

	while (std::getline(csv_file, line))
	{
		std::vector<std::string>	row;
		size_t						pos;

		std::string					key;
		std::string					val;

		pos = 0;
		while (line[pos] != '\0')
		{
			if (line[pos] == delim)
			{
				pos++;
				while (line[pos] != '\0')
				{
					val = val + line[pos];
					pos++;
				}
				try
				{
					csv_map[key] = std::stod(val);
				}
				catch(const std::exception& e)
				{
					
				}
			}
			key = key + line[pos];
			pos++;
		}
	}
	return (csv_map);
}

void	read_file(std::string file, std::map<std::string, double> csv_data)
{
	std::ifstream							csv_file(file.c_str());
	std::string								line;
	size_t									pos;
	std::map<std::string, double>::iterator	itr;

	while (std::getline(csv_file, line))
	{
		std::string					key;
		std::string					val;
		double						val_num;

		pos = 0;
		while (line[pos] != '\0')
		{
			if (line[pos] == ' ' && line[pos + 1] == '|' && line[pos + 2] == ' ')
			{
				pos = pos + 3;
				while (line[pos] != '\0')
				{
					val = val + line[pos];
					pos++;
				}
				try
				{
					val_num = std::stod(val);
					itr = csv_data.lower_bound(key);
					if (itr == csv_data.begin() && key != itr->first)
						std::cout << key << " is not founded!!" << std::endl;
					else if (itr != csv_data.begin() && key != itr->first)
					{
						itr--;
						std::cout << key << " 's subject_key is " << itr->first << " and value is " << itr->second << " and result is "  << val_num * itr->second << std::endl;
					}
					else
						std::cout << key << " 's subject_key is " << itr->first << " and value is " << itr->second << " and result is "  << val_num * itr->second << std::endl;
				}
				catch(const std::exception& e)
				{
					
				}
			}
			key = key + line[pos];
			pos++;
		}
	}
}

int main(int argc, char **argv)
{
	std::string	filename;
	std::string	input;

	if (argc != 2)
		show_usage();
	if (file_existch(argv[1]) == false)
		filename = file_not_exist(argv[1]);
	else
		filename = argv[1];
	read_file(filename, read_csvfile("data.csv", ','));
}
