#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <ctime>

# include <list>
# include <vector>

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
        void merge(std::list<int> lst);

		std::list<int> getData() const;
};

class SortVector
{
	private:
		std::vector<int> _data;
        double _time;
	public:
		SortVector();
		SortVector(SortVector const &other);
		SortVector &operator=(SortVector const &other);
		virtual ~SortVector();

        void sortMI();
        void simpleSort();
        void insert(int n);
        void merge(std::vector<int> lst);
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