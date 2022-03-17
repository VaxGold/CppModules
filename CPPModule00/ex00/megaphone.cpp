/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:28:16 by omercade          #+#    #+#             */
/*   Updated: 2022/03/15 19:26:44 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int narg, char **xarg)
{
	if (narg == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < narg; i++)
		{
			std::string str(xarg[i]);
			for (size_t j = 0; j < str.length(); j++)
				std::cout << (char)std::toupper(str[j]);
		}
		std::cout << std::endl;
	}
}
