/*
#include <iostream>
#include <vector>

template <class T>
class Stack 
{
	std::vector<T> stack;

public:
	bool empty() 
	{
		if (stack.empty())
			return true;
		else 
			return false;
	}
	void push(const T &item) 
	{
		stack.push_back(item);
	}
	int top() 
	{
		return stack.back();
	}
	void pop() 
	{
		stack.pop_back();
	}
};

int main() 
{
	Stack<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push('A');

	
	while(!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}

	return 0;
}
*/