#include "PmergeMe.hpp"

// ----> LIST <---- //
SortList::SortList() { }

SortList::SortList(char **data)
{
    int i = 0;
    while (data[i] != 0)
    {
        this->_data.push_back(atoi(data[i]));
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
    this->sortMI();
}

SortList &SortList::operator=(SortList const &other)
{
    if (this != &other)
	{
		this->_data = other.getData();
	}
    this->sortMI();
	return (*this);
}

SortList::~SortList() { }

void SortList::sortMI() 
{
    std::list<int> aux;
    SortList right;
    int n = -1;

    if (this->getData().size() <= 3)
    {
        this->simpleSort();
    }
    else
    {
        size_t i = 0;
        std::list<int>::iterator it = this->getData().begin();
        while (i < (this->getData().size() / 2))
        {
            aux.push_back(*it);
            i++;
        }
        SortList left(aux);
        aux.clear();
        this->_data = left.getData();
        while (i < (this->getData().size() / 2) * 2)
        {
            aux.push_back(*it);
            i++;
        }
        if (it != this->getData().end())
            n = *it;
        SortList right(aux);
        aux.clear();
        this->merge(right.getData());
        this->simpleSort();
        if (n != -1)
            this->insert(n);
    }
}

void SortList::simpleSort() 
{
    this->getData().sort();
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

// ----> VECTOR <---- //