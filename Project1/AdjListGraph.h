#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H

#include "AnyList.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_LIST_VERTICES = 20; 

class AdjListGraph
{
public:
	AdjListGraph( );
	AdjListGraph(int totalVertices);

	void createAdjListGraph(const vector<vector<string>>& graphData);

	void printVertices() const;
	void printAllSuccessors() const;
	
	// The Big 5

	// Function destroyGraph


protected:

	string *vertices;		//will point to an array storing labels for vertices
	AnyList **list;			//will point to an array of objects of type AnyList (successors)
    int maxVertices;		//max number of vertices the graph can hold (capacity)
    int numOfVertices;		//total number of vertices
};

#endif