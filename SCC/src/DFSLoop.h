/*
 * DFSLoop.h
 *
 *  Created on: Nov 16, 2014
 *      Author: als
 */

#ifndef DFSLOOP_H_
#define DFSLOOP_H_

#include <vector>

class DFS_Loop {
public:
	DFS_Loop(std::vector<std::vector<unsigned long int>>&, unsigned long int, std::vector<unsigned long int>&);
	~DFS_Loop();

	const std::vector<unsigned long int>& getFt() const {
		return ft;
	}

	const std::vector<unsigned long int>& getLeader() const {
		return leader_set;
	}

	const std::vector<unsigned long int>& getCounts() const {
		return counts;
	}

private:
    unsigned long int fin_time;
    unsigned long int SCC_leader;
	unsigned long int n_nodes, set_count;
	std::vector<bool> was_visited;
	std::vector<unsigned long int> leader, ft, leader_set, counts;

    void DFS(std::vector<std::vector<unsigned long int>>& , unsigned long int, std::vector<unsigned long int>& );
};

#endif /* DFSLOOP_H_ */
