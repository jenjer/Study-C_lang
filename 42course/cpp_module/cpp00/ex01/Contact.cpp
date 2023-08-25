/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:51:37 by youngski          #+#    #+#             */
/*   Updated: 2023/08/17 18:37:25 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

std::string Contact::Get_number()
{
	return this->number;
}

std::string Contact::Get_first_name()
{
	return this->first_name;
}

std::string Contact::Get_last_name()
{
	return this->last_name;
}

std::string Contact::Get_nick_name()
{
	return this->nick_name;
}

std::string Contact::Get_darkest_secret()
{
	return this->darkest_secret;
}

void Contact::Set_number(std::string temp)
{
	this->number = temp;
}

void Contact::Set_first_name(std::string temp)
{
	this->first_name = temp;
}

void Contact::Set_last_name(std::string temp)
{
	this->last_name = temp;
}

void Contact::Set_nick_name(std::string temp)
{
	this->nick_name = temp;
}

void Contact::Set_darkest_secret(std::string temp)
{
	this->darkest_secret = temp;
}
