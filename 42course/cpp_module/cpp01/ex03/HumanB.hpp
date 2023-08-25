/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:23:26 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 21:35:59 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB{
	private :
		Weapon *WeaponB;
		std::string name;
		HumanB();
	public :
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &WeaponB);
};

#endif
