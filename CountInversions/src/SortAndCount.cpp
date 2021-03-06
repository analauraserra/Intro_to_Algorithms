/*
 * SortAndCount.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: als
 */

#include "SortAndCount.h"

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int SortAndCount::count = 0;
int SortAndCount::inversions = 0;

SortAndCount::SortAndCount(vector<int> &A, unsigned long &inv) {
	//count instances
	number = count; // modifies the instance variable "this->number"
	        ++count; // modifies the class variable "Request::count"
    inv=0;

    int n=A.size();
    if (n==1){
    	inv=0;
    } else {
    	// build two half vectors
        	int n1st, n2nd;
        	if (n%2==0) {n1st=n/2; n2nd=n1st;}
        	else{n1st=(n-1)/2; n2nd=(n+1)/2;}

        	vector<int> B(&A[0], &A[n1st]);
        	vector<int> C(&A[n1st], &A[n]);

        	unsigned long int x, y;
        	x=0;
        	y=0;
        	SortAndCount firstHalf(B, x);
        	cout<< "-------- inversions first half "<< x<<endl;

        	SortAndCount secondHalf(C, y);
        	cout<< "-------- inversions second half "<< x<<endl;

            unsigned long int z=SplitInversions(n1st, B, n2nd, C);
        	inv=inv+z+x+y;
        	if(inv < 0){
        		cout<< "Negative inv; debug your code"<<endl;

        	};

			cout<< "inversions "<<inv<<endl;

    }
}

SortAndCount::~SortAndCount() {
	// TODO Auto-generated destructor stub
}

unsigned long int SortAndCount::SplitInversions(int& n1st, vector<int>& B, int &n2nd, vector<int> &C){
	//Split inversions
	//The split inversions involving an element y of the second array
	//C are precisely the number left in the first array when y is copied
	//the output D

	/*All the inversions are counted here! The two recursive calls
	 * are just to call this part for all the halves (of the halves
	 * of the halves... and so on)
	 */

	int i=0;
	int j=0;
	int n=n1st+n2nd;

	vector<int> idx_B=sort_indexes(B);
	vector<int> idx_C=sort_indexes(C);

	unsigned long int inv=0;
	cout<< "halves are "<< B.size()<< " "<< C.size()<<endl;
	for (int k = 0; k < n; ++k){
        while (i < n1st && j < n2nd){
		int bb=idx_B[i];
		int cc=idx_C[j];

		if (B[bb]<C[cc]){
			++i;
		}else{
			++j;
			inv=inv+(n1st-i);
		}
      }
	}
    return inv;
}
