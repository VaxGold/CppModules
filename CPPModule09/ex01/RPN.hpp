#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <stack>
# include <vector>
# include <cctype>

class RPN
{
	private:
		std::stack<int> _stck;
		std::string _err;

		void clearStck();

	public:
		RPN();
		RPN(char *data);
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		virtual ~RPN();

		int parser(char *data);

		int calculator(std::string data);
		int addition();
		int subtraction();
		int multiplication();
		int division();

		std::stack<int> getInfo() const;
		std::string getError() const;
};

std::ostream& operator << (std::ostream &out, const RPN &rpn);

#endif
