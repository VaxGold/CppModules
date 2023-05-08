#include "PmergeMe.hpp"

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
  std::clock_t start = std::clock();
  SortList lst(xarg);
  std::clock_t end = std::clock();
  double time_l = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000000.0;
  std::cout << lst << std::endl;

  /* VECTOR */
  start = std::clock();
  //SortVector vect(xarg);
  end = std::clock();
  double time_v = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000000.0;

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

  std::cout << "After:";
  // Serie ordenada
  std::cout << std::endl;

  std::cout << "Time to process a range of " << lst.getData().size() << " elements with std::list : " << time_l << " us" << std::endl;
  std::cout << "Time to process a range of " << n << " elements with std::vector : " << time_v << " us" << std::endl;

  return (0);
}
