/*
 * DFSLoop.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: als
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "DFSLoop.h"

using namespace std;

//unsigned long int DFS_Loop::fin_time = 0;
//unsigned long int DFS_Loop::SCC_leader = 0;

DFS_Loop::DFS_Loop(vector<vector<unsigned long int>>& graph, unsigned long n_nodes, vector<unsigned long int> & order) {

	fin_time=0;
	SCC_leader=0;
	n_nodes=n_nodes+1;
//	cout<< "constructor "<<endl;
	was_visited.resize(n_nodes);
	ft.resize(n_nodes);
//	leader.resize(n_nodes);

	fill(was_visited.begin(),was_visited.end(),false);

	for (unsigned long i=n_nodes-1; i > 0; --i){
   	if(i%10000==0) cout <<"node "<< i<< endl;
  //  	cout <<"node "<< i<< endl;

	//	cout<<"order "<< order[i]<<endl;
   	 unsigned long int node_i_idx=graph[order[i]][0];
//		cout<<"idx "<< node_i_idx<<endl;

   	 unsigned long int node_i=graph[node_i_idx][0];
//		cout<<"node "<< node_i<<endl;

     if(!was_visited[node_i_idx]){
    	 SCC_leader=node_i;
    //	 cout<< "leader set at "<< node_i<<endl;
         leader_set.push_back(node_i);
         set_count=0;
    	 DFS(graph, node_i_idx, order);
    	 counts.push_back(set_count);
     }
	}
/*
	cout<<"finishing time: "<<endl;
	std::for_each(ft.begin()+1, ft.end(),[](unsigned long int a){cout<< a<<" "; });
    cout<<endl;

	cout<<"leaders: "<<endl;
	std::for_each(leader.begin()+1, leader.end(),[](unsigned long int a){cout<< a<<" "; });
    cout<<endl;
*/

}

void DFS_Loop::DFS(vector<vector<unsigned long int>>& graph, unsigned long int node_i_idx, vector<unsigned long int>& order){
		 was_visited[node_i_idx]=true;
//		 leader[node_i_idx]=SCC_leader;
		 set_count++;
//		 cout<< "node: "<< i <<endl;
//		 cout<< "size of this node: "<< graph[i].size()<<endl;
		// std::for_each(graph[node_i_idx].begin(), graph[node_i_idx].end(),[](unsigned long int a){cout<< a<<" "; });

		 //cout<< endl;
		 for(unsigned long int j=1; j < graph[node_i_idx].size(); ++j){
			 unsigned long node_j=graph[node_i_idx][j];
			 unsigned long node_j_idx=graph[order[node_j]][0];
/*
			 cout<< "edge: " << graph[node_i_idx][0] << " to " << node_j<<endl;
		     cout<<"idx j dfs "<< node_j_idx<<endl;
*/
	         if (!was_visited[node_j_idx]) DFS(graph, node_j_idx, order);
		 }

		 fin_time++;
		 ft[node_i_idx]=fin_time;
}

DFS_Loop::~DFS_Loop() {
	// TODO Auto-generated destructor stub
}

