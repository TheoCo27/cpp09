/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:30:02 by tcohen            #+#    #+#             */
/*   Updated: 2025/08/18 15:16:15 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int data_to_map(void) // prendre en paraetre la reference de la map
{

}

void convert_input(std::string line)
{
	
}


int BitcoinExchange(std::string infile)
{
	std::ifstream file(infile.c_str());

	if (file.fail())
		throw std::invalid_argument("Cannot open file");
	// recup data.csv et convertit la en map ici
	std::string line;
	while(getline(file, line))
	{
		check_input_line(line);
		//convert input
	}
	file.close();
	return 0;
}