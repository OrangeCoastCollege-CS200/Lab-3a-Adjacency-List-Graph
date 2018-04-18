#include "AdjListGraph.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{	
	vector<vector<string>> graphData1 = {
		{ "A", "F", "B" },
		{ "B", "F", "D", "C" },
		{ "C", "E" },
		{ "D" },
		{ "E", "F", "D" },
		{ "F", "D" },
	};

	vector<vector<string>> graphData2 = {
			{ "AA", "BB" },
			{ "BB", "DD", "CC" },
			{ "CC" },
			{ "DD", "AA" },
			{ "EE", "AA" },
	};

	{
		cout << "TEST copy constructor...\n";
		cout << "\n=> GRAPH 1...\n";
		AdjListGraph graph1(static_cast<int>(graphData1.size()));
		graph1.createAdjListGraph(graphData1);
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();

		AdjListGraph graph2(graph1);
		cout << "\nDestroy graph 1...";
		cout << "\n=> GRAPH 2...\n";
		graph1.~AdjListGraph();
		graph2.printVertices();
		cout << "\nSuccessors...\n";
		graph2.printAllSuccessors();
	}

	cout << "\n==================================================\n";

	{
		cout << "TEST overloaded assignment operator...\n";
		cout << "\n=> GRAPH 1...\n";
		AdjListGraph graph1(static_cast<int>(graphData1.size()));
		graph1.createAdjListGraph(graphData1);
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();

		AdjListGraph graph2(static_cast<int>(graphData2.size()));
		graph2.createAdjListGraph(graphData2);
		graph2 = graph1;
		cout << "\nDestroy graph 1...";
		cout << "\n=> GRAPH 2...\n";
		graph1.~AdjListGraph();
		graph2.printVertices();
		cout << "\nSuccessors...\n";
		graph2.printAllSuccessors();
	}

	cout << "\n==================================================\n";
	
	{
		cout << "TEST destroyGraph...\n";
		cout << "\n=> GRAPH 1...\n";
		AdjListGraph graph1(static_cast<int>(graphData1.size()));
		graph1.createAdjListGraph(graphData1);
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();
	
		cout << "\nDestroy graph 1...\n";
		graph1.destroyGraph();
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();
	}

	cout << "\n==================================================\n";

	{
		cout << "TEST move constructor...\n";
		cout << "\n=> GRAPH 1...\n";
		AdjListGraph graph1(static_cast<int>(graphData1.size()));
		graph1.createAdjListGraph(graphData1);
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();

		cout << "\nCall move constructor...";
		cout << "\n=> GRAPH 2...\n";
		AdjListGraph graph2 = move(graph1);
		graph2.printVertices();
		cout << "\nSuccessors...\n";
		graph2.printAllSuccessors();

		cout << "\nGraph 1 should be empty...";
		cout << "\n=> GRAPH 1...\n";
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();
	}

	cout << "\n==================================================\n";

	{
		cout << "TEST move assignment operator...\n";
		cout << "\n=> GRAPH 1...\n";
		AdjListGraph graph1(static_cast<int>(graphData1.size()));
		graph1.createAdjListGraph(graphData1);
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();

		AdjListGraph graph2(static_cast<int>(graphData2.size()));
		graph2.createAdjListGraph(graphData2);
		cout << "\n=> GRAPH 2...\n";
		graph2.printVertices();
		cout << "\nSuccessors...\n";
		graph2.printAllSuccessors();

		cout << "\nCall move assignment operator...";
		cout << "\n=> GRAPH 2...\n";
		graph2 = move(graph1);
		graph2.printVertices();
		cout << "\nSuccessors...\n";
		graph2.printAllSuccessors();

		cout << "\nGraph 1 should be empty...";
		cout << "\n=> GRAPH 1...\n";
		graph1.printVertices();
		cout << "\nSuccessors...\n";
		graph1.printAllSuccessors();
	}

	cout << "\n==================================================\n";
	
	cout << endl;
	system("Pause");
    return 0;
}

