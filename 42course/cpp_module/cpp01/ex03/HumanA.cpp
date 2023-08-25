/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:22:42 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 21:40:24 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &WeaponA) : WeaponA(WeaponA)
{
	this->name = name;
	this->WeaponA = WeaponA;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->WeaponA.getType() << std::endl;
}
