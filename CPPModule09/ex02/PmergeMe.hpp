#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <ctime>

# include <list>
# include <deque>

class SortList
{
	private:
		std::list<int> _data;
	public:
		SortList();
        SortList(char **data);
		SortList(std::list<int> lst);
		SortList(SortList const &other);
		SortList &operator=(SortList const &other);
		virtual ~SortList();

        void sortMI();
        void simpleSort();
        void insert(int n);
        void merge(SortList left, SortList right);

		std::list<int> getData() const;
};

class SortDeque
{
	private:
		std::deque<int> _data;
        double _time;
	public:
		SortDeque();
		SortDeque(SortDeque const &other);
		SortDeque &operator=(SortDeque const &other);
		virtual ~SortDeque();

        void sortMI();
        void simpleSort();
        void insert(int n);
        void merge(SortDeque left, SortDeque right);
};

class PmergeMe
{
	private:
		double _lstTime;
		double _dequeTime;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		virtual ~PmergeMe();
};

std::ostream& operator << (std::ostream &out, const PmergeMe &obj);

#endif