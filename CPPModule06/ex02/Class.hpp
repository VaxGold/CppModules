/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:11:17 by omercade          #+#    #+#             */
/*   Updated: 2022/03/29 15:43:46 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

# include <stdlib.h>
# include <time.h>

class Base
{
	public:
		virtual	~Base() {};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base *generate();
void identify(Base *p);

#endif
