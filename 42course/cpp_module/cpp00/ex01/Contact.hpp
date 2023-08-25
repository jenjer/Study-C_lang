/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:17 by youngski          #+#    #+#             */
/*   Updated: 2023/08/17 18:30:31 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public :
		Contact();
		std::string Get_number();
		std::string Get_first_name();
		std::string Get_last_name();
		std::string Get_nick_name();
		std::string Get_darkest_secret();

		void Set_number(std::string temp);
		void Set_first_name(std::string temp);
		void Set_last_name(std::string temp);
		void Set_nick_name(std::string temp);
		void Set_darkest_secret(std::string temp);


	private :
		std::string	number;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;

};

#endif
