


//NOTE: ON LINE 82, ON VS CODE IT GIVES AN ERROR IF WE PUT THE TEMPLATE AGAIN(shadow error), HOWEVER, IT WORKS FINE ON THE REGULAR VISUAL STUDIO. I COMMENTED IT ON VS CODE JUST IN CASE

#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstring>

/*
TEST CASES

TEST CASE 1: Empty stack	=> checked (no errors if valid type) : Stack<int>, Stack<char>, etc.
TEST CASE 2: pop, top, push, and check if empty for a filled stack of integers	=> checked (no errors if valid): Stack<int> pushing to it 4,2,1,2,3
TEST CASE 3: pop, top, push, and check if empty for a filled stack of doubles	=> checked (no errors if valid): Stack<double> pushing to it 4.2,2,1,2.5,3.8
TEST CASE 4: pop, top, push, and check if empty for a filled stack of strings	=> checked (no errors if valid): Stack<string> pushing to it "string1", "two"
TEST CASE 5: pop, top, push, and check if empty for a filled stack of chars		=> checked (no errors if valid): Stack<char> pushing to it 'c', 'b'
TEST CASE 6: pop, top, push, and check if empty for a stack of bools => TEST FAILS BY CPP CONVENTION
TEST CASE 7: add two int/double stacks of same size			=> checked (no errors if valid): c = a + b  where a == b
TEST CASE 8: add two int/double stacks of different size	=> checked (no errors if valid): c = a + b  where a != b
TEST CASE 9: add two string stacks of same 	size			=> checked (no errors if valid): c = a + b  where a == b
TEST CASE 10: add two string stacks of different size		=> checked (no errors if valid): c = a + b  where a != b
TEST CASE 11: add two char stacks of same size				=> checked (no errors if valid): c = a + b  where a == b
TEST CASE 12: add two char stacks of different size			=> checked (no errors if valid): c = a + b  where a != b
TEST CASE 13: add two bool stacks of same size => TEST FAILS BY CPP CONVENTION
TEST CASE 14: add two bool stacks of different size => TEST FAILS BY CPP CONVENTION
*/

using namespace::std;

template <class T>
class Stack
{
private:
	std::vector<T> stack;

public:
	/*
	Requires: nothing

	Effects: returns true if empty, false if not
	*/
	bool empty()
	{
		if (stack.empty())
			return true;
		else
			return false;
	}
	/*
	Requires: nothing

	Effects: add an element/item input into the last index of the vector
	*/
	void push(const T& item)
	{
			stack.push_back(item);
	}
	/*
	Requires: nothing

	Effects: returns the last element of the stack (vector in this case)
	*/
	T& top()
	{
			return stack.back();
	}
	/*
	Requires: nothing

	Effects: removes the last element of the stack (vector in this case), or prints invalid if empty
	*/
	void pop()
	{
		
		if(stack.size() > 0)
			stack.pop_back();
		else 
			std::cout << "Invalid stack size";
	}
	//template<class T>
	friend Stack<T> operator + (Stack<T>& s1, Stack<T>& s2);
};
	/*
	Requires: neither of s1 or s2 is of type bool

	Effects: returns a new stack containing the elements of both s1 and s2 chronologically
	*/
	template<class T>
	Stack<T> operator + (Stack<T> &s1, Stack<T> &s2) 
	{
		//if (!(std::strcmp(typeid(s1).name(), "class Stack<bool>")) || !(std::strcmp(typeid(s2).name(), "class Stack<bool>")))
		//{
			Stack<T> s3;
			Stack<T> t1;
			Stack<T> t2;
			Stack<T> t3;
			/*//in case you wanted the implementation to add the values together at the same indices
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
			while (!s1.empty())
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
		//}
	}
	
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
	stack33.push('3');
	stack33.push('f');
	stack33.push('-');
	
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
	Stack<string> stack6 = stack4 + stack44;
	
	while (!stack6.empty())
	{
		std::cout << stack6.top() << std::endl;
		stack6.pop();
	}
	*/
	/*
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

	return 0;
}


