/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:33:30 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 17:49:34 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie *asdf;
	Zombie foo;
	Zombie zoo;
	foo.announce();
	zoo.announce();
	asdf = foo.zombieHorde(10, "asdf");
	for(int i = 0; i < 10; i++)
		asdf[i].announce();
	delete[](asdf);

}
