/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:49:07 by user              #+#    #+#             */
/*   Updated: 2023/07/05 12:17:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#define FORMAT_ERROR	1
#define	MINUSNUM_ERROR	2
#define OVERNUM_ERROR	3
#define NUMFORMAT_ERROR	4

static void	show_usage()
{
	std::cout << "you must one file argument" << std::endl;
	std::cout << "like [./btc (filename)]" << std::endl;
}

static bool	file_existch(std::string sub)
{
	std::ifstream	file(sub);
	return (file.good());
}

static std::string	file_not_exist(std::string sub)
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

static int rate_ch(std::string ratio)
{
	size_t	pos = 0;
	size_t	dot_counter = 0;

	if (ratio[pos] == '-')
		return (MINUSNUM_ERROR);
	else if (ratio[pos] == '+')
		pos++;
	while (ratio[pos] != '\0')
	{
		if (ratio[pos] == '.' && dot_counter == 0)
		{
			if (pos > 4)
				return (OVERNUM_ERROR);
			dot_counter++;
		}
		else if (ratio[pos] == '.' && dot_counter != 0)
			return (NUMFORMAT_ERROR);
		else if (!('0' <= ratio[pos] && ratio[pos] <= '9'))
			return (NUMFORMAT_ERROR);
		pos++;
	}
	if (dot_counter != 0 && pos > 4)
		return (OVERNUM_ERROR);
	return (0);
}

static bool day_ch(char left, char right)
{
	if ('0' <= left && left <= '2')
	{
		if ('0' <= right && right <= '9')
			return (true);
		return (false);
	}
	else if (left == '3')
	{
		if ('0' <= right && right <= '1')
			return (true);
		return (false);
	}
	return (false);
}

static bool month_ch(char left, char right)
{
	if (left == '0')
	{
		if ('1' <= right && right <= '9')
			return (true);
		return (false);
	}
	else if (left == '1')
	{
		if ('0' <= right && right <= '2')
			return (true);
		return (false);
	}
	return (false);
}

static bool line_correctly_ch(std::string line)
{
	size_t	pos = 0;

	while ('0' <= line[pos] && line[pos]<= '9')
		pos++;
	if (line[pos] != '-')
		return (FORMAT_ERROR);
	pos++;
	if (month_ch(line[pos], line[pos + 1]) == false)
		return (FORMAT_ERROR);
	pos = pos + 3;
	if (day_ch(line[pos], line[pos + 1]) == false)
		return (FORMAT_ERROR);
	pos = pos + 2;
	if (line[pos] != ' ' || line[pos + 1] != '|' || line[pos + 2] != ' ')
		return (FORMAT_ERROR);
	pos = pos + 3;

	std::string	rate = "";

	while (line[pos] != '\0')
	{
		rate = rate + line[pos];
		pos++;
	}
	return rate_ch(rate);
}

static double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}

static	void	show_error_switching(int error_num)
{
	switch (error_num)
	{
		case FORMAT_ERROR:
			std::cout << " FORMAT ERROR" << std::endl;
			break;
		case MINUSNUM_ERROR:
			std::cout << " HANDLING POSITIVE NUM" << std::endl;
			break;
		case OVERNUM_ERROR:
			std::cout << " TOO LARGE NUM" << std::endl;
			break;
		case NUMFORMAT_ERROR:
			std::cout << " THIS IS ... NUM ... ? CHECK IT !" << std::endl;
			break;
	}
}

std::string obtain_day_info(std::string line, size_t *pos)
{
	std::string	key = "";

	while (line[*pos] != ' ')
	{
		key = key + line[*pos];
		*pos = *pos + 1;
	}
	return (key);
}

std::string obtain_rate_info(std::string line, size_t *pos)
{
	std::string	key = "";

	while (line[*pos] != '\0')
	{
		key = key + line[*pos];
		*pos = *pos + 1;
	}
	return (key);
}

void	read_file(std::string file, std::map<std::string, double> csv_data)
{
	std::ifstream							subject_file(file.c_str());
	std::string								line;
	size_t									pos;
	std::map<std::string, double>::iterator	itr;

	while (std::getline(subject_file, line))
	{
		std::string					key = "";
		std::string					val = "";
		double						val_num = 0.0;
		int							error_num;

		pos = 0;
		error_num = line_correctly_ch(line);
		if (error_num != 0)
		{
			std::cout << line;
			show_error_switching(error_num);
		}
		else
		{
			key = obtain_day_info(line, &pos);
			pos = pos + 3;
			val = obtain_rate_info(line, &pos);
			val_num = stringToDouble(val);
			itr = csv_data.lower_bound(key);
			if (itr == csv_data.begin() && key != itr->first)
				std::cout << key << " is not founded!!" << std::endl;
			else if (val_num > 1000)
				std::cout << key << " TOO LARGE NUM" << std::endl;
			else if (itr != csv_data.begin() && key != itr->first)
			{
				itr--;
				std::cout << key << " 's subject_key is " << itr->first << " and value is " << itr->second << " and result is "  << val_num * itr->second << std::endl;
			}
			else
				std::cout << key << " 's subject_key is " << itr->first << " and value is " << itr->second << " and result is "  << val_num * itr->second << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		show_usage();
		return (1);
	}
	BitcoinExchange database;
	if (database.line_correctlyexit() == false)
	{
		std::cout << "========================" << std::endl;
		std::cout << "<<      CAUTION       >>" << std::endl;
		std::cout << "========================" << std::endl;
		std::cout << "|  CSV FILE IS MISSED  |" << std::endl;
		std::cout << "========================" << std::endl;
		return (1);
	}
	std::string	filename;
	std::string	input;

	if (file_existch(argv[1]) == false)
		filename = file_not_exist(argv[1]);
	else
		filename = argv[1];
	read_file(filename, database.csvinfo_return());
}
