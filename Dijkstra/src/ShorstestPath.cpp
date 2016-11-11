/*
 * ShorstestPath.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: als
 */
#include <algorithm>    // std::reverse
#include <vector>
#include <math.h>
#include <cstdlib>
#include <iterator>
#include <iomanip>
#include <algorithm>    // std::min_element, std::max_element


#include <stdio.h>
#include <string.h>

#include "ShorstestPath.h"
using namespace std;

ShorstestPath::ShorstestPath(int s, int p, std::vector<int> &vertices, std::vector<std::vector<std::pair<int,int>>>& edges) {

	vector<int> A, X;
	vector<bool> was_converted;
	int converted;
	int n=vertices.size();


	A.resize(n);
    fill(A.begin(),A.end(),0);
    was_converted.resize(n);
    fill(was_converted.begin(),was_converted.end(),false);

    converted=1;
    was_converted[s-1]=true;
    X.push_back(s);

    int t, SP_dist;

    while(converted!=n){
    	//loop over nodes in X
		vector<int> score, score_idx;
    	for (int v=0; v < (int)X.size(); ++v){
    		int v_idx=X[v]-1;
    		//look at that vertex's line: edges[v-1] and see how many of the
    		//ending vertices are in V-X
    		//create a mini vector to keep track of this A's
    		for (int e=0; e<(int)edges[v_idx].size();++e){
    			int node= edges[v_idx][e].first-1; //linked node
    			if (!was_converted[node]){ //it is in V-X
            		cout<<"--edge "<< edges[v_idx][e].first<<endl;
            		cout<<"--length "<< edges[v_idx][e].second<<endl;
            		cout<<"--score "<< A[v_idx]+edges[v_idx][e].second<<endl;
    				score.push_back(A[v_idx]+edges[v_idx][e].second); //distances between nodes
    				score_idx.push_back(edges[v_idx][e].first); //distances between nodes
    			}
    		}
    	}
		//take the minimum of local_A
		auto min = min_element(score.begin(), score.end());
		//add that node to X
		int min_idx = min - score.begin();
		t=score_idx[min_idx];

		X.push_back(t);
		A[t-1]=score[min_idx];
		was_converted[t-1]=true;
		converted++;
    }
    SP_dist=A[p-1];
    cout<< "shortest path from node "<< s <<" to " <<p<<" is "<< SP_dist<<endl;

}

ShorstestPath::~ShorstestPath() {
	// TODO Auto-generated destructor stub
}

