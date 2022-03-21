/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:57 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 12:09:40 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

int	main( int argc, char **argv )
{
	if (argc == 1)
	{
		std::cerr << "[ Amazing ! Karen is totally quiet... or I'm deaf... ]" << std::endl;
		return (1);
	}
	if (argc != 2)
	{
		std::cerr << "[ Karen is saying many things at once ! ]" << std::endl;
		return (1);
	}
    Karen karen(argv[1]);
	karen.complain();
}
