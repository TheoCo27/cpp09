/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:53:26 by theog             #+#    #+#             */
/*   Updated: 2025/08/21 17:32:42 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error, need: ./PmergeMe your_list_to_sort" << std::endl;
        return(EXIT_FAILURE);
    }
    if (checker(argv) == false)
        return(EXIT_FAILURE);
    try{
        PmergeSort(argv, argc);
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}