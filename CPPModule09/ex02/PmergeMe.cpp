#include "PmergeMe.hpp"

// ----> LIST <---- //

SortList::SortList() { }

SortList::SortList(char **data)
{
	int i = 1;
	
	while (data[i] != 0)
	{
		std::istringstream tmp(data[i]);
		std::string token;
		while (tmp >> token)
			this->_data.push_back(atoi(token.c_str()));
		i++;
	}
	this->sortMI();
}

SortList::SortList(std::list<int> lst): _data(lst) 
{
	this->sortMI();
}

SortList::SortList(SortList const &other)
{
	*this = other;
}

SortList &SortList::operator=(SortList const &other)
{
	if (this != &other)
	{
		this->_data = other.getData();
	}
	return (*this);
}

SortList::~SortList() { }

void SortList::sortMI() 
{
	std::list<int> left;
	std::list<int> right;
	int n = -1;

	// std::cout << "INSIGHT: " << *this << std::endl;
	if (this->getData().size() <= 3)
		this->_data.sort();
	else
	{
		size_t i = 0;
		size_t size = this->getData().size();
		for(std::list<int>::iterator it = this->getData().begin(); it != this->getData().end(); ++it)
		{
			if (i < size / 2)
				left.push_back(*it);
			else if (i > size / 2 && i < size / 2 * 2)
				right.push_back(*it);
			else
				n = *it;
			i++;
		}
		SortList lst_l(left);
		this->_data = lst_l.getData();
		SortList lst_r(right);
		this->merge(lst_r.getData());
		this->_data.sort();
		if (n != -1)
			this->insert(n);







		// std::list<int>::iterator it = this->getData().begin();
		// for(; it != this->getData().end(); ++it)
		// {
		// 	if (i < (this->getData().size() / 2))
		// 		break;
		// 	std::cout << "ELEMENT TO STORE: " << *it << std::endl;
		// 	aux.push_back(*it);
		// 	i++;
		// }
		// while (i < (this->getData().size() / 2))
		// {
		// 	std::cout << "ELEMENT TO STORE: " << *it << std::endl;
		// 	aux.push_back(*it);
		// 	i++;
		// }
		// SortList left(aux);
		// aux.clear();
		// this->_data = left.getData();
		// for(; it != this->getData().end(); ++it)
		// {
		// 	if (i < ((this->getData().size() / 2) * 2))
		// 		break;
		// 	std::cout << "ELEMENT TO STORE: " << *it << std::endl;
		// 	aux.push_back(*it);
		// 	i++;
		// }
		// while (i < (this->getData().size() / 2) * 2)
		// {
		// 	aux.push_back(*it);
		// 	i++;
		// }
		// SortList right(aux);
		// aux.clear();
		// this->merge(right.getData());
		// if (it != this->getData().end())
		// 	n = *it;
		// this->_data.sort();
		// if (n != -1)
		// 	this->insert(n);
	}

	// std::list<int> lst = getData();
	// for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	// {
	//     std::cout << *it << std::endl;
	// }
}

void SortList::insert(int n) 
{
	for (std::list<int>::iterator it = this->getData().begin(); it != this->getData().end(); ++it)
	{
		if (*it > n)
		{
			this->getData().insert(it, n);
			break;
		}
	}
}

void SortList::merge(std::list<int> lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		this->_data.push_back(*it);
}

std::list<int> SortList::getData() const
{
	return (this->_data);
}

std::ostream& operator << (std::ostream &out, const SortList &obj)
{
	std::list<int> lst = obj.getData();

	out << "Sorted std::list<int>: ";
	for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		out << *it << " ";
	out << std::endl;
	return out;
}

// ----> VECTOR <---- //