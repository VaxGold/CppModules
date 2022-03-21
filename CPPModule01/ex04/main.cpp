/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:48:06 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:40:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 4)
		std::cout << "error: Invalid number of arguments" << std::endl;
	else
		Sed::replace(argv[1], argv[2], argv[3]);
	return (0);
}
