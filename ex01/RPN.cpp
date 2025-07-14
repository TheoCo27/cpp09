/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 08:35:38 by theog             #+#    #+#             */
/*   Updated: 2025/07/14 09:46:57 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool check_allowed_whitespace(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::isspace(static_cast<int>(str[i])))
			if(str[i] != ' ')
			{
				std::cerr << "Error: Only spaces allowed" << std::endl;
				return false;
			}
	}
	return true;
}

bool check_forbidden_char(std::string input)
{
    if (input.empty())
    {
        std::cerr << "Input cannot be empty" << std::endl;
        return false;
    }
    if (check_allowed_whitespace(input) == false)
        return false;
    for(int i = 0; input[i]; i++)
    {
        if (!std::isdigit(static_cast<int>(input[i])) && input[i] != '-' 
            && input[i] != '+' && input[i] != '*' && input[i] != '/' && input[i] != ' ')
        {
            std::cerr << "Error: Use only digits and + - * / operators" << std::endl;
            return false;
        }   
    }
    return true;
}

bool check_operator_nb(std::string input)
{
    int op_count = 0, space_count = 0, nb_count = 0;

    for(int i = 0; input[i]; i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            op_count++;
        if (input[i] == ' ')
            space_count++;
    }
    nb_count = input.length() - space_count - op_count;
    if (op_count < 1 || nb_count < 2)
    {
        std::cerr << "Error: You need at least one digit and one operator" << std::endl;
        return false;
    }
    if(!(nb_count == op_count + 1))
    {
        if (nb_count > op_count + 1)
            std::cerr << "Too much numbers or not enough operators" << std::endl;
        if (nb_count < op_count + 1)
            std::cerr << "Too much operators or not enough numbers" << std::endl;
        return false;
    }
    return true;
}

bool RP_checker(std::string input)
{
    if (check_forbidden_char(input) == false)
        return false;
    if (check_operator_nb(input) == false)
        return false;
    std::cout << "this is a valid input" << std::endl;
    return true;
}


int RP_calculator(std::string input)
{
    std::stack<int> rp_stack;
    

    return 0;
}