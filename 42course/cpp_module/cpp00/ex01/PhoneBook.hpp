/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:03 by youngski          #+#    #+#             */
/*   Updated: 2023/08/18 18:03:36 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	private :
		int		num;
		int		loop;
		Contact Contacts[8];
		
	public :
		PhoneBook();
		void	Add_Contacts();
		void	Search();
		void	Print(std::string for_print);
		void	Check_func(std::string input_data);
		void	Select_one(std::string input_data);
};

#endif
