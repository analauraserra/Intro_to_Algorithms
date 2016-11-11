//============================================================================
// Name        : TwoSum.cpp
// Author      : ALS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>    // std::reverse
#include <vector>
#include <math.h>
#include <cstdlib>
#include <iterator>
#include <iomanip>

#include <stdio.h>
#include <string.h>

#include <unordered_map>


using namespace std;

int main() {
	string myfile="/media/data/Courses/Algorithms/homework/algo1-programming_prob-2sum.txt";
    ifstream file;

    file.open(myfile.c_str());
    int long value;
    vector<int long> A;

    while (file>> value){
		A.push_back(value);
    }

    file.close();

    vector<int long> target;
    for (int i=-10000; i<=10000; ++i ) target.push_back(i);

    //populate hash map
    std::unordered_map<int long, size_t>  set;
    for (const auto &v : A) {
        ++set[v];
    }

    cout<< "hash table populated"<<endl;

int count=0;
    //for each target
for (int long i=0; i<=20000; ++i){
    int long t=target[i];
    bool is_sum_there=false;
   // for each x in A
    for_each(A.begin(), A.end(),[&t, &set, &count, &is_sum_there](int long x){
   	cout<< "x is "<< x<<endl;
   	cout<< "target:  "<< t <<endl;

    	if (x*2 != t){ // so y is not gonna be = x
    	std::unordered_map<int long, size_t>::const_iterator got = set.find(t-x);

    	  if ( got != set.end() ){
    	    std::cout << got->first << " is " << got->second<<endl;
    	    cout<< got->first + x <<" = "<< t<<endl;
    	    is_sum_there=true;
    	    if ( got->first == x) cout << "equal!!!" <<endl;
    	  }

    	}
    	;} );
    if(is_sum_there) {
    	count++;
        cout<< "number of targets: "<< count << endl;
        is_sum_there=false;
    }
}
    cout<< "total number of targets: "<< count << endl;
/*
//brute force
count=0;
 for (int long k=0; k<=20000; ++k){
  int long t=target[k];
    for (int long i = 0; i < A.size(); i++){
      for (int long j = i; j < A.size(); j++){
        if (A[i] + A[j] == t)
          cout << "(" << A[i] << ", " << A[j] << ")" << endl;
        count++;
      }
    }
 }
 cout<< "total number of combinations: "<<count<<endl;
*/
	return 0;
}
