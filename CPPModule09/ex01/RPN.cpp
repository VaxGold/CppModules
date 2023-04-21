#include "RPN.hpp"

RPN::RPN(): _err("") { }

RPN::RPN(char *data): _err("")
{
	// Checking correct syntaxis notation.
	if (this->parser(data))
	{
		//this->_err = "Error: invalid expresion.\n";
		this->clearStck();
		return ;
	}

	// Split and operate elements.
	std::string tmp;
	for (size_t pos = 0; data[pos] != 0; pos++)
	{
		while (data[pos] == ' ')
			pos++;
		if (data[pos] == 0)
			break;
		while (data[pos] != ' ')
		{
			tmp += data[pos];
			if (data[pos + 1] == 0)
				break;
			pos++;
		}
		if (this->calculator(tmp))
			return ;
		tmp.clear();
	}

	// Checking logic in syntaxis.
	if (this->_stck.size() > 1)
		this->_err = "Error: syntaxis, more than one element stored:\n";
}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		this->_stck = other.getInfo();
		this->_err = other.getError();
	}
	return (*this);
}

RPN::~RPN() { }

int RPN::parser(char *data)
{
	char *token = std::strtok(data, " ");
	int n = 0;
	int err;

	while (token != NULL)
	{
		err = this->validate(token);
		if (err == 0)
		token = std::strtok(NULL, " ");
	}


	return (0);
}

int RPN::calculator(std::string data)
{
	int err = 0;

	// Choose operation.
	if (data == "+")
		err = this->addition();
	else if (data == "-")
		err = this->subtraction();
	else if (data == "*")
		err = this->multiplication();
	else if (data == "/")
		err = this->division();
	else
	{
		int n = atoi(data.c_str());
		if (n > 9 || n < -9)
		{
			this->_err = "Error: number out of range.\n";
			this->clearStck();
			return (1);
		}
			this->_stck.push(atoi(data.c_str()));
	}

	// Manage operator errors.
	if (err != 0)
	{
		this->_err = "Error: operator " + data + ", not enough elements to operate.\n";
		this->clearStck();
		return (1);
	}

	return (0);
}

int RPN::addition()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first + last);
	return (0);
}

int RPN::subtraction()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first - last);
	return (0);
}

int RPN::multiplication()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first * last);
	return (0);
}

int RPN::division()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first / last);
	return (0);
}

std::stack<int> RPN::getInfo() const
{
	return (this->_stck);
}

std::string RPN::getError() const
{
	return (this->_err);
}

void RPN::clearStck()
{
	while (!this->_stck.empty())
		this->_stck.pop();
	return ;
}

std::ostream& operator << (std::ostream &out, const RPN &rpn)
{
	std::stack<int> aux = rpn.getInfo();

	out << rpn.getError();
	if (!aux.empty())
	{
		while (!aux.empty())
		{
			out << aux.top() << std::endl;
			aux.pop();
		}
	}
	return (out);
}
