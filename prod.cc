// prod.cc
// Computes the product of a n x n matrix by a n x 1 column vector 
// INPUT:
//    aa: a STL "vector of vectors". Represents the matrix A,
//    bb: a STL vector. Represents the vector b.
// OUTPUT:
//    cc: STL vector. The product of the matrix by the vector, c = A · b.
//
#ifndef _DO_THE_BASICS_
#define _DO_THE_BASICS_

#include<vector>

std::vector<double> prod(std::vector<std::vector<double>> const & aa,
		std::vector<double> const & bb)
{
	std::vector<double> cc(bb.size(), 0.0e0);

	for (size_t i = 0; i < bb.size(); ++i)
		for (size_t j = 0; j < bb.size(); ++j)
			cc[i] += aa[i][j]*bb[j];

	return cc;
}

#endif
// _DO_THE_BASICS_
