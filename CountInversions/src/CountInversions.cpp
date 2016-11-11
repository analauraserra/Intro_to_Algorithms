//============================================================================
// Name        : CountInversions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "SortAndCount.h"

using namespace std;

int main() {
	string myfile="/media/data/Courses/Algorithms/homework/IntegerArray.txt";
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
    unsigned long int inv;
    SortAndCount myCount(array, inv);
    int count= myCount.getCount();
    cout<< "number of recursive calls: "<< count<<endl;
    cout<< "inversions: "<< inv<<endl;

	return 0;
}
