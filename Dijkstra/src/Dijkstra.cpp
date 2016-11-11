//============================================================================
// Name        : Dijkstra.cpp
// Author      : ALS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "ShorstestPath.h" //misspelled!

using namespace std;

int main() {
	string myfile="/media/data/Courses/Algorithms/homework/dijkstraData.txt";
    ifstream file;

    file.open(myfile.c_str());

    string myLine;

    std::vector<std::vector<std::pair<int,int>>> all_edges;
    std::vector<int> vertices;

    int vertex;
    std::vector<std::pair<int,int>> edges;

    while (std::getline (file,myLine)){
    ShorstestPath::divideLine(myLine, vertex, edges);
    vertices.push_back(vertex);
    all_edges.push_back(edges);

    }
    file.close();
    int s, p;
    s=1;
    p=197; 
    ShorstestPath myPath1(s, p, vertices, all_edges);

	return 0;
}


