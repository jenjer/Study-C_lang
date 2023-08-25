/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:52:35 by youngski          #+#    #+#             */
/*   Updated: 2023/08/23 18:12:51 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string *stringPTR;
	std::string Brain;
	Brain = "HI THIS IS BRAIN";
	std::string &stringREF = Brain;
	stringPTR = &Brain;

	std::cout <<"The memory address of the string variable = " << &Brain << std::endl;
	std::cout <<"The memory address held by stringPTR = " << stringPTR << std::endl;
	std::cout <<"The memory address held by stringREF = " << &stringREF << std::endl;

	std::cout <<"The value of the string variable = " << Brain<< std::endl;
	std::cout <<"The value pointed to by stringPTR = "<< *stringPTR<<std::endl;
	std::cout <<"The value pointed to by stringREF = "<< stringREF<<std::endl;
	
}
