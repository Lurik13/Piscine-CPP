/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:47:50 by lribette          #+#    #+#             */
/*   Updated: 2024/04/12 19:16:45 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	open_outfile(std::fstream& outputFile, std::string outputName)
{
	outputFile.open(outputName.c_str(), std::fstream::out | std::fstream::trunc);
	if (!outputFile)
	{
		std::cout << "Error while opening " << outputName << ".\n";
		return (EXIT_FAILURE);
	}
	outputFile.close();

	outputFile.open(outputName.c_str(), std::fstream::out | std::fstream::app);
	if (!outputFile)
	{
		std::cout << "Error while opening " << outputName << ".\n";
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

std::string	replace_by_s2(std::string current_line, std::string s1, std::string s2)
{
	size_t	len_s1 = s1.length();
	for (size_t i = 0; i < current_line.length(); i++)
	{
		if (current_line[i] == s1[0] && !current_line.compare(i, len_s1, s1))
		{
			current_line.erase(i, len_s1);
			current_line.insert(i, s2);
			i += s2.length();
		}
	}
	return (current_line);
}

void	replace(std::fstream &inputFile, std::string outputName, \
	std::string s1, std::string s2)
{
	std::fstream	outputFile;
	std::string		current_line = "";
	outputName += ".replace";
	int	number_of_lines = 0;

	if (open_outfile(outputFile, outputName) == EXIT_SUCCESS)
	{
		while (std::getline(inputFile, current_line, '\0'))
		{
			if (!current_line.empty() && number_of_lines++)
				outputFile << std::endl;
			current_line = replace_by_s2(current_line, s1, s2);
			outputFile << current_line;
		}
		outputFile.close();
	}
}
