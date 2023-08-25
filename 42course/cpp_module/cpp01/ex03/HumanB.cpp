/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:47:44 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 21:40:36 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;	
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->WeaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &WeaponB)
{
	this->WeaponB = &WeaponB;
}

