/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:47 by omercade          #+#    #+#             */
/*   Updated: 2023/05/08 17:39:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int narg, char **xarg)
{
    /* CHECKING THE FILE */
    FILE *file;
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
    fclose(file);

    /* RUN BTC */
    std::string route(xarg[1]);
    BitcoinExchange bte(route);
    std::cout << bte;
    
    return (0);
}
