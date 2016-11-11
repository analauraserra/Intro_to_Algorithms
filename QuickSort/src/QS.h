/*
 * QS.h
 *
 *  Created on: Nov 2, 2014
 *      Author: als
 */

#ifndef QS_H_
#define QS_H_

#include <vector>


class QS {
public:
	QS(unsigned long int order,std::vector<int>& A, unsigned long int, unsigned long int );
	~QS();

	int getComp() const {
		return NComp;
	}

private:
    static int NComp;
    unsigned long int p_idx;
    void partition(std::vector<int>& A, unsigned long int l, unsigned long int r);
    unsigned long int choosePivot(unsigned long int , std::vector<int>& , unsigned long int, unsigned long int );
};

#endif /* QS_H_ */
