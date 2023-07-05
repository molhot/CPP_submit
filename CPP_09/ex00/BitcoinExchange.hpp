/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:49:04 by user              #+#    #+#             */
/*   Updated: 2023/07/05 22:39:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	csv_info;
		std::string						year;
		std::string						month;
		std::string						day;
		bool							csv_correct_ornot;
		bool							reading_csv(std::map<std::string, double> 	*sub_map);
		bool							line_correctly_ch(std::string line);
		bool							month_ch(char left, char right);
		bool							day_ch(char left, char right);
		bool							rate_ch(std::string ratio);
		std::string						get_key(std::string line, size_t *pos);
		std::string						get_val(std::string line, size_t *pos);
		double							stringToDouble(const std::string &str);
		void							ready_alldayinfo(const std::string &day_info);
		bool							date_ch(void);
		bool							oddmonth_ch(void);
		bool							addmonth_ch(void);
		bool							uru_ch(void);
		bool							not_uru_ch(void);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		bool							line_correctlyexit(void);
		std::map<std::string, double>	csvinfo_return(void);
		int								text_format_check(std::string line);
		void							show_error(int error_num);
		void							show_correct(void);
};

#endif