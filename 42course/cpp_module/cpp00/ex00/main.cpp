/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:18:57 by youngski          #+#    #+#             */
/*   Updated: 2023/05/31 13:23:16 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	std::string for_print;

	if (argc == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	for(int k = 1; k < argc; k++)
	{
		for_print = argv[k];
		for(std::size_t i = 0; i < for_print.size(); i++)
		{
			std::cout<<(char)toupper(for_print[i]);
		}
		std::cout<<" ";
	}
	std::cout<<std::endl;
	return (0);
}
