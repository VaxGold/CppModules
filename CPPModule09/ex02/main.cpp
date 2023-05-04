#include "PmergeMe.hpp"

# include <iostream>
# include <cstdlib>
# include <string>
# include <ctime>
# include <cctype>
# include <cstring>
# include <chrono>

int main (int narg, char **xarg)
{
  int n = 0;
  for (int i = 1; i < narg; i++)
  {
    char *token = std::strtok(xarg[i], " ");
  	while (token != NULL)
  	{
  		int len = std::strlen(token);
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
  		token = std::strtok(NULL, " ");
  	}
    std::cout << "Number of elements: " << n << std::endl;
  }

  /* LIST */
  auto start =  std::chrono::high_resolution_clock::now();
  SortList lst(xarg);
  auto end =  std::chrono::high_resolution_clock::now();
  auto time_l = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  /* VECTOR */
  auto start =  std::chrono::high_resolution_clock::now();
  SortVector vect(xarg);
  auto end =  std::chrono::high_resolution_clock::now();
  auto time_v = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  /* DISPLAY */
  std::std::cout << "Before:";
  for (int i = 1; i < narg; i++)
  {
    char *token = std::strtok(xarg[i], " ");
  	while (token != NULL)
  	{
      std::std::cout << " " << token;
  		token = std::strtok(NULL, " ");
  	}
  }
  std::cout << std::endl;

  std::cout << "After:";
  // Serie ordenada
  std::cout << std::endl;

  std::cout << "Time to process a range of " << n << " elements with std::list : " << time_l.count() << " us" << std::endl;
  std::cout << "Time to process a range of " << n << " elements with std::vector : " << time_v.count() << " us" << std::endl;

  return (0);
}
