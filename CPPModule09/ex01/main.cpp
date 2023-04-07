#include "RPN.hpp"

int main(int narg, char **xarg)
{
	std::string str = "";

	if (narg != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	str += xarg[1];
	RPN operation(str);
	std::cout << operation;

	return (0);
}
