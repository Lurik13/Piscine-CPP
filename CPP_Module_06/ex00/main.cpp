/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:53:38 by lribette          #+#    #+#             */
/*   Updated: 2024/05/01 15:31:48 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int verif_param(char **argv, ScalarConverter &convert)
{
	int nb_dots = 0;

	convert.setValue(argv[1]);
	if (convert.getValue().length() == 1 && !isdigit(convert.getValue()[0]))
	{
		convert.setType("char");
		return (0);
	}
	for (int i = 0; convert.getValue()[i]; i++)
	{
		if (convert.getValue()[i] == '.')
			nb_dots++;
		if (nb_dots > 1 || (convert.getValue()[i] == '.' && (i == 0 || !convert.getValue()[i + 1]))
			|| (convert.getValue()[i] == 'f' && (i == 0 || convert.getValue()[i + 1]))
			|| (!isdigit(convert.getValue()[i]) && convert.getValue()[i] != '.' && convert.getValue()[i] != 'f')
			|| (convert.getValue()[i] == '.' && convert.getValue()[i + 1] && convert.getValue()[i + 1] == 'f')
			|| (convert.getValue()[i] == 'f' && nb_dots == 0))
			convert.setType("impossible");
	}
	return (nb_dots);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter *convert = new ScalarConverter;
		bool nb_dots = verif_param(argv, *convert);
		if (nb_dots && convert->getType() != "")
		{
			convert->setType("double");
			if (convert->getValue()[convert->getValue().length() - 1] == 'f'
				&& convert->getType() != "")
				convert->setType("float");
		}
		else if (convert->getType() == "")
			convert->setType("int");
		convert->print();
		delete convert; /////////////////////////////////////////////////////////////////////
	}
}
