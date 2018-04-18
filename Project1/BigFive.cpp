/*
	Badajoz, Severiano

	CS A200
	April 18, 2018

	Lab 3a
*/

#include "AdjListGraph.h"

// copy constructor
AdjListGraph::AdjListGraph(const AdjListGraph& other) {
	numOfVertices = other.numOfVertices;
	maxVertices = other.maxVertices;

	vertices = new string[maxVertices]();
	list = new AnyList*[maxVertices]();

	for (int i = 0; i < numOfVertices; i++) {
		vertices[i] = other.vertices[i];
		list[i] = new AnyList();
		*list[i] = *(other.list[i]);
	}
}

// move constructor
AdjListGraph::AdjListGraph(AdjListGraph&& other) {
	numOfVertices = other.numOfVertices;
	maxVertices = other.maxVertices;
	vertices = other.vertices;
	list = other.list;

	other.numOfVertices = 0;
	other.maxVertices = 0;
	other.vertices = nullptr;
	other.list = nullptr;
}

// overloaded assignment operator (short version)
AdjListGraph& AdjListGraph::operator=(const AdjListGraph& other) {
	if (&other != this) {
		if (maxVertices != other.maxVertices) {
			maxVertices = other.maxVertices;
			delete[] vertices;
			vertices = new string[maxVertices]();
		}

		for (int i = 0; i < numOfVertices; i++) {
			delete list[i];
			list[i] = nullptr;
		}
		delete[] list;
		list = new AnyList*[maxVertices]();

		numOfVertices = other.numOfVertices;
		for (int i = 0; i < numOfVertices; i++) {
			vertices[i] = other.vertices[i];
			list[i] = new AnyList();
			*list[i] = *(other.list[i]);
		}
	}
	else cerr << "Incorrect assignment to self";

	return *this;
}

// move assignment operator
AdjListGraph& AdjListGraph::operator=(AdjListGraph&& other) {
	if (&other != this) {
		delete[] vertices;

		for (int i = 0; i < numOfVertices; ++i) {
			delete list[i];
			list[i] = nullptr;
		}

		delete[] list;

		numOfVertices = other.numOfVertices;
		vertices = other.vertices;
		list = other.list;

		other.numOfVertices = 0;
		other.maxVertices = 0;
		other.vertices = nullptr;
		other.list = nullptr;

	}
	else cerr << "Incorrect assignment to self";

	return *this;
}

// destructor
AdjListGraph::~AdjListGraph() {
	maxVertices = 0;
	delete[] vertices;
	vertices = nullptr;
	for (int i = 0; i < numOfVertices; i++) {
		delete list[i];
		list[i] = nullptr;
	}

	delete[] list;
	list = nullptr;
	numOfVertices = 0;
}

// destroyGraph
void AdjListGraph::destroyGraph() {
	for (int i = 0; i < numOfVertices; ++i)
	{
		vertices[i] = "";
		delete list [i];
		list[i] = nullptr;
	}

	numOfVertices = 0;
}


