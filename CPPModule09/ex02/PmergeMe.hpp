#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <vector>
# include <list>
# include <deque>

class PmergeMe
{
	private:
		PMList _list;
		PMDeque _deque;
		int _nelements;
		std::vector _original;
		std::vector _sorted;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		virtual ~PmergeMe();
};

class SortCode
{
	private:
		double _dataTime;
		double _sortTime;
		std::string _name;
	public:
		SortCode();
		~SortCode();
};

class PMList
{
	private:
		double _dataTime;
		double _sortTime;
	public:
		PMList();
		PMList(PMList const &other);
		PMList &operator=(PMList const &other);
		virtual ~PMList();
};

class PMDeque
{
	private:
		double _dataTime;
		double _sortTime;
	public:
		PMDeque();
		PMDeque(PMDeque const &other);
		PMDeque &operator=(PMDeque const &other);
		virtual ~PMDeque();
}

std::ostream& operator << (std::ostream &out, const PmergeMe &obj);

#endif
