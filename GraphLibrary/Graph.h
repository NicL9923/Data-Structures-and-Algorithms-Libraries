/*
-----Graph-----
A library/class about graphs and various methods
to manipulate/traverse/search them.

Notes:
-

Created by Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>

class Graph {
private:
	int numNodes;
	int graph[numNodes][numNodes];

public:
	Graph(int numbNodes);
	~Graph();
};

Graph::Graph(int numbNodes) {
	numNodes = numbNodes;
	graph[numNodes][numNodes] = { 0 };
}

Graph::~Graph() {
	delete[] graph;
}