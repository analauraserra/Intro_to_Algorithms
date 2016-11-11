//============================================================================
// Name        : RandomizedContractionAlgorithm.cpp
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

#include "RCA.h"

using namespace std;

int main() {
	string myfile="/media/data/Courses/Algorithms/homework/kargerMinCut.txt";
    ifstream file;

    int N=200;
    int NMax=pow(N, 2)*log(N);
    cout<< "number of repetitions "<< NMax<<endl;
    int minCut=1500000;
    for (int nn=0; nn<NMax+1; ++nn){
    	if(nn%10==0) cout <<"repetition "<< nn<< " minimum cuts so far "<< minCut<< endl;
    file.open(myfile.c_str());
    std::vector<std::vector<int>> graph;

    string myLine;
    std::vector<int> fields;
    while (std::getline (file,myLine)){
 //  	cout<< myLine<< endl;
    RCA::divideLine(myLine, fields);
    graph.push_back(fields);
    }
    file.close();
/*
    cout<< "check first and last "<< endl;
    std::for_each(graph[0].begin(), graph[0].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    std::for_each(graph[graph.size()-1].begin(), graph[graph.size()-1].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
*/
    /*
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/

    RCA myMinCut(graph);
    int nCuts=myMinCut.getMinCut();
 //   cout<< "Cuts: "<< nCuts<<endl;
    if(nCuts< minCut) minCut=nCuts;
    }

    cout<< "Minimum number of Cuts: "<< minCut<<endl;

	return 0;
}
