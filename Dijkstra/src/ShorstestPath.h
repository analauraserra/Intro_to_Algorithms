/*
 * ShorstestPath.h
 *
 *  Created on: Nov 23, 2014
 *      Author: als
 */

#ifndef SHORSTESTPATH_H_
#define SHORSTESTPATH_H_

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

class ShorstestPath {
public:
	ShorstestPath(int , int , std::vector<int> &, std::vector<std::vector<std::pair<int,int>>>& );
	~ShorstestPath();

	 static void divideLine(std::string & myLine, int& vertex, std::vector<std::pair<int,int>>& edges){
		 edges.clear();
			 	std::vector<std::string> fieldsString;
			     //dividing the line into fields
			     std::istringstream ss(myLine);
			     //putting all the tokens in the vector
			     std::copy(std::istream_iterator<std::string>(ss),
			              std::istream_iterator<std::string>(),
			              std::back_inserter<std::vector<std::string> >(fieldsString));

			    //the first component is the vertex
			    std::istringstream ( fieldsString[0] ) >> vertex;

			    std::pair<int, int> mypair;
		        std::for_each(fieldsString.begin()+1, fieldsString.end(),[&edges, &mypair](std::string a){
			    std::replace(a.begin(), a.end(), ',', ' ');
		        //re-devide because there are no more commas
			    std::istringstream sst(a);
			    std::vector<std::string> subfield;
			    std::copy(std::istream_iterator<std::string>(sst),
			              std::istream_iterator<std::string>(),
			              std::back_inserter<std::vector<std::string> >(subfield));
			    //these are always two components
			    std::istringstream ( subfield[0] ) >> mypair.first;
			    std::istringstream ( subfield[1] ) >> mypair.second;

			    edges.push_back(mypair);
		        });

	 }

};

#endif /* SHORSTESTPATH_H_ */
