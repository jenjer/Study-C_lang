/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:46:06 by youngski          #+#    #+#             */
/*   Updated: 2023/08/24 17:21:44 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "argument num error!" << std::endl;
		return (0);
	}
	std::string outfilename(argv[2]);
	outfilename = outfilename + ".repalce";
	std::ifstream input(argv[1]);

	if (!input.is_open())
	{
		std::cout << "file open error" << argv[1] << std::endl;
		return (1);
	}

	std::ofstream output(outfilename);
	if (!output.is_open())
	{
		std::cout << "output file error"<< outfilename << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(input, line))
	{
		size_t start = 0;
		while ((start = line.find(s1, startPos)) != std::string::npos)
		{
			output << line.substr(0, start);
		}
	}
	
		


}
