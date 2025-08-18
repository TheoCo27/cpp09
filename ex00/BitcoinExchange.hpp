/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:30:07 by tcohen            #+#    #+#             */
/*   Updated: 2025/08/18 14:21:35 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

typedef struct s_date
{
	int year;
	int month;
	int day;
}t_date;

int BitcoinExchange(std::string infile);
bool ends_with(std::string str, std::string suffix);
bool check_input_line(std::string line);