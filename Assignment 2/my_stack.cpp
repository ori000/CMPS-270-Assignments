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
};