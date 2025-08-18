/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:46:30 by tcohen            #+#    #+#             */
/*   Updated: 2025/08/18 12:30:44 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool ends_with(std::string str, std::string suffix)
{
	if (str.length() <= suffix.length())
		return (false);
	if (str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0)
		return (true);
	return (false);
}

bool check_if_valid_int(std::string str)
{
	std::stringstream ss(str);
	int nb;
	char leftover;
	ss >> nb;
	if (ss.fail())
		return (false);
	if (nb > 1000 || nb < 0)
		return (false);
	if (ss >> leftover)
	{
		std::cerr << "extra char detected in value" << std::endl;
		return false;
	}
	return (true);
}

bool check_if_valid_float(std::string str)
{
	std::stringstream ss(str);
	float nb;
	char leftover;
	ss >> nb;
	if (ss.fail())
		return (false);
	if (nb > 1000 || nb < 0)
		return (false);
	if (ss >> leftover)
	{
		std::cerr << "extra char detected in value" << std::endl;
		return false;
	}
	return (true);
}

bool check_date(std::string date)
{
	std::cout << date <<  std::endl;
	std::stringstream ss(date);
	char dash1, dash2;
	unsigned int year, month, day;
	char extra;
	unsigned int tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	ss >> year >> dash1 >> month >> dash2 >> day;
	if (ss.fail() || dash1 != '-' || dash2 != '-') 
	{	std::cout << "string stream failed\n";
		return false;
	}
	if (year < 2009 || year > 2025 || month > 12 || month < 1)
		return false;
	if (day > tab[month - 1] || day < 1)
		return false;
	if (ss >> extra)
	{
		std::cerr << "extra char detected in date" << std::endl;
		return false;
	}

	return true;
}

bool check_value(std::string value)
{
	std::cout << value << std::endl;
	if (check_if_valid_int(value) == false && check_if_valid_float(value) == false)
		return false;
	return true;
}

bool check_input_line(std::string line)
{
	if (line.find('|') == std::string::npos)
	{
		std::cerr << "No delimiter '|' found\n";
		return false;
	}
	int delimiter_pos = line.find('|');
	if (check_date(line.substr(0, delimiter_pos)) == false)
	{	std::cerr << "Wrong date format" << std::endl;
		return false;
	}
	std:: cout << "valid date\n";
	if (check_value(line.substr(delimiter_pos + 1, line.length() - delimiter_pos)) == false)
	{
		std::cerr << "value has to be a positive int or float between 0 & 1000" << std::endl;
		return false;
	}
	std::cout << "valid value\n";
	return true;
}