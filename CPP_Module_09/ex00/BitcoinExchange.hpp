#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>

#define GREEN RESET "\e[38;2;210;210;0m"
#define PURPLE RESET "\e[38;2;170;50;170;1m"
#define ERROR RESET "\e[38;2;224;17;95;1;4m"
#define HIGHLIGHTED_ERROR RESET "\e[38;2;235;235;235;1;4m" "\e[48;2;224;17;95m"
#define RESET "\e[0m"


class BitcoinExchange
{
	public:
		BitcoinExchange(int argc = 0, char **argv = NULL);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

	private:
		std::ifstream file;
		std::pair<std::string, float> input_line;
		std::string input_date;
		float input_value;
		std::string current_line;
		std::map<std::string, float> data_lines;

		void verif_params(int argc, char **argv);
		void fill_data_lines();
		std::string parse_date(std::string date);
		float parse_value(std::string value);
		void parse_line();
		std::map<std::string, float>::iterator skip_to_date(int begin, int end, std::map<std::string, float>::iterator it);
		std::map<std::string, float>::iterator find_line();
		void calculate_line(std::map<std::string, float>::iterator it);
};
