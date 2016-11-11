//============================================================================
// Name        : SCC.cpp
// Author      : ALS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "DFSLoop.h"

using namespace std;

template<typename T> vector<T> sort_indexes(const vector<T> &v) {
  cout<<"Sorting vector of "<<v.size()<<" components\n";
  // initialize original index locations
  vector<unsigned long int> idx(v.size());
  for (unsigned int i = 0; i != idx.size(); ++i) idx[i] = i;
  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),[&v](int i1, int i2) {return v[i1] > v[i2];});
  return idx;
 };

int main() {
	string myfile="/media/data/Courses/Algorithms/homework/SCC.txt";
	ifstream file;
    file.open(myfile.c_str());

	unsigned long int head, tail, n_nodes;
//	n_nodes=9;
	n_nodes=875714;
	std::vector <std::vector <unsigned long int>> graph;
	graph.resize(n_nodes+1);
	std::vector<bool> is_created;
	is_created.resize(n_nodes+1);
	fill(is_created.begin(),is_created.end(),false);

	//read G as reversed(tail before head)
	while (file >> head >> tail){ //G inversed
//		cout << head <<  " " << tail<<endl;

		if (!is_created[tail]){
			graph[tail].push_back(tail);
			graph[tail].push_back(head);
			is_created[tail]=true;
		}else{
			graph[tail].push_back(head);
		}
	}
	   //fill gaps: nodes never created
    for (int i=1; i< (int) n_nodes+1; ++i){
    	if (!is_created[i]){
			graph[i].push_back(i);
    	}
    }

	file.close();
/*
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
    vector<unsigned long int> natural_order;
    for (int i=0; i< n_nodes+1; ++i){
    	natural_order.push_back(i);
    }
    cout <<"First pass "<<endl;
    //run first pass on G^rev
    DFS_Loop loopRevGraph(graph, n_nodes, natural_order);

    //get finishing time
    vector<unsigned long int> ft=loopRevGraph.getFt();

    cout <<"Re-read G "<<endl;
    //read G (not G^rev)
    file.open(myfile.c_str());
    graph.clear();
	graph.resize(n_nodes+1);
	fill(is_created.begin(),is_created.end(),false);


	while (file >> tail >> head){ //G
//		cout << head <<  " " << tail<<endl;

		if (!is_created[tail]){
			graph[tail].push_back(tail);
			graph[tail].push_back(head);
			is_created[tail]=true;
		}else{
			graph[tail].push_back(head);
		}
	}
	   //fill gaps: nodes never created
    for (int i=1; i< n_nodes+1; ++i){
 	 if (!is_created[i]){
			graph[i].push_back(i);
 	 }
    }
	file.close();
/*
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
    //swap nodes and ft
    vector<unsigned long int> order;
    order.resize(n_nodes+1);
    for (int gg=1; gg< (int)graph.size(); ++gg){
        for (int jj=0; jj< (int)graph[gg].size(); ++jj){
        	graph[gg][jj]=ft[graph[gg][jj]];
        }
    	order[ft[graph[gg][0]]]=gg;
    }
/*
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
    //second pass on G
    DFS_Loop loopGraph(graph, n_nodes, order);

    vector<unsigned long int> leaders= loopGraph.getLeader();
    vector<unsigned long int> counts= loopGraph.getCounts();

    cout << "sizes of SCCs: "<<endl;
    cout<< "number of SCCs: "<< leaders.size()<<endl;

    //sort in decreasing order
	vector <unsigned long int> idx=sort_indexes(counts);

    cout<< "number of nodes in first SCCs: "<<endl;

	for (int ii=0; ii<10; ++ii){
		cout<< counts[idx[ii]]<< " " << leaders[idx[ii]]<< endl;
	}
/*
    std::for_each(leaders.begin(), leaders.end(),[](int a){cout<< a<<" "; });
    cout<<endl;
	std::for_each(counts.begin(), counts.end(),[](int a){cout<< a<<" "; });
    cout<<endl;
*/
	return 0;
}


