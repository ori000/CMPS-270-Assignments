#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

/*
TEST CASES

TEST CASE 1: Empty graph	=> checked (print invalid)
TEST CASE 2: int graph with adjacent nodes	=> checked (no errors if valid type): start = 0001 end = 2345
TEST CASE 3: int graph with zero adjacent nodes	=> checked (no errors if valid type): start = 0001 end = null
TEST CASE 4: graph with no cycles	=> checked (no errors if valid type): start = 00 end = 12
TEST CASE 5: graph with mutliple cycles	=> checked (no errors if valid type): start = 0012 end = 1200
TEST CASE 6: graph with cycles towards every vertex	=> checked (no errors if valid type): start = 01 end =10
TEST CASE 7: graph with grand-children (adjacent nodes have adjacent nodes)	=> checked (no errors if valid): start = 012 end = 12
TEST CASE 8: graph with no grand-children	=> checked (no errors if valid): start = 0 end = null
TEST CASE 9: graph with with only one node having one adjacent node having one child... 	=> checked (no errors if valid): start = 012 end = 12
TEST CASE 10:graph with already defined adjacent nodes => checked (if statement) ignore if already defined
TEST CASE 11:graph with new undefined adjacent nodes => checked (if statement) add nodes if undefined
*/

class Graph
{
private:
	vector<int> start;
	vector<int> end;
public:
	map<int, vector<int>> g;
	/*
	REQUIRES: nothing

	EFFECTS: assigns the start and end vectors to those in given input parameters
	*/
	Graph(const vector<int>& starts, const vector<int>& ends)
	{
		start = starts;
		end = ends;
	}
	/*
	REQUIRES: nodeID input of type int

	EFFECTS: returns the number of outgoing edges / direct vertices from the given node input 
	*/
	int numOutgoing(const int nodeID)
	{
		vector<int> outgoing;
		if (end.size() == start.size() && start.size() != 0 && std::find(start.begin(), start.end(), nodeID) != start.end())
		{
			for (int i = 0; i < end.size(); i++)
			{
				if (start[i] == nodeID && std::find(g[nodeID].begin(), g[nodeID].end(), end[i]) == g[nodeID].end())
				{
					outgoing.push_back(end[i]);
					g[nodeID].push_back(end[i]);
				}
			}
			/*
			for (int i = 0; i < start.size(); i++)
			{
				if (start[i] == nodeID)
					g.insert(nodeID, end[i]);

			}
			*/
			return g[nodeID].size();
		}
		else 
		{
			std::cout << "INVALID START / END VECTORS";
			return 0;
		}
	}
	/*
	REQUIRES: input nodeID of type int

	EFFECTS: returns a vector containing the adjacent nodes of the given node input (returned vector is the value of map g at key nodeID)
	*/
	const vector<int> adjacent(const int nodeID)
	{
		vector<int> outgoing;
		if (end.size() == start.size() && start.size() != 0 && std::find(start.begin(), start.end(), nodeID) != start.end())
		{
			for (int i = 0; i < end.size(); i++)
			{
				if (start[i] == nodeID && std::find(g[nodeID].begin(), g[nodeID].end(), end[i]) == g[nodeID].end())
				{
					outgoing.push_back(end[i]);
					g[nodeID].push_back(end[i]);
				}
			}
			return g[nodeID];
		}
		else 
		{
			std::cout << "INVALID START & END VECTORS";
			return g[nodeID];
		}
	}
	/*
	REQUIRES: non-empty int graph

	EFFECTS: return cycle in graph(if exists), return no cycles if there isnt any
	*/
	string hasCycles(Graph graph) 
	{
		vector<int> s = graph.start;
		vector<int> e = graph.end;
		// if (end.size() <= start.size() && start.size() != 0)
		// {
		// 	for (int i = 0; i < s.size(); i++)
		// 	{
		// 		for (int j = 0; j < e.size(); j++)
		// 		{
		// 			if (start[j] == end[i] && e[j] == s[i])
		// 				return true;
		// 		}
		// 	}
		// 	return false;
		// }
		// else 
		// {
		// 	std::cout << "INVALID START / END VECTOR SIZE";
		// 	return false;
		// }
		if (end.size() == start.size() && start.size() != 0)
		{
			string cycle = "Cycle: ";
			stack<string> stack;
			for (int i = 0; i < s.size(); i++)
			{
				for (int j = 0; j < e.size(); j++)
				{
					if (start[j] == end[i] && e[j] == s[i])
					{
						cycle += std::to_string(start[j]);
						cycle += ",";
						cycle += std::to_string(end[j]);
					}
						
				}
			}
			return cycle;
		}
		else 
		{
			std::cout << "INVALID START / END VECTOR SIZE";
			return "";
		}
	}
};

int main()
{
	vector<int> s;
	vector<int> e;
	vector<int> f;
	vector<int> ff;
	vector<int> c;
	vector<int> cc;
	vector<int> d;
	vector<int> dd;
	vector<int> b;
	vector<int> bb;

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

	c.push_back(0);
	cc.push_back(1);
	c.push_back(1);
	cc.push_back(2);

	d.push_back(6);

	bb.push_back(0);



	Graph graph(s, e);
	Graph graph2(f,ff);
	Graph graph3(c,cc);
	Graph graph4(d,dd);
	Graph graph5(b,bb);

	
	std::cout << graph.hasCycles(graph) << std::endl;
	std::cout << graph.numOutgoing(4) << std::endl;
	
	const vector<int> v = (graph.adjacent(0));
	const vector<int> v2 = (graph.adjacent(4));

	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	for (int i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	
	
	/*
	std::cout << graph2.hasCycles(graph2) << std::endl;
	std::cout << graph2.numOutgoing(0) << std::endl;

	const vector<int> v3 = (graph2.adjacent(0));
	const vector<int> v4 = (graph2.adjacent(4));

	for (int i = 0; i < v3.size(); i++)
		std::cout << v3[i] << std::endl;
	for (int i = 0; i < v4.size(); i++)
		std::cout << v4[i] << std::endl;

	std::cout << std::endl;

	std::cout << graph3.hasCycles(graph3) << std::endl;
	std::cout << graph3.numOutgoing(0) << std::endl;

	const vector<int> v5 = (graph3.adjacent(0));
	const vector<int> v6 = (graph3.adjacent(1));

	for (int i = 0; i < v5.size(); i++)
		std::cout << v5[i] << std::endl;
	for (int i = 0; i < v6.size(); i++)
		std::cout << v6[i] << std::endl;

	std::cout << std::endl;

	std::cout << graph4.hasCycles(graph4) << std::endl;
	std::cout << graph4.numOutgoing(6) << std::endl;

	const vector<int> v7 = (graph4.adjacent(6));
	const vector<int> v8 = (graph4.adjacent(4));

	for (int i = 0; i < v7.size(); i++)
		std::cout << v7[i] << std::endl;
	for (int i = 0; i < v8.size(); i++)
		std::cout << v8[i] << std::endl;

	std::cout << std::endl;

	std::cout << graph5.hasCycles(graph5) << std::endl;
	std::cout << graph5.numOutgoing(2) << std::endl;

	const vector<int> v9 = (graph5.adjacent(0));
	const vector<int> v10 = (graph5.adjacent(4));

	for (int i = 0; i < v9.size(); i++)
		std::cout << v9[i] << std::endl;
	for (int i = 0; i < v10.size(); i++)
		std::cout << v10[i] << std::endl;
		*/
	return 0;
}

