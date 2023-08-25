/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:44:21 by youngski          #+#    #+#             */
/*   Updated: 2023/08/18 17:43:56 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	this->num = 0;
	this->loop = 0;
}

void PhoneBook::Check_func(std::string input_data)
{
	std::cin.clear();
	std::cin.ignore(100,'\n');
	if (std::cin.eof())
		exit(0) ;
	if (std::cin.fail())
	{
		while (std::cin.fail())
		{
			std::cout<<"명확한 값을 입력하세요"<<std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cin>>input_data;
		}
	}
}

void PhoneBook::Add_Contacts()
{
	if (std::cin.eof())
				exit(0);
	std::string temp;
	std::cout<<"공백 없이 입력하세요"<<std::endl;
	std::cout<<"last_name  :";
	std::cin>>temp;
	Contacts[this->num % 9].Set_last_name(temp);
	Check_func(temp);

	std::cout<<"fisrt_name :";
	std::cin>>temp;
	Contacts[this->num % 9].Set_first_name(temp);
	Check_func(temp);

	std::cout<<"nick_name  :";
	std::cin>>temp;
	Contacts[this->num % 9].Set_nick_name(temp);
	Check_func(temp);

	std::cout<<"phone_num  :";
	std::cin>>temp;
	Contacts[this->num % 9].Set_number(temp);
	Check_func(temp);

	std::cout<<"secret     :";
	std::cin>>temp;
	Contacts[this->num % 9].Set_darkest_secret(temp);
	Check_func(temp);
	std::cout<<std::endl;
	this->num++;
	this->num = num % 8;
	this->loop++;
}

void PhoneBook::Select_one(std::string input_data)
{
	int input_data_int;
	if (std::cin.eof())
				exit(0);
	input_data_int = std::atoi(input_data.c_str()) - 1;
	std::cout<<input_data_int + 1<<std::endl;
	std::cout<<"firstname : "<<this->Contacts[input_data_int].Get_first_name()<<std::endl;
	std::cout<<"lastname  : "<<this->Contacts[input_data_int].Get_last_name()<<std::endl;
	std::cout<<"nickname  : "<<this->Contacts[input_data_int].Get_nick_name()<<std::endl;
	std::cout<<"phone     : "<<this->Contacts[input_data_int].Get_number()<<std::endl;
	std::cout<<"secret    : "<<this->Contacts[input_data_int].Get_darkest_secret()<<std::endl;
}

void PhoneBook::Print(std::string for_print)
{
	if (for_print.size() > 9)
	{
		for(int k = 0; k < 9; k++)
			std::cout<<for_print[k];
		std::cout<<".|";
	}
	else
		std::cout<<std::setw(10)<<for_print<<"|";
}

void PhoneBook::Search()
{
	std::string temp;
	std::string selected_num;
	int max;
	int	input_temp;

	if (loop > 8)
		max = 8;
	else
		max = loop;
	if (max == 0)
	{
		std::cout<<"전화번호부가 비었습니다."<<std::endl;
		return ;
	}
	std::cout<<"     index| firstname|  lastname|  nickname"<<std::endl;
	for (int i = 0; i < max; i++)
	{
		std::cout<<std::setw(10)<<i + 1<<"|";
		Print(this->Contacts[i].Get_first_name()); Print(this->Contacts[i].Get_last_name());
		Print(this->Contacts[i].Get_nick_name());
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"몇번 항목을 보시겠습니까? : ";
	std::cin>>selected_num;
	Check_func(selected_num);
	input_temp = std::atoi(selected_num.c_str());
	if (input_temp >= max + 1 || input_temp <= 0 )
	{
		std::cout<<"맞지 않는 인덱스"<<std::endl;
		return ;
	}
	Select_one(selected_num);
}
