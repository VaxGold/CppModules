#include "PmergeMe.hpp"

long long getTimeUS()
{
	struct timeval chrono;
	gettimeofday(&chrono, NULL);
	return chrono.tv_sec * 1000000 + chrono.tv_usec;
}

int main (int narg, char **xarg)
{
	int n = 0;
	for (int i = 1; i < narg; i++)
	{
		std::istringstream tmp(xarg[i]);
		std::string token;
		while (tmp >> token)
		{
			int len = token.length();
			for (int j = 0; j < len; j++)
			{
				if (!std::isdigit(token[j]))
				{
					std::cout << "Error: invalid element." << std::endl;
					return (1);
				}
			}
			n++;
			if (n > 3000)
			{
				std::cout << "Error: too many elements." << std::endl;
				return (1);
			}
		}
	}

	/* LIST */
	long long start1 = getTimeUS();
	SortList lst(xarg);
	long long end1 = getTimeUS();
	long long time_l1 = end1 - start1;

	// std::clock_t start2 = std::clock();
	// SortList lst(xarg);
	// std::clock_t end2 = std::clock();
	// double time_l2 = (double)(end2 - start2) / (double)CLOCKS_PER_SEC * 1000000.0;

	// Checking duplicates.
	std::list<int> sorted = lst.getData();
	size_t osize = sorted.size();
	sorted.unique();
	if (osize != sorted.size())
	{
		std::cout << "Error: duplicated elements." << std::endl;
		return (1);
	}


	/* VECTOR */
	start1 = getTimeUS();
	SortVector vect(xarg);
	end1 = getTimeUS();
	long long time_v1 = end1 - start1;

	// start2 = std::clock();
	// SortVector vect(xarg);
	// end2 = std::clock();
	// double time_v2 = (double)(end2 - start2) / (double)CLOCKS_PER_SEC * 1000000.0;


	/* DISPLAY */
	std::cout << "Before:";
	for (int i = 1; i < narg; i++)
	{
		char *tmp = xarg[i];
		char *token = std::strtok(tmp, " ");
		while (token != NULL)
		{
			std::cout << " " << token;
			token = std::strtok(NULL, " ");
		}
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for(std::list<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// std::cout << lst << std::endl;
	// std::cout << vect << std::endl;

	std::cout << "Time to process a range of " << lst.getData().size() << " elements with std::list : " << time_l1 << " us" << std::endl;
	std::cout << "Time to process a range of " << vect.getData().size() << " elements with std::vector : " << time_v1 << " us" << std::endl;
	
	// std::cout << "Time to process a range of " << lst.getData().size() << " elements with std::list : " << time_l2 << " us" << std::endl;
	// std::cout << "Time to process a range of " << vect.getData().size() << " elements with std::vector : " << time_v2 << " us" << std::endl;

	return (0);
}
