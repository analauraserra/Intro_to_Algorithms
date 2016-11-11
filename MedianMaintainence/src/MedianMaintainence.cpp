//============================================================================
// Name        : MedianMaintainence.cpp
// Author      : ALS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <queue>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <numeric>

using namespace std;

int main() {
	std::priority_queue<int, std::vector<int>, std::greater<int> > Hh; //greatest v
	std::priority_queue<int>  Hl; //smallest v's

	string myfile="/media/data/Courses/Algorithms/homework/Median.txt";
    ifstream file;

    file.open(myfile.c_str());
    int value;
    vector<int> A;
    vector<float> median, median2;

    int Hlmax, Hhmin;

    int va1, va2;
    //1st and 2nd number
    file>> va1;
    file>> va2;

    Hl.push(std::min(va1,va2)); Hh.push(std::max(va1,va2));

      median.push_back(0.0); //component 0=0, just to avoid index problems; k=0
      median.push_back(va1); //first median is the only value, k=1
      median.push_back(std::min(va1,va2)); //k=2 --> median= k/2 smallest

      median2.push_back(0.0); //component 0=0, just to avoid index problems; k=0

	A.push_back(va1);
    cout << "added " << va1<<endl;
  //  cout << "median 1 " <<median[1]<<endl;
    std::nth_element(A.begin(), A.begin() + A.size()/2, A.end());
    median2.push_back(va1);

	A.push_back(va2);
    cout << "added " << va2<<endl;
 //   cout << "median 2 " <<median[2]<<endl;
    std::nth_element(A.begin(), A.begin() + A.size()/2, A.end());
    median2.push_back(std::min(va1,va2));

    int k=2;
	Hlmax=Hl.top();
	Hhmin=Hh.top();
    while (file>> value){
		A.push_back(value);
	    std::sort(A.begin(), A.end());
		cout<< "ksize " << A.size()<<endl;

	    if (A.size()%2==0) median2.push_back(A[A.size()/2-1]);
	    else median2.push_back(A[(A.size()+1)/2-1]);

		k++;
		cout<< "k " << k<<endl;
		cout<< "value " << value<<endl;
		cout<< "min, max " << Hlmax<< " "<< Hhmin<< endl;

		if (value < Hlmax) Hl.push(value);
		else if (value >= Hhmin) {
		  Hh.push(value);
		}else{ //value < Hhmin and value > Hlmax
		  Hl.push(value);
		}

		Hlmax=Hl.top();
		Hhmin=Hh.top();

		//restore balance and compute median
		int size_low=Hl.size();
		int size_high=Hh.size();
		cout << "sizes "<< size_low << " "<< size_high<<endl;
		if (k%2==0){ //heaps must be the same size
			while (size_high != size_low){
				if(size_high > size_low ){
				//	cout<< "high> low " <<endl;

					Hl.push(Hh.top());
					Hh.pop();
					size_low=Hl.size();
					size_high=Hh.size();
				}else{
			//		cout<< "high< low " <<endl;

					Hh.push(Hl.top());
					Hl.pop();
					size_low=Hl.size();
					size_high=Hh.size();
				}
			}
	//		cout<< "equal " <<endl;

		//median
		median.push_back(Hl.top());
		cout << "corrected sizes "<< size_low << " "<< size_high<<endl;
	    cout << "added " << value<<endl;
	    cout << "median " <<median[k]<<endl;

		}else{ //k is odd, so heaps are unbalanced by one
		    cout << "k odd "<<endl;

			if(size_high > size_low ){
				while (size_high != size_low+1){
					Hl.push(Hh.top());
					Hh.pop();
					size_low=Hl.size();
					size_high=Hh.size();
				}
			//median
			median.push_back(Hh.top());
			cout << "corrected sizes "<< size_low << " "<< size_high<<endl;
		    cout << "added " << value<<endl;
		    cout << "median " <<median[k]<<endl;
			}else{
			    cout << "qui "<<endl;

				while (size_low != size_high+1){
					Hh.push(Hl.top());
					Hl.pop();
					size_low=Hl.size();
					size_high=Hh.size();
				}
			    cout << "while finito "<<endl;

			//median
			median.push_back(Hl.top());
			cout << "corrected sizes "<< size_low << " "<< size_high<<endl;
		    cout << "added " << value<<endl;
		    cout << "median " <<median[k]<<endl;
			}
		}
		//re-calculate max/min (we have rearranged the lists)
		Hlmax=Hl.top();
		Hhmin=Hh.top();
		if (median[k] != median2[k]){
			cout <<"medians dont coincide "<< median[k]<<" "<< median2[k]<<endl;
			exit(1);
		}
		cout << "----------------------- "<< endl;

    }

    file.close();

    int long sum = std::accumulate(median.begin(), median.end(), 0);
    int long sum2 = std::accumulate(median2.begin(), median2.end(), 0);

	string omyfile="/media/data/Courses/Algorithms/homework/median_output.txt";
    ofstream ofile;
    ofile.open(omyfile.c_str());

    for (int l=0; l<median.size(); ++l){
    	ofile<< median[l]<<" "<<median2[l]<<endl;
    }


    ofile<< endl;
    ofile<< sum<<" "<<sum2<<endl;
    ofile<< sum%10000<<" "<<sum2%10000<<endl;


    ofile.close();

	return 0;
}
