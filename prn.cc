//prn.cc 
//This function writes the index and the values of the components
//of the vector c by sending them to the corresponding stream 
//
// INPUT:
//    fileout: stream connected to the output file
//        vec: STL vector. This is the vector we want to write to the
//             file.

#ifndef _DO_THE_BASICS_
#define _DO_THE_BASICS_

#include<vector>
#include<fstream>
#include<iomanip>

int prn(std::ostream & fileout, std::vector<double> const & vec) 
{

	fileout << std::scientific << std::setprecision(10);

	for (size_t i = 0; i < vec.size(); ++i)
		fileout << std::setw(5) 
			<< i 
			<< std::setw(20) 
			<< vec[i] 
			<< std::endl;

	return 0;
}

#endif
// _DO_THE_BASICS_
