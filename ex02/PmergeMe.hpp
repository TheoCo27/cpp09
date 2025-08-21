/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:53:17 by theog             #+#    #+#             */
/*   Updated: 2025/08/21 17:32:30 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>

typedef std::vector<std::pair<int, int> > t_pair_vec;
typedef std::vector<std::pair<int, int> >::iterator t_pvec_it;

bool checker(char **argv);
void PmergeSort(char **argv, int argc);