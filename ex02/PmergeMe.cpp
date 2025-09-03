/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:53:20 by theog             #+#    #+#             */
/*   Updated: 2025/09/03 19:07:13 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


static bool check_forbidden_char(std::string str)
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

            if (str[i] == '-')
                std::cerr << "Error: Only positive int allowed" << std::endl;
            else
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
   // std::cout << "This is a valid input" << std::endl;
    return true;
}


static void make_list(std::vector<int>& list, char **argv)
{
    for(int i = 1; argv[i]; i++)
    {
        std::string str(argv[i]);
        int nb = ft_stoi(str);
        list.push_back(nb);
    }
}

static void make_pair_tab(t_pair_vec& pair_tab, std::vector<int> list)
{
    if (list.size() < 2)
        return;
    std::vector<int>::iterator it = list.begin();
    std::vector<int>::iterator next_it = it + 1;
    while(it != list.end() && next_it != list.end())
    {
        int a, b;
        std::pair<int, int> pair;
        a = *it;
        b = *next_it;
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
        it +=2;
        next_it +=2;
    }
}

// static void print_pair_tab(t_pair_vec pair_vec)
// {
//     for(t_pvec_it it = pair_vec.begin(); it != pair_vec.end(); it++)
//     {
//         std::cout << "--VECTOR--" << std::endl;
//         std::cout << "first = " << it->first << " second = " << it->second << std::endl;
//     }
//     std::cout << std::endl;
// }

static void print_list(std::vector<int> list)
{
    for(std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

static std::vector<int> ford_johnson(std::vector<int> list)
{
    if (list.size() <= 1)
        return list;
    t_pair_vec pair_tab;
    std::vector<int> max_list;
    std::vector<int> min_list;
    std::vector<int>::iterator rest = list.end();
    if (list.size() % 2 != 0)
        rest--;
    make_pair_tab(pair_tab, list);
    for (size_t i = 0; i < pair_tab.size(); i++)
    {
        max_list.push_back(pair_tab[i].first);
        min_list.push_back(pair_tab[i].second);
    }
    std::vector<int> sorted = ford_johnson(max_list);
    std::vector<int> j_seq = jacobsthal_sequence(min_list.size());
    std::vector<bool> index_inserted(min_list.size(), false);
    for(size_t i = 0; i < j_seq.size(); i++)
    {
        int value_index = j_seq[i];
        if (value_index >= static_cast<int>(min_list.size()))
            break;
        int value_to_insert = min_list[j_seq[i]];
        binary_insert(sorted, value_to_insert);
        index_inserted[value_index] = true;
    }
    for(size_t i = 0; i < min_list.size(); i++)
    {
        if(index_inserted[i] == false)
            binary_insert(sorted, min_list[i]);
    }
    if (rest != list.end())
        binary_insert(sorted, *rest);
    
    return sorted;
}

// static bool check_if_sorted(std::vector<int> list)
// {
//     for(std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
//     {
//         std::vector<int>::iterator next_it = it + 1;

//         if (next_it == list.end())
//             break;
//         if (*it > *next_it)
//         {
//             std::cout << "List is not sorted" << std::endl;
//             return false;
//         }
//     }
//     std::cout << "List is sorted" << std::endl;
//     return true;
// }

void PmergeSort(char **argv, int argc)
{
    std::vector<int> list;
    std::vector<int> sorted;

    if (argc == 2)
    {
        std::cout << argv[1] << std::endl;
        return;
    }
    make_list(list, argv);
    std::cout << "Before : ";
    print_list(list);
    sorted = ford_johnson(list);
    std::cout << "After : ";
    print_list(sorted);
   // check_if_sorted(sorted);
}