/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:47:33 by lribette          #+#    #+#             */
/*   Updated: 2024/04/09 10:35:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define DEBUG_MSG "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n"
#define INFO_MSG "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n"
#define WARNING_MSG "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n"
#define ERROR_MSG "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now."
#define NOT_FOUND "[ Probably complaining about insignificant problem. ]"

#define GREEN "\033[38;2;32;212;25;1m"
#define PURPLE "\033[38;2;127;59;243;1m"
#define ORANGE "\033[38;2;249;151;24;1m"
#define RED "\033[38;2;222;55;55;1m"
#define WHITE "\033[38;2;255;255;255;1m"
#define RESET "\033[0m"

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

