/*
 * QS.cpp
 *
 *  Created on: Nov 2, 2014
 *      Author: als
 */

#include <vector>
#include <iostream>
#include <algorithm>


#include "QS.h"
using namespace std;

int QS::NComp = 0;

QS::QS(unsigned long int order, std::vector<int>& A, unsigned long int l, unsigned long int r) {
long int n= r-l+1;
/*
cout<< "--------------------------------"<< endl;

cout<< "array of : "<< n <<" elements"<< endl;
*/
	if(n>1){

		p_idx=choosePivot(order, A, l, r);
		cout<< "Apivot : "<<A[p_idx]<< endl;

		if (p_idx != l) std::swap(A[l],A[p_idx]);

		partition(A, l, r);

		unsigned long int rl, lr;
		rl=p_idx-1;
		lr=p_idx+1;
    	QS A_1st_half(order, A, l, rl);
    	QS A_2nd_half(order, A, lr, r);

	}
}

QS::~QS() {
}

void QS::partition(std::vector<int>& A, unsigned long int l, unsigned long int r){
int p=A[l];

cout<< "l and r: "<< l <<" "<< r<< endl;
cout<< "pivot : "<<p<< endl;


NComp=NComp+r-l;
unsigned long int i=l+1;
 for (unsigned long int j=l+1; j<=r; ++j){
	//  NComp=NComp+1;
	  if (A[j] < p ){
		  std::swap(A[j], A[i]);
		  ++i;
	  }
 }

 std::swap(A[l], A[i-1]);
 p_idx=i-1;


/*
 cout<< "pivot changed to : "<< p_idx <<endl;
 std::for_each(A.begin(), A.end(),[](int a){
 	cout<< a<<endl; });
*/
}

unsigned long int QS::choosePivot(unsigned long o, std::vector<int>& A, unsigned long int l, unsigned long int r){
//return l;
//return r;

	unsigned long int mid, n;
	n=r-l+1;
	mid=0;
	if (n%2==0){mid=n/2+l-1;
	}else{ mid=(n+1)/2+l-1;}

	cout<< "n "<<n<<" "<<endl;

	cout<< "l, mid, r "<<l <<" "<<mid<<" "<<r<< endl;

	cout<< "Al , Amid and Ar: "<< A[l] <<" "<<A[mid]<<" "<< A[r]<< endl;

	//identify the median of l,r,mid
	if (A[mid]>A[l]){
		if(A[mid]<A[r]){return mid;
		}else{
			if(A[r]<A[l]){return l;
			}else{return r;}
		}
	}else{ //A[mid]<=A[l]
		if(A[l]<A[r]){return l;
		}else{ //A[l]>A[r]
			if(A[mid]>A[r]){return mid;
			}else{return r;}
		}
	}


}
