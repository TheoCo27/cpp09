/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:53:20 by theog             #+#    #+#             */
/*   Updated: 2025/08/20 18:18:41 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


bool check_forbidden_char(std::string str)
{
    for(size_t i = 0; str[i]; i++)
    {
        if(!std::isdigit(str[i]))
        {
            std::cerr << "Error: Forbidden char detected please use digit only" << std::endl;
            return false;
        }
    }
    return true;
}

bool checker(char **argv)
{
    for(size_t i = 1; argv[i]; i++)
    {
        if(check_forbidden_char(argv[i]) == false)
            return false;
    }
    std::cout << "This is a valid input" << std::endl;
    return true;
}