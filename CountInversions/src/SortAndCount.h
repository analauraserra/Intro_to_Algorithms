/*
 * SortAndCount.h
 *
 *  Created on: Oct 24, 2014
 *      Author: als
 */

#ifndef SORTANDCOUNT_H_
#define SORTANDCOUNT_H_

#include <vector>
#include <iostream>
#include <algorithm>

class SortAndCount {
public:
	SortAndCount(std::vector<int> &, unsigned long int&);
	unsigned long int SplitInversions(int& , std::vector<int>& , int &, std::vector<int> &);

	~SortAndCount();

	int getCount() const {
		return count;
	}

private:
    static int count;
    static int inversions;
    int number;

    template<typename T> static std::vector<T> sort_indexes(const std::vector<T> &v) {
	  // initialize original index locations
	  std::vector<int> idx(v.size());
	  for (unsigned int i = 0; i != idx.size(); ++i) idx[i] = i;
	  // sort indexes based on comparing values in v
	  std::sort(idx.begin(), idx.end(),[&v](int i1, int i2) {return v[i1] < v[i2];});
	  return idx;
	 };
};
#endif /* SORTANDCOUNT_H_ */
