/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:03:29 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 19:19:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    Cat basic;
    {
	    Cat tmp = basic;
    }

    delete j; 
    delete i;
}
