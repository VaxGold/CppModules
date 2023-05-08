#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <cctype>
# include <cstring>
# include <ctime>
# include <sstream>

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
        void insert(int n);
        void merge(std::list<int> lst);

		std::list<int> getData() const;
};

class SortVector
{
	private:
		std::vector<int> _data;
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

// class PmergeMe
// {
// 	private:
// 		double _lstTime;
// 		double _dequeTime;
// 	public:
// 		PmergeMe();
// 		PmergeMe(PmergeMe const &other);
// 		PmergeMe &operator=(PmergeMe const &other);
// 		virtual ~PmergeMe();
// };

std::ostream& operator << (std::ostream &out, const SortList &obj);
std::ostream& operator << (std::ostream &out, const SortVector &obj);

#endif
