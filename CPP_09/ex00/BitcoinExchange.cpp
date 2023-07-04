/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:49:01 by user              #+#    #+#             */
/*   Updated: 2023/07/04 21:47:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::rate_ch(std::string ratio)
{
	size_t	pos = 0;
	size_t	dot_counter = 0;

	while (ratio[pos] != '\0')
	{
		if (ratio[pos] == '.' && dot_counter == 0)
			dot_counter++;
		else if (ratio[pos] == '.' && dot_counter != 0)
			return (false);
		else if (!('0' <= ratio[pos] && ratio[pos] <= '9'))
			return (false);
		pos++;
	}
	return (true);
}

bool BitcoinExchange::day_ch(char left, char right)
{
	if ('0' <= left <= '2')
	{
		if ('0' <= right <= '9')
			return (true);
		return (false);
	}
	else if (left == '3')
	{
		if ('0' <= right <= '1')
			return (true);
		return (false);
	}
	return (false);
}

bool BitcoinExchange::month_ch(char left, char right)
{
	if (left == '0')
	{
		if ('1' <= right <= '9')
			return (true);
		return (false);
	}
	else if (left == '1')
	{
		if ('0' <= right <= '2')
			return (true);
		return (false);
	}
	return (false);
}

bool BitcoinExchange::line_correctly_ch(std::string line)
{
	size_t	pos = 0;

	while ('0' <= line[pos] <= '9')
		pos++;
	if (line[pos] != '-')
		return (false);
	pos++;
	if (month_ch(line[pos], line[pos + 1]) == false)
		return (false);
	pos = pos + 2;
	if (day_ch(line[pos], line[pos + 1]) == false)
		return (false);
	pos = pos + 2;
	if (line[pos] != ',')
		return (false);
	pos = pos + 1;

	std::string	rate = "";

	while (line[pos] != '\0')
	{
		rate = rate + line[pos];
		pos++;
	}
	if (rate_ch(rate) == false)
		return (false);
	return (true);
}

std::string	BitcoinExchange::get_key(std::string line, size_t *pos)
{
	std::string	key = "";
	while (line[*pos] != ',')
	{
		key = key + line[*pos];
		*pos = *pos + 1;
	}
	return (key);
}

double BitcoinExchange::stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}

std::string	BitcoinExchange::get_val(std::string line, size_t *pos)
{
	std::string	val = "";
	while (line[*pos] != '\0')
	{
		val = val + line[*pos];
		*pos = *pos + 1;
	}
	return (val);
}

bool BitcoinExchange::reading_csv(std::map<std::string, double> map)
{
	std::ifstream	file("data.csv");
	std::string		line;
	size_t			pos = 0;
	std::string		key;
	std::string		val;

	while (std::getline(file, line))
	{
		if (line_correctly_ch(line) == false)
			return (false);
		key = get_key(line, &pos);
		pos = pos + 1;
		val = get_key(line, &pos);
		map[key] = stringToDouble(val);
	}
	return (true);
}

bool	BitcoinExchange::line_correctlyexit()
{
	return (this->csv_correct_ornot);
}

std::map<std::string, double>	BitcoinExchange::csvinfo_return(void)
{
	return (this->csv_info);
}

BitcoinExchange::BitcoinExchange()
{
	std::cout << "<< regist database >>" << std::endl;
	std::ifstream file("data.csv");
	if (file.good() == true)
		this->csv_correct_ornot = reading_csv(this->csv_info);
	else
		this->csv_correct_ornot = false;
}

BitcoinExchange::~BitcoinExchange()
{
	//何もしない
}
