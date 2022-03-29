/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:56 by omercade          #+#    #+#             */
/*   Updated: 2022/03/29 19:17:20 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
 #define ITER_HPP
 
# include <iostream>

template <typename T>

void    iter(T *array, size_t len, void (*f)(T const &a))
{
    for (size_t i = 0; i < len; i++)
        (*f)(array[i]);
}

#endif
