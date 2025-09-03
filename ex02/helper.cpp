/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:48:34 by theog             #+#    #+#             */
/*   Updated: 2025/09/03 19:12:44 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int ft_stoi(std::string str)
{
	long value = 0;

	if (str.size() > 11)
	{
		throw std::invalid_argument("str too long to be converted to int");
		return -1;
	}
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] == '-' && i != 0)
		{
			throw std::invalid_argument("cannot convert str to int, sign at wrong position");
			return -1;
		}
		if (!std::isdigit(static_cast<int>(str[i])))
		{
			throw std::invalid_argument("cannot convert str to int, invalid char detected");
			return -1;
		}
	}
	value = std::atol(str.c_str());
	if (value > 2147483647 || value < -2147483648)
	{
			throw std::invalid_argument("value out of int range");
			return -1;
	}
	return (static_cast<int>(value));

}

std::vector<int> jacobsthal_sequence(int n) 
{
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    while (seq.back() < n) {
        int m = seq.size();
        seq.push_back(seq[m-1] + 2 * seq[m-2]);
    }
    return seq;
}

void binary_insert(std::vector<int>& sorted, int value) 
{
    int min = 0;
    int max = sorted.size();

    while (min < max) {
        int mid = min + (max - min) / 2;

        if (sorted[mid] < value)
            min = mid + 1;
        else
            max = mid;
    }
    sorted.insert(sorted.begin() + min, value);
}

double timer(int mode)
{
    static clock_t start_time = 0;

    if (mode == 0) { // START
        start_time = clock();
        return 0.0;
    } else { // STOP
        clock_t end_time = clock();
        double elapsed_us = double(end_time - start_time) * 1e6 / CLOCKS_PER_SEC; // microsecondes
        return elapsed_us;
    }
}
void print_time(size_t nb_elements, std::string container_name)
{
    double elapsed_us = timer(1);
    std::cout << "Time to process a range of "
              << nb_elements
              << " elements with std::" << container_name
              << " : "
              << std::fixed
              << std::setprecision(5)
              << elapsed_us
              << " us"
              << std::endl;
}