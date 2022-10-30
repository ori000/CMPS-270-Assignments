#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstring>

using namespace::std;

template <class T>
class Stack
{
private:
	std::vector<T> stack;

public:
	bool empty()
	{
		if (stack.empty())
			return true;
		else
			return false;
	}
	void push(const T& item)
	{
		/*if (std::strcmp(typeid(item).name(), "bool"))
		{
			if (item == true)
				stack.push_back(1);
			else
				stack.push_back(0);
		}
		else*/
			stack.push_back(item);
	}
	T& top()
	{
		return stack.back();
	}
	void pop()
	{
		if(stack.size() > 0)
			stack.pop_back();
	}
	template<class T>
	friend Stack<T> operator + (Stack<T> &s1, Stack<T> &s2);
	//friend ostream& operator<<(ostream&, const Stack<T>&);

	/*
	template<class T>
	Stack<T> operator+ (Stack<T>& const s1, Stack<T>& const s2)
	{
		Stack<T> s3;
		s3.push(s1.pop() + s2.pop());
		return s3;
	}*/
};
	
	template<class T>
	Stack<T> operator + (Stack<T> &s1, Stack<T> &s2) 
	{
		Stack<T> s3;
		Stack<T> t1;
		Stack<T> t2;
		Stack<T> t3;
		/*
		while (!s1.empty() || !s2.empty()) 
		{
			s3.push(s1.top() + s2.top());
			t1.push(s1.top());
			t2.push(s2.top());
			s1.pop();
			s2.pop();
		}
		*/
		while (!s2.empty())
		{
			t3.push(s2.top());
			t2.push(s2.top());
			s2.pop();
		}
		while(!s1.empty())
		{
			t3.push(s1.top());
			t1.push(s1.top());
			s1.pop();
		}
		
		while (!t3.empty()) 
		{
			s3.push(t3.top());
			t3.pop();
		}
		
		while (!t1.empty()) 
		{
			s1.push(t1.top());
			t1.pop();
		}
		while (!t2.empty())
		{
			s2.push(t2.top());
			t2.pop();
		}
		return s3;
	}
/*
int main()
{
	Stack<int> stack1;
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);

	Stack<int> stack2;
	stack2.push(40);
	
	Stack<char> stack3;
	stack3.push('a');
	stack3.push('`');
	stack3.push('.');
	Stack<char> stack33;
	//stack33.push('3');
	//stack33.push('f');
	//stack33.push('-');
	
	Stack<string> stack4;
	stack4.push("one");
	stack4.push("two");
	stack4.push("three");

	Stack<string> stack44;
	stack44.push("one");
	stack44.push("two");
	stack44.push("three");

	
	Stack<bool> stack5;
	stack5.push(0);
	stack5.push(1);

	Stack<bool> stack55;
	stack55.push(0);
	stack55.push(1);
	
	/*
	while (!stack2.empty())
	{
		std::cout << stack2.top() << std::endl;
		stack2.pop();
	}
	std::cout << std::endl;
	while (!stack1.empty())
	{
		std::cout << stack1.top() << std::endl;
		stack1.pop();
	}
	std::cout << std::endl;
	
	//Stack<bool> stack6 = stack5 + stack55;
	Stack<bool> stack7 = stack5 + stack55;

	/*
	while (!stack6.empty())
	{
		std::cout << stack6.top() << std::endl;
		stack6.pop();
	}
	std:: cout << std::endl;
	while (!stack2.empty())
	{
		std::cout << stack2.top() << std::endl;
		stack2.pop();
	}
	std::cout << std::endl;
	while (!stack1.empty())
	{
		std::cout << stack1.top() << std::endl;
		stack1.pop();
	}
	*/
	/*
	while (!stack7.empty())
	{
		std::cout << stack7.top() << std::endl;
		stack7.pop();
	}
	std::cout << std::endl;
	while (!stack2.empty())
	{
		std::cout << stack2.top() << std::endl;
		stack2.pop();
	}
	std::cout << std::endl;
	while (!stack1.empty())
	{
		std::cout << stack1.top() << std::endl;
		stack1.pop();
	}

	return 0;*/
//}
/*
template <class T>
Stack<T> operator+(Stack<T>& s1, Stack<T>& s2)
{
	return Stack<T>();
}*/
