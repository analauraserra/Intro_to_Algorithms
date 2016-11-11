/*
 * RCA.h
 *
 *  Created on: Nov 9, 2014
 *      Author: als
 */

#ifndef RCA_H_
#define RCA_H_

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

class RCA {
public:
	RCA(std::vector<std::vector<int>>&);
	~RCA();


	 static void divideLine(std::string & myLine, std::vector<int>& fields){
		    fields.clear();
		 	std::vector<std::string> fieldsString;
		     //dividing the line into fields
		     std::istringstream ss(myLine);
		     //putting all the tokens in the vector
		     std::copy(std::istream_iterator<std::string>(ss),
		              std::istream_iterator<std::string>(),
		              std::back_inserter<std::vector<std::string> >(fieldsString));
		          // string to float
		          std::for_each(fieldsString.begin(), fieldsString.end(),[&fields](std::string s){
		         	int numb; std::istringstream ( s ) >> numb;
		             fields.push_back(numb);
		          });
	 }

	int getMinCut() const {
		return nMinCut;
	}

private:
	 static int nMinCut;
	 void contraction(std::vector<std::vector<int>>& , int , int );
};

#endif /* RCA_H_ */
