#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
TEST CASES

TEST CASE 1: int Empty Graph
TEST CASE 2: int Graph with disconnected vertices (not a graph by theory)
TEST CASE 3: int Graph with vertices pointing to multiple vertices
TEST CASE 4: char or string Empty Graph
TEST CASE 5: char or string Graph with disconnected vertices (not a graph by theory)
TEST CASE 6: char or string Graph with vertices pointing to multiple vertices
TEST CASE 7: int Graph with no cycles
TEST CASE 8: char or string Graph with no cycles
TEST CASE 9: int Graph with cycles
TEST CASE 10: char or string Graph with cycles
*/


class Graph 
{
private:
	vector<int> start;
	vector<int> end;
public:
	Graph(const vector<int>& starts, const vector<int>& ends) 
	{
		start = starts;
		end = ends;
	}
	/*
	REQUIRES:

	EFFECTS:
	*/
	int numOutgoing(const int nodeID) 
	{
		//map<int, int> outgoing;
		vector<int> outgoing;
		for (int i = 0; i < start.size(); i++) 
		{
			if (start[i] == nodeID)
				outgoing.push_back(end[i]);
				//outgoing.insert(start[i], end[i]);
		}
		return outgoing.size();
	}
	/*
	REQUIRES:

	EFFECTS:
	*/
	const vector<int> adjacent(const int nodeID) 
	{
		vector<int> outgoing;
		for (int i = 0; i < start.size(); i++)
		{
			if (start[i] == nodeID)
				outgoing.push_back(end[i]);
		}
		return outgoing;
	}

};
/*
int main() 
{
	vector<int> s;
	vector<int> e;

	s.push_back(0);
	s.push_back(0);
	s.push_back(0);
	s.push_back(4);
	s.push_back(4);
	s.push_back(3);

	e.push_back(1);
	e.push_back(2);
	e.push_back(3);
	e.push_back(3);
	e.push_back(1);
	e.push_back(1);

	Graph graph(s, e);

	std::cout << graph.numOutgoing(2) << std::endl;
	//std::cout << graph.adjacent(0) << std::endl;

	return 0;
}*/