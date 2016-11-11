/*
 * RCA.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: als
 */

#include "RCA.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

int RCA::nMinCut = 0;

RCA::RCA(vector<vector<int>>& graph) {
   //the indexes [0][*] of graph are the nodes
   //pick a node randomly

	if (graph.size()<3){
	//	cout<< "finished!!!"<<endl;
		nMinCut=graph[0].size()-1;
	}else{
	//NOTE: eclipse doesn't recognize it, but it works (the compiler does)
    std::random_device rd_i;
    std::mt19937 generator_i(rd_i());
    std::uniform_int_distribution<> distribution_i(0, graph.size()-1);
    int i= distribution_i(generator_i);

    //pick randomly l'adjacent node to contract
    std::random_device rd_j;
    std::mt19937 generator_j(rd_j());
    std::uniform_int_distribution<> distribution_j(1, graph[i].size()-1);
    //from one because we want to avoid the node
    int j= distribution_j(generator_j);

//    cout<< "node and adjacent node indexes "<< i  <<" "<< j<<endl;
//    cout<< "node and adjacent node "<<graph[i][0] <<" "<< graph[i][j]<<endl;
    contraction(graph, i, j);

    RCA newGraph(graph);
	}
}

void RCA::contraction(vector<vector<int>>& graph, int i, int j){
//brute force:

//identify the index of graph[*][0] where the node j is
	int node_i=graph[i][0];
	int node_j=graph[i][j];
	int node_j_idx;

	for (int ii=0; ii< (int)graph.size(); ++ii){
       if(graph[ii][0]==node_j){
    		node_j_idx= ii;
    		break;
       }
	}

//	cout<< "index of node j "<< node_j_idx<<endl;
// replaces all occurrences of j with i
	for (int nodes=0; nodes< (int)graph.size(); ++nodes){
	std::replace(graph[nodes].begin(), graph[nodes].end(), node_j, node_i);
	}
/*
    cout<< "replace node_j with node_i: "<<endl;
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
//merge lines j and i
	for (int imerge=1; imerge< (int)graph[node_j_idx].size(); ++imerge){
		//from 1, because the index 0 correspond to the node j
		//(and I want just the adjacent nodes
	graph[i].push_back(graph[node_j_idx][imerge]);
	}
/*
    cout<< "merging node_j into node_i: "<<endl;
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
//remove jth node
	graph.erase (graph.begin()+node_j_idx);
/*
    cout<< "removing line of node j: "<<endl;
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
//update the line of the ith node:
    if(node_j_idx< i){i--;};
//remove self loops in ith node
    vector<std::vector<int>::iterator> rem;
    graph[i].erase(std::remove_if(graph[i].begin()+1, graph[i].end(), [&node_i](int n){return n == node_i;}), graph[i].end());
/*
    cout<< "new graph: "<<endl;
    for (int gg=0; gg< (int)graph.size(); ++gg){
    std::for_each(graph[gg].begin(), graph[gg].end(),[](int a){cout<< a<<" "; });
    cout<<  endl;
    }
*/
}
RCA::~RCA() {

}


