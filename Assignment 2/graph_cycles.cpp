#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph
{
private:
	vector<int> start;
	vector<int> end;
public:
	map<int, vector<int>> g;
	Graph(const vector<int>& starts, const vector<int>& ends)
	{
		start = starts;
		end = ends;
	}
	/*
	REQUIRES: nothing

	EFFECTS: returns the number of outgoing edges / direct vertices from the given node input 
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
		for (int i = 0; i < start.size(); i++) 
		{
			if (start[i] == nodeID)
				g.insert(nodeID, end[i]);
			
		}
		return outgoing.size();
	}
	/*
	REQUIRES: nothing

	EFFECTS: returns a vector containing the adjacent nodes of the given node input
	*/
	const vector<int>& adjacent(const int nodeID)
	{
		vector<int> outgoing;
		for (int i = 0; i < start.size(); i++)
		{
			if (start[i] == nodeID) 
			{
				outgoing.push_back(end[i]);
			}
		}
		return outgoing;
	}
	/*
	REQUIRES: non-empty int graph

	EFFECTS: return true if graph contains at least one cycle, false if not
	*/
	bool hasCycles(Graph graph) 
	{
		vector<int> s = graph.start;
		vector<int> e = graph.end;

		for (int i = 0; i < s.size(); i++) 
		{
			for (int j = 0; j < e.size(); j++) 
			{
				if (start[j] == end[i] && e[j] == s[i])
					return true;
			}
		}
		return false;
	}
};

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
	s.push_back(1);

	e.push_back(1);
	e.push_back(2);
	e.push_back(3);
	e.push_back(3);
	e.push_back(1);
	e.push_back(1);
	e.push_back(0);

	Graph graph(s, e);

	//std::cout << graph.numOutgoing(2) << std::endl;
	//std::cout << graph.adjacent(0) << std::endl;
	const vector<int> v = graph.adjacent(0);
	map<int, vector<int>> m = graph.g;
	cout << m.begin()->first;
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	//std::cout << graph.hasCycles(graph) << std::endl;

	return 0;
}
