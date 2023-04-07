#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(std::string str)
{
	std::vector<std::string> storage;
	std::string delimiter = " ";
	size_t pos = 0;
	
	while ((pos = str.find(delimiter)) != std::string::npos)
	{
		storage.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.length());
	}
	storage.push_back(str.substr(0, pos));
	if (this->parse(storage) == 0)
	{
		storage.clear();
		return ;
	}
	for (std::vector<std::string>::iterator it = storage.begin(); it != storage.end(); ++it)
	{
		if (*it == "+")
			this->addition();
		else if (*it == "-")
			this->subtraction();
		else if (*it == "*")
			this->multiplication();
		else if (*it == "/")
			this->division();
		else
			this->_stck.push(atoi((*it).c_str()));
	}
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
	}
	return (*this);
}

RPN::~RPN() { }

int RPN::parse(std::vector<std::string> storage)
{
	if (storage.size() > 10)
		return (0);
	for (std::vector<std::string>::iterator it = storage.begin(); it != storage.end(); ++it)
	{
		if ((*it).length() == 1)
		{
			if (!isdigit((*it)[0]) && (*it)[0] != '+' && (*it)[0] != '-' && (*it)[0] != '*' && (*it)[0] != '/')
				return (0);
		}
		else
		{
			for (size_t i = 0; i < (*it).length(); i++)
			{
				if (!isdigit((*it)[i]))
					return (0); 
			}	
		}
	}
	return (1);
}

void RPN::addition() 
{
	int first;
	int last;

	if (this->_stck.size() < 2)
		return ;
	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first + last);
}

void RPN::subtraction()
{
	int first;
	int last;

	if (this->_stck.size() < 2)
		return ;
	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first - last);
}

void RPN::multiplication()
{
	int first;
	int last;

	if (this->_stck.size() < 2)
		return ;
	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first * last);
}

void RPN::division()
{
	int first;
	int last;

	if (this->_stck.size() < 2)
		return ;
	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first / last);
}

std::stack<int> RPN::getInfo() const
{
	return (this->_stck);
}

std::ostream& operator << (std::ostream &out, const RPN &rpn)
{
	std::stack<int> aux = rpn.getInfo();
	
	if (aux.empty() == 1)
		std::cout << "Error" << std::endl;
	else
	{
		while (!aux.empty())
		{
			std::cout << aux.top() << std::endl;
			aux.pop();
		}
	}
	return (out);
}
