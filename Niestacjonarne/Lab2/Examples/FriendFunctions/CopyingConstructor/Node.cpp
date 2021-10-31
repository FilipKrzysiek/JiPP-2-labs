#include "Node.h"

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y) : x(x), y(y) {}

Node::Node(Node& node)
{
    x = node.x;
    y = node.y;
    size = node.size;

    array = new double[size];

    for (size_t i = 0; i < size; ++i) {
        array[i] = node.array[i];
    }
}

Node::~Node()
{
    if(size > 0)
        delete[] array;
}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

void Node::addNewValue(double n)
{
    if (size == 0) {
        array = new double[1];
        array[0] = n;
        size = 1;
    }
    else {
        ++size;
        double* temp = new double[size];

        for (size_t i = 0; i < size - 1; ++i)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        array[size - 1] = n;
    }
}

void Node::printValues()
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}

void Node::changeValueOn(double newValue, int indx)
{
    if (indx < size) {
        array[indx] = newValue;
    }
}

double pointDistance(Node a, Node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
