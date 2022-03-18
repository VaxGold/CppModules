/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:57 by omercade          #+#    #+#             */
/*   Updated: 2022/03/18 20:02:42 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

void	complain(std::string level)
{
	Karen karen(level);

	karen.complainRoutine();
}

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments!" << std::endl;
		return (1);
	}
    Karen karen(argv[1]);
	karen.complain();
}
