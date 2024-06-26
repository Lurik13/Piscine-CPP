/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:47:33 by lribette          #+#    #+#             */
/*   Updated: 2024/04/11 11:45:40 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable!\nI want to speak to the manager now."
#define NOT_FOUND "Probably complaining about insignificant problem."

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

