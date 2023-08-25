/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:22:50 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 21:20:11 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA{
	private :
		Weapon &WeaponA;
		std::string name;
	public :
		HumanA(std::string name, Weapon &WeaponA);
		void attack();
};

#endif
