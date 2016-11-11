//============================================================================
// Name        : QuickSort.cpp
// Author      : ALS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "QS.h"

using namespace std;


int main() {
	string myfile="/media/data/Courses/Algorithms/homework/QuickSort.txt";
    ifstream file;
    file.open(myfile.c_str());

    int i;
    vector<int> array;
    while (file >> i){
    array.push_back(i);
    }

    cout<< "check first and last "<< array[0] << " "<< array[array.size()-1]<<endl;

    file.close();
    cout<< "array of "<< array.size()<< " elements"<< endl;

    cout<< "using divide and conquer"<<endl;
    unsigned long l, r;
    l=0;
    r=array.size()-1;
    unsigned long int order=r;
    QS myQuickSort(order, array, l, r);
    int ncomp = myQuickSort.getComp();

    cout<< "number of comparisons: "<< ncomp <<endl;

	string omyfile="/media/data/Courses/Algorithms/homework/output.txt";
    ofstream ofile;
    ofile.open(omyfile.c_str());

    for_each(array.begin(), array.end(),[&ofile](int a){
    	ofile<< a<<endl; });
    ofile.close();
	return 0;
}

