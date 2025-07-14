/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 08:35:35 by theog             #+#    #+#             */
/*   Updated: 2025/07/14 08:42:42 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Need: ./RPN 'your_reverse_polish_expression'" << std::endl;
        return (EXIT_FAILURE);
    }
    if (RP_checker(argv[1]) == false)
        return (EXIT_FAILURE);
    RP_calculator(argv[1]);
    return (0);
}