/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:35:28 by youngski          #+#    #+#             */
/*   Updated: 2023/08/18 16:52:53 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout<< this->name << ": BraiiiiiiinnnzzZ..." << std::endl;;
}

Zombie::Zombie()
{
	std::string temp = "foo";
	this->name = temp;	
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout<< this->name << " is deleted"<<std::endl;
}
