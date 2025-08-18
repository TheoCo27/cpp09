/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:30:02 by tcohen            #+#    #+#             */
/*   Updated: 2025/08/18 17:43:27 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int data_to_map(std::map<t_date, float>& data_map) // prendre en parametre la reference de la map
{
	int year, month, day;
	float value;
	char dash1, dash2, comma, extra;
	int line_count = 0;
	std::ifstream file("data.csv");
	if (file.fail())
	{
		throw std::invalid_argument("Cannot open file");
		return 1;
	}
	std::string line;
	while(getline(file, line))
	{
		if (line_count == 0)
		{
			line_count++;
			continue;
		}
		t_date date;
		std::stringstream ss(line);
		ss >> year >> dash1 >> month >> dash2 >> day >> comma >> value;
		if (ss.fail() || dash1 != '-' || dash2 != '-' || comma != ',' || ss >> extra)
		{
			std::cerr << "Error: data.csv corrupted" << std::endl;
			return 1;
		}
		date.day = day;
		date.year = year;
		date.month = month;
		data_map[date] = value;
	}
	file.close();
	return 0;
}


void convert_input(std::map<t_date, float>& data_map, t_date date, float value)
{
	std::map<t_date, float>::iterator it = data_map.lower_bound(date);

    if (it == data_map.end() || it->first != date) {
        if (it == data_map.begin()) {
            std::cerr << "Error: no available date before " 
                      << date.year << "-" << date.month << "-" << date.day << std::endl;
            return;
        }
        --it;
    }

    float rate = it->second;
    float result = rate * value;

    std::cout << date.year << "-";
	if (date.month < 10)
		std::cout << "0";
	std ::cout << date.month << "-"; 
	if (date.day < 10)
		std::cout << "0";	
	std :: cout << date.day << " => " << value << " = " << result << std::endl;

}


int BitcoinExchange(std::string infile)
{
	float value;
	char dash1, dash2, pipe;
	int line_count = 0;
	std::ifstream file(infile.c_str());
	if (ends_with(infile, ".csv") == false)
	{
		std::cerr << "Error: file needs to end with .csv" << std::endl;
		return 1;
	}
	if (file.fail())
	{
		throw std::invalid_argument("Cannot open file");
		return 1;
	}
	std::map<t_date, float> data_map;
	if (data_to_map(data_map) == 1)
		return 1;
	std::string line;
	while(getline(file, line))
	{
		if (line_count == 0)
		{
			line_count++;
			continue;
		}
		if (check_input_line(line) == false)
			continue;
		std::stringstream ss(line);
		t_date date;
		ss >> date.year >> dash1 >> date.month >> dash2 >> date.day >> pipe >> value;
		convert_input(data_map, date, value);
	}
	file.close();
	return 0;
}