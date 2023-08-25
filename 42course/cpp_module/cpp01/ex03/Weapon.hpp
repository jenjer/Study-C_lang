/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:19:31 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 21:38:53 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define  WEAPON_HPP

#include <iostream>

class Weapon{
	private :
		std::string type;
	public :
		Weapon(std::string type);
		std::string getType();
		void setType(std::string type); 
};

#endif
