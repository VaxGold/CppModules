/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:47 by omercade          #+#    #+#             */
/*   Updated: 2023/03/21 21:24:34 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include "BitcoinExchange.hpp"

int main(int narg, char **xarg)
{
    FILE *file;
    BitcoinExchange bte;

    if (narg != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    file = fopen(xarg[1], "r");
    if (file == NULL)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    BitcoinExchange bte(file);
    std::cout << bte;
    fclose(file);
    return (0);
}
