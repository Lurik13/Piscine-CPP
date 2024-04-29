/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:19:00 by lribette          #+#    #+#             */
/*   Updated: 2024/04/05 17:03:12 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "str address = " << &str << std::endl;
    std::cout << "stringPTR address = " << &stringPTR << std::endl;
    std::cout << "stringREF address = " << &stringREF << std::endl << std::endl;

    std::cout << "str value = " << str << std::endl;
    std::cout << "stringPTR value = " << *stringPTR << std::endl;
    std::cout << "stringREF value = " << stringREF << std::endl;
}
