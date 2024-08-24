#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int argc, char **argv)
{
	verif_params(argc, argv);
	fill_data_lines();
	while (std::getline(this->file, this->current_line))
	{
		try
		{
			parse_line();
			std::map<std::string, float>::iterator it = find_line();
			calculate_line(it);
		}
		catch(const std::exception& e)
		{
	        std::cerr << PURPLE "ERROR:" RESET " " ERROR << e.what() << "\n" RESET;
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	*this = src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	this->file.close();
}

void BitcoinExchange::verif_params(int argc, char **argv)
{
	if (argc != 2)
		throw(std::runtime_error(PURPLE "Bad usage:" RESET " " ERROR "./btc <file>"));
	this->file.open(argv[1], std::ifstream::in);
	if (!this->file)
		throw(std::runtime_error("I don't know this file 👀"));
}

void BitcoinExchange::fill_data_lines()
{
	std::ifstream data_file;
	std::string current_data_line = "";

	data_file.open("data.csv", std::ifstream::in);
	if (!data_file)
		throw(std::runtime_error("WHERE IS data.csv ? 🤬"));
	std::getline(data_file, current_data_line);
	while (std::getline(data_file, current_data_line))
	{
		this->data_lines.insert(std::pair<std::string, float>( \
			current_data_line.substr(0, 10),
			atof(current_data_line.substr(11, current_data_line.size()).c_str())));
	}
}


std::string BitcoinExchange::parse_date(std::string date)
{
	if (date.size() != 10)
		throw(std::runtime_error("invalid date size ➤ " HIGHLIGHTED_ERROR + date + RESET));
	for(int i = 0; date[i]; ++i)
	{
		if (((i == 4 || i == 7) && date[i] != '-')
			|| (i != 4 && i != 7 && !isdigit(date[i])))
			throw(std::runtime_error("invalid date format ➤ " HIGHLIGHTED_ERROR + date + RESET));
	}
	return (date);
}

float BitcoinExchange::parse_value(std::string value)
{
	size_t number_of_dots = 0;
	for (size_t i = 0; value[i]; ++i)
	{
		if (i == 0 && value[i] == '-')
			throw(std::runtime_error("not a positive number ➤ " HIGHLIGHTED_ERROR + value + RESET));
		if (((i == 0 || i == value.size() - 1 || number_of_dots > 0) && value[i] == '.')
			|| (value[i] != '.' && !isdigit(value[i])))
			throw(std::runtime_error("invalid value format ➤ " HIGHLIGHTED_ERROR + value + RESET));
		if (value[i] == '.')
			number_of_dots++;
	}
	double return_value = atof(value.c_str());
	if (return_value > 2147483647)
		throw(std::runtime_error("too large number ➤ " HIGHLIGHTED_ERROR + value + RESET));
	return (static_cast<float>(return_value));
}

void BitcoinExchange::parse_line()
{
	size_t value_index = this->current_line.find(" | ");
	if (value_index == std::string::npos)
		throw(std::runtime_error("bad input ➤ " HIGHLIGHTED_ERROR + this->current_line + RESET));
	this->input_line.first = parse_date(this->current_line.substr(0, value_index));
	this->input_line.second = parse_value(this->current_line.substr(value_index + 3));
}

std::map<std::string, float>::iterator BitcoinExchange::skip_to_date( \
	int begin, int end, std::map<std::string, float>::iterator it)
{
	std::string input_string = "";
	std::string data_string = "";
	std::string previous_data_string = "";
	for (int i = begin; i < end; ++i)
		input_string += this->input_line.first[i];
	for (; it != this->data_lines.end(); ++it)
	{
		data_string = "";
		for (int i = begin; i < end; ++i)
			data_string += it->first[i];
		if (atoi(data_string.c_str()) < atoi(previous_data_string.c_str()))
			return (--it);
		previous_data_string = "";
		for (int i = begin; i < end; ++i)
			previous_data_string += it->first[i];
		if (atoi(data_string.c_str()) >= atoi(input_string.c_str()))
			break ;
	}
	if (it == this->data_lines.end())
		return (--it);
	return (it);
}

std::map<std::string, float>::iterator BitcoinExchange::find_line()
{
	std::map<std::string, float>::iterator it = this->data_lines.begin();
	it = skip_to_date(0, 4, it);
	it = skip_to_date(5, 7, it);
	it = skip_to_date(8, 10, it);
	if (it->first != this->input_line.first)
		return (--it);
	return (it);
}

void BitcoinExchange::calculate_line(std::map<std::string, float>::iterator it)
{
	std::cout << GREEN << this->input_line.first << " ➤ " << this->input_line.second
	<< " = \e[4m" << it->second * this->input_line.second << std::endl;
}