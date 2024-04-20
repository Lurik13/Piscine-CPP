/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:03 by lribette          #+#    #+#             */
/*   Updated: 2024/04/20 11:26:15 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int err()
{
    std::cout << "./bureaucrat <std::string name> <int grade>\n";
    return (1);
}

int which_grade(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            throw (err());
    }
    return (std::atoi(str));
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        try
        {
            Bureaucrat(argv[1], which_grade(argv[2]));
        }
        catch(...)
        {
            
        }
    }
    else
        err();
}