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
	public:
		RPN();
		RPN(std::string str);
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		virtual ~RPN();

		int parse(std::vector<std::string> storage);

		void addition();
		void subtraction();
		void multiplication();
		void division();

		std::stack<int> getInfo() const;
};

std::ostream& operator << (std::ostream &out, const RPN &rpn);

#endif
