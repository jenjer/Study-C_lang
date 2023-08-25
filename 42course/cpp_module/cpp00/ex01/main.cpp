/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:18:51 by youngski          #+#    #+#             */
/*   Updated: 2023/08/17 18:38:41 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	mybook;
	int			input;

	while (1)
	{
		while (true)
		{
			std::cout<<std::endl;
			std::cout<<"동작 번호를 선택해주세요"<<std::endl;
			std::cout<<"1. Add\n2. Search\n3. Exit"<<std::endl;
			if (!(std::cin>>input))
			{
				if (std::cin.eof())
					exit(0);
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"유효한 입력이 아닙니다."<<std::endl;
				continue;
			}
			if (input > 3 || input <= 0)
				std::cout<<"유효한 입력이 아닙니다."<<std::endl;
			switch(input)
			{
				case 1 :
					mybook.Add_Contacts();
					break;
				case 2 :
					mybook.Search();
					break;
				case 3 :
					exit(0);
			}
		}	
	}
}
