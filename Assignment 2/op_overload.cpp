#include <iostream>
#include <vector>

using namespace std;

/*
TEST CASES

TEST CASE 1: Empty stack
TEST CASE 2: pop, top, push, and check if empty for Partially filled stack of integers
TEST CASE 3: pop, top, push, and check if empty for Partially filled stack of doubles
TEST CASE 4: pop, top, push, and check if empty for Partially filled stack of strings
TEST CASE 5: pop, top, push, and check if empty for Partially filled stack of integers, doubles, strings, chars...
TEST CASE 6: pop, top, push, and check if empty for Fully filled stack of integers
TEST CASE 7: pop, top, push, and check if empty for Fully filled stack of doubles
TEST CASE 8: pop, top, push, and check if empty for Fully filled stack of strings
TEST CASE 9: pop, top, push, and check if empty for Fully filled stack of integers, doubles, strings, chars...
TEST CASE 10:input elements of various types
TEST CASE 11:input one stack 1 as empty and stack 2 as not 
TEST CASE 12:input one stack 2 as empty and stack 1 as not 
*/

template <class T>
class Stack
{
    public:
    vect<T> stack;
    /*
    Requires: nothing

    Effects: returns true if empty, false if not
    */
    bool Stack::empty()
    {
        for(int i = 0; i < stack.size(); i++)
            if(stack[i] != NULL)
            {
                return false;
            }
        return true;
    }
    /*
    Requires: nothing
    
    Effects: add an element into the last index of the vector
    */
    void Stack::push(const T&item)
    {
        stack.push_back(item);
    }
    /*
    Requires: nothing
    
    Effects: returns the last element of the stack (vector in this case), or prints invalid if empty
    */
    T &Stack::top()
    {
        if(stack.size() != 0)
        {
            for(int i = 0; i < stack.size(); i++)
                if(i == stack.size()-1)
                    return stack[i];
        }
        else return "Empty stack."
    }
    /*
    Requires: nothing
    
    Effects: removes the last element of the stack (vector in this case), or prints invalid if empty
    */
    void Stack::pop()
    {
        if(stack.size() != 0)
        {
            for(int i = 0; i < stack.size(); i++)
                if(i == stack.size()-1)
                    stack.erase(stack[i]);
        }
        else return "Empty stack."
    }

    friend Stack<T> operator+(Stack<T>&, Stack<T>&);
};

/*
Requires: nothing

Effects: returns a new stack containing the elements of the two given stacks as parameters SUCCESSIVELY (elements of stack 1 followed by those of stack 2)
*/
template <class T>
Stack<T> operator+(Stack<T>& stack1, Stack<T>& stack2) // Call by reference
{
    // Create an object to return
    Stack<T> stack3;
 
    // Perform addition of feet and inches
    for(int i = 0 ;i< stack1.size(); i++)
        stack3[i] = stack1[i];
    for(int i = stack1.size()-1 ;i< stack2.size(); i++)
        stack3[i] = stack2[i];
 
    // Return the resulting object
    return stack3;
}