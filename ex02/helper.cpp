/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:48:34 by theog             #+#    #+#             */
/*   Updated: 2025/08/31 21:18:49 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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