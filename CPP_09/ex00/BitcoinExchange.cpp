/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:49:01 by user              #+#    #+#             */
/*   Updated: 2023/08/09 20:36:37 by user             ###   ########.fr       */
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

bool BitcoinExchange::month_ch(char left, char right)
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

bool BitcoinExchange::line_correctly_ch(std::string line)
{
	size_t	pos = 0;

	while ('0' <= line[pos] && line[pos] <= '9')
		pos++;
	if (line[pos] != '-')
		return (false);
	pos++;
	if (month_ch(line[pos], line[pos + 1]) == false)
		return (false);
	pos = pos + 3;
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

void BitcoinExchange::ready_alldayinfo(const std::string &day_info)
{
	size_t	pos = 0;

	while (day_info[pos] != '-')
	{
		this->year = this->year + day_info[pos];
		pos++;
	}
	pos++;
	while (day_info[pos] != '-')
	{
		this->month = this->month + day_info[pos];
		pos++;
	}
	pos++;
	while (day_info[pos] != '\0')
	{
		this->day = this->day + day_info[pos];
		pos++;
	}
}

bool BitcoinExchange::oddmonth_ch()
{
	std::istringstream iss(this->day); 
	int result;

    iss >> result;
	if (result > 30)
		return (false);
	return (true);
}

bool BitcoinExchange::addmonth_ch()
{
	std::istringstream iss(this->day); 
	int result;

    iss >> result;
	if (result > 31)
		return (false);
	return (true);
}

bool BitcoinExchange::uru_ch()
{
	std::istringstream iss(this->day); 
	int result;

    iss >> result;
	if (result > 29)
		return (false);
	return (true);
}

bool BitcoinExchange::not_uru_ch()
{
	std::istringstream iss(this->day); 
	int result;

    iss >> result;
	if (result > 28)
		return (false);
	return (true);
}

bool BitcoinExchange::date_ch()
{
	std::istringstream iss(this->year); 
	int year_int;

    iss >> year_int;
	if ((this->month == "02" && (year_int % 400) == 0) || (this->month == "02" && (year_int % 4) == 0 && (year_int % 100) != 0))
		return (uru_ch());
	else if (this->month == "02")
		return (not_uru_ch());
	if (this->month == "04" || this->month == "06" || this->month == "09" || this->month == "11")
		return (oddmonth_ch());
	else
		return (addmonth_ch());
}

bool BitcoinExchange::reading_csv(std::map<std::string, double> *map)
{
	std::ifstream	file("data.csv");
	std::string		line;
	std::string		key;
	std::string		val;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		this->year = "";
		this->month = "";
		this->day = "";
		size_t			pos = 0;
		if (line_correctly_ch(line) == false)
			return (false);
		key = get_key(line, &pos);
		ready_alldayinfo(key);
		if (date_ch() == false)
			return (false);
		pos = pos + 1;
		val = get_val(line, &pos);
		(*map)[key] = stringToDouble(val);
	}
	std::cout << "<< ready database >>" << std::endl;
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
		this->csv_correct_ornot = reading_csv(&(this->csv_info));
	else
	{
		std::cout << "data.csv does not exists" << std::endl;
		this->csv_correct_ornot = false;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	//何もしない
}
