/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:30:07 by tcohen            #+#    #+#             */
/*   Updated: 2025/08/18 10:48:45 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

int BitcoinExchange(std::string infile);
bool ends_with(std::string str, std::string suffix);
bool check_input_line(std::string line);