/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:53:20 by theog             #+#    #+#             */
/*   Updated: 2025/08/21 17:33:55 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


bool check_forbidden_char(std::string str)
{
    if (str.empty())
    {
        std::cerr << "Error: Empty arg not allowed" << std::endl;
        return false;            
    }
    for(size_t i = 0; str[i]; i++)
    {
        if(!std::isdigit(str[i]))
        {
            std::cerr << "Error: Forbidden char detected please use digits only" << std::endl;
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

void make_pair_tab(t_pair_vec& pair_tab, char **argv)
{
    size_t i = 1;

    while(argv[i] && argv[i + 1])
    {
        int a, b;
        std::pair<int, int> pair;
        a = std::stoi(argv[i]);
        if (argv[i + 1] != NULL)
            b = std::stoi(argv[i + 1]);
        else 
            b = -1;
        if (a > b)
        {
            pair.first = a;
            pair.second = b;
        }
        else
        {
            pair.first = b;
            pair.second = a;
        }
        pair_tab.push_back(pair);
        i += 2;
    }
}

void print_pair_tab(t_pair_vec pair_vec)
{
    for(t_pvec_it it = pair_vec.begin(); it != pair_vec.end(); it++)
    {
        std::cout << "--VECTOR--" << std::endl;
        std::cout << "first = " << it->first << " second = " << it->second << std::endl;
    }
    std::cout << std::endl;
}

void PmergeSort(char **argv, int argc)
{
    t_pair_vec pair_tab;
    int rest = -1;

    if (argc == 2)
    {
        std::cout << argv[1] << std::endl;
        return;
    }

    if ((argc - 1) % 2 != 0)
        rest = std::stoi(argv[argc -1]);

    make_pair_tab(pair_tab, argv);
    print_pair_tab(pair_tab);
    if (rest != -1)
        std::cout << "rest is " << rest << std::endl;
}