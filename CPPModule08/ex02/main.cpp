/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:13:24 by omercade          #+#    #+#             */
/*   Updated: 2022/03/31 16:46:18 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::cout << "## ORIGINAL TEST ##" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n## EXTRA TEST WITH LIST ##" << std::endl;
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(21);
	lst.push_back(89);
	lst.push_back(555);
	std::cout << "List with size " << lst.size() << std::endl;
	std::list<int>::reverse_iterator l_start = lst.rbegin();
	std::list<int>::reverse_iterator l_end = lst.rend();
	++l_start;
	--l_start;
	while (l_start != l_end)
	{
		std::cout << *l_start << std::endl;
		++l_start;
	}
	
	return (0);
}
