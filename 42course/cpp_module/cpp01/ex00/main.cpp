/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:33:30 by youngski          #+#    #+#             */
/*   Updated: 2023/08/20 15:27:57 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie foo;
	Zombie zoo;
	foo.announce();
	zoo.announce();
	Zombie *newzombie = foo.newZombie("first");
	Zombie *newzombie1 = zoo.newZombie("second");
	std::cout << std::endl;
	newzombie->announce();
	newzombie1->announce();
	std::cout << std::endl;
	newzombie->randomChump("first_random!!");
	newzombie1->randomChump("second_random!!");
	
}
