#include "Triangle.h"

Triangle::Triangle(Node a, Node b, Node c, string name): name(name)
{
	nodes[0] = a;
	nodes[1] = b;
	nodes[2] = c;
}

void Triangle::display()
{
	cout << name << endl;
	nodes[0].display();
	nodes[1].display();
	nodes[2].display();
}

double Triangle::distance(int firstPointIndex, int secondPointIndex)
{
	if (firstPointIndex >= 0 && secondPointIndex >= 0 && firstPointIndex < 3 && secondPointIndex < 3) {
		return pointDistance(nodes[firstPointIndex], nodes[secondPointIndex]);
	}
	return 0.0;
}

void showTriangleData(Triangle triangle)
{
	triangle.display();
}

void showTriangleData(Triangle* triangle)
{
	triangle->display();
}
