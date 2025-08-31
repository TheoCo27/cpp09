/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:48:34 by theog             #+#    #+#             */
/*   Updated: 2025/08/31 21:31:59 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::deque<int> jacobsthal_sequence_d(int n) 
{
    std::deque<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    while (seq.back() < n) {
        int m = seq.size();
        seq.push_back(seq[m-1] + 2 * seq[m-2]);
    }
    return seq;
}

void binary_insert_d(std::deque<int>& sorted, int value) 
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