#include "AdjListGraph.h"

AdjListGraph::AdjListGraph( )
{
	numOfVertices = 0;
	maxVertices = MAX_LIST_VERTICES;

	vertices = new string[maxVertices];
	list = new AnyList*[maxVertices];
}

AdjListGraph::AdjListGraph(int totalVertices)
{
	numOfVertices = totalVertices;
	maxVertices = totalVertices * 2;

	vertices = new string[maxVertices];
	list = new AnyList*[maxVertices];
}

void AdjListGraph::createAdjListGraph
			(const vector<vector<string>>& graphData)
{
	numOfVertices = static_cast<int>(graphData.size());

	for (int i = 0; i < numOfVertices; ++i)
	{	
		int adjVertices = static_cast<int>(graphData[i].size()) - 1;
		vertices[i] = graphData[i].at(0);

		list[i] = new AnyList;

		for (int j = 1; j <= adjVertices; ++j)
			list[i]->insertFront(graphData[i].at(j));	
	}
}

// printVertices
// Assume the list has at least one vertex.
void AdjListGraph::printVertices() const
{
	cout << "Vertices: ";
	for (int i = 0; i < numOfVertices; ++i)
		cout << vertices[i] << " ";
}

// printAllSuccessors
// Assume the list has at least one vertex.
void AdjListGraph::printAllSuccessors() const
{
	for (int i = 0; i < numOfVertices; ++i)
	{
		cout << "- " << vertices[i] << ": ";
		if (list[i]->getCount() == 0)
			cout << "No successors";
		else
			cout << *list[i];
		cout << endl;
	}
}