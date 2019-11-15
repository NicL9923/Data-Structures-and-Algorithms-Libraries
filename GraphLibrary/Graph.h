/*
-----Graph-----
A library/class about graphs and various methods
to manipulate/traverse/search them.

Notes:
-Need to create and pass own bool visited[]
-Functions are written to be used functionally, not object...ally

Created by Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>
#include "..//StackQueueLibrary/Queue.h"
#include "..//StackQueueLibrary/Stack.h"

#define numNodes 8

class Graph {
private:
	int graph[numNodes][numNodes];

public:
	Graph();
	~Graph();

	void createConnections();

	void recursiveDepthFirstTraversal(int G[][numNodes], int startNode, bool visited[]);
	void stackDepthFirstTraversal(int G[][numNodes], int startNode, bool visited[]);
	void breadthFirstTraversal(int G[][numNodes], int startNode, bool visited[]);
};

Graph::Graph() {
	graph[numNodes][numNodes];
}

Graph::~Graph() {
	delete[] graph;
}

//Connects all nodes in ascending order
void Graph::createConnections() {
	for (int i = 0; i < numNodes - 1; i++)
		graph[i][i + 1] = 1;
}

void Graph::recursiveDepthFirstTraversal(int G[][numNodes], int startNode, bool visited[]) {
	if (!visited[startNode]) {
		visited[startNode] = true;
		std::cout << startNode << std::endl;

		//Search for next neighbor to traverse (search goes in ascending value)
		for (int i = 0; i < numNodes; i++) {
			if (G[startNode][i] == 1 && !visited[i]) {
				recursiveDepthFirstTraversal(G, i, visited);
			}
		}
	}
}

void Graph::stackDepthFirstTraversal(int G[][numNodes], int startNode, bool visited[]) {
	Stack<int> s;
	
	visited[startNode] = true;
	std::cout << startNode << std::endl;
	s.push(startNode);

	while (!s.isEmpty()) {
		int k = s.top();
		bool flag = false;

		//Go to first lowest value neighbor and repeat
		for (int i = 0; i < numNodes; i++) {
			if (G[k][i] == 1 && !visited[i]) {
				visited[i] = true;
				std::cout << i << std::endl;
				flag = true;
				s.push(i);
				break;
			}
		}

		if (!flag) {
			s.pop();
		}
	}

}

void Graph::breadthFirstTraversal(int G[][numNodes], int startNode, bool visited[]) {
	Queue<int> q;
	visited[startNode] = true;

	std::cout << startNode << std::endl;

	q.push(startNode);

	while (!q.isEmpty()) {
		int k = q.front();

		//Work through all neighbors
		for (int i = 0; i < numNodes; i++) {
			if (G[k][i] == 1 && !visited[i]) {
				visited[i] = true;
				std::cout << i << std::endl;
				q.push(i);
			}
		}

		q.pop();
	}
}