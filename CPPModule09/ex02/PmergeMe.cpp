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
	size_t size = this->getData().size();
	size_t mid_cap = size / 2;
	size_t high_cap = size / 2 * 2;

	if (size <= 3)
		this->_data.sort();
	else
	{
		size_t i = 0;
		for(std::list<int>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
		{
			if (i <= mid_cap)
				left.push_back(*it);
			else if (i > mid_cap && i <= high_cap)
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
	}
}

void SortList::insert(int n)
{
	for (std::list<int>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
	{
		if (*it > n)
		{
			this->_data.insert(it, n);
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
	return out;
}

// ----> VECTOR <---- //

SortVector::SortVector() { }

SortVector::SortVector(char **data)
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

SortVector::SortVector(std::vector<int> vect): _data(vect)
{
	this->sortMI();
}

SortVector::SortVector(SortVector const &other)
{
	*this = other;
}

SortVector &SortVector::operator=(SortVector const &other)
{
	if (this != &other)
	{
		this->_data = other.getData();
	}
	return (*this);
}

SortVector::~SortVector() { }

void SortVector::sortMI()
{
	std::vector<int> left;
	std::vector<int> right;
	int n = -1;
	size_t size = this->getData().size();

	if (size <= 3)
		std::sort(this->_data.begin(), this->_data.end());
	else
	{
		size_t i = 0;
		for(std::vector<int>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
		{
			if (i <= size / 2)
				left.push_back(*it);
			else if (i > size / 2 && i <= size / 2 * 2)
				right.push_back(*it);
			else
				n = *it;
			i++;
		}
		SortVector vect_l(left);
		this->_data = vect_l.getData();
		SortVector vect_r(right);
		this->merge(vect_r.getData());
		std::sort(this->_data.begin(), this->_data.end());
		if (n != -1)
			this->insert(n);
	}
}

void SortVector::insert(int n)
{
	for (std::vector<int>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
	{
		if (*it > n)
		{
			this->_data.insert(it, n);
			break;
		}
	}
}

void SortVector::merge(std::vector<int> lst)
{
	for (std::vector<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		this->_data.push_back(*it);
}

std::vector<int> SortVector::getData() const
{
	return (this->_data);
}

std::ostream& operator << (std::ostream &out, const SortVector &obj)
{
	std::vector<int> vect = obj.getData();

	out << "Sorted std::vector<int>: ";
	for(std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
		out << *it << " ";
	return out;
}
