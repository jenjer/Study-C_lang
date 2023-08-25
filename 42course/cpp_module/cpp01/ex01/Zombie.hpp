/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:35:36 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 17:45:17 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie{
	private :
		std::string name;
	public :
		Zombie();
		~Zombie();
		Zombie(std::string name);
		Zombie* newZombie(std::string name);
		Zombie* zombieHorde(int N, std::string name);
		void	randomChump(std::string name);
		void	announce(void);
		void	set_name(std::string name);
};

#endif
