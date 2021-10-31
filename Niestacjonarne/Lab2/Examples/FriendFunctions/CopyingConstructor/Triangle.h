#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class Triangle
{
private:
	Node nodes[3];
	string name;

public:
	Triangle(Node a, Node b, Node c, string name);

	void display();

	double distance(int firstPointIndex, int secondPointIndex);
};

void showTriangleData(Triangle triangle);

void showTriangleData(Triangle* triangle);

