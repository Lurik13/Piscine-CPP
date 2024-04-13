/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:47:06 by lribette          #+#    #+#             */
/*   Updated: 2024/04/13 10:17:48 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap R2D2("R2D2");
    ClapTrap C3PO("C-3PO");

    R2D2.attack("C-3PO");
    C3PO.takeDamage(3);
    C3PO.beRepaired(1);
    R2D2.attack("C-3PO");
    C3PO.takeDamage(3);
    C3PO.beRepaired(1);
    R2D2.attack("C-3PO");
    C3PO.takeDamage(3);
    C3PO.beRepaired(1);
    R2D2.attack("C-3PO");
    C3PO.takeDamage(3);
    C3PO.beRepaired(1);
    R2D2.attack("R5-D4");
    R2D2.attack("GNK");
    R2D2.attack("DUM");
    R2D2.attack("MSE-6");
    R2D2.attack("BD-1");
    R2D2.attack("EG-6");
    R2D2.attack("RIC-920");
    R2D2.beRepaired(100);
}