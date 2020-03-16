//main.cc
//
// This is the main file of the program basics (basics.exe on Windows) which
// reads the ASCII files, MXX.DAT (XX = 00, 01,....,99), shapes the
// matrix A and the vector b, multiplies the matrix by the vector, and writes
// the components of the product vector, c = A b, to another file. The names of
// both, the input and output files, must be supplied by the user at the
// command line.  
//
// To run it, do 
//
// username@machine:~/path/to/folder$ ./basics MXX.DAT PRODXX.TXT
//
// on a Unix/Linux/mac OS terminal
/// C:\Users\Username\Path\to\Folder> basics.exe MXX.DAT PRODXX.TXT
//
// on Windows
//
// Therefore, the file PRODXX.TXT is created with the components of the product.

#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<cstdlib>

//Here we put the headers of the functions that are called from main()
int prn(std::ostream &, std::vector<double> const &);
std::vector<double> prod(std::vector<std::vector<double>> const &, 
		std::vector<double> const &);

int main(int argc, char *argv[])
{
  //Hint: to read from the command line, we need to specity input parameters in the
  //function main. Note above that "int argc and char *argv[]" appear between 
  //the parenthesis, in the declaration of function main(). What are they for?
  //Actually, this is the mechanism that C/C++ uses to collect information 
  //from the command line when we execute the program. More specifically,
  //      
  //int argc: collects number of arguments of the program (wherw first argument is 
  //the name of the program itself.
  //
  //char *argv[] is an array of char srtings, so that there is one such
  //char string for each parameter in the command line. In this way,
  //
  //argv[0]: (char string) collects the name of the program,
  //argv[1]: (char string) collects the name of the 1st. param at the command line,
  //argv[2]: (char string) collects the name of the 2nd. param at the command line,
  //... an so on so forth.	
  //
  //These arguments are passed to the function main and can be used in what follows
  //(for example, they can be assigned to function declared variables).

	if (argc < 3) { // Check if the number of the arguments is correct 
		std::cerr << "Error. Two arguments required in the comand line." 
			<< std::endl 
			<< "Use: " 
			<< std::endl
			<< "\tbasics file_in file_out" 
			<< std::endl;
		exit (EXIT_FAILURE);
	}

	//(1) prints out the command line arguments 
	for (int i = 0; i < argc; ++i) 
		std::cout << "Argument " 
			<< i 
			<< ": " 
			<< argv[i] 
			<< std::endl;

	std::cout << std::endl;

	std::ifstream fin; //create the stream fin (input)
	
	fin.open(argv[1],std::ios::in); // Connects the stream (i.e., the instantation 
	                                // of the class ifstream ) "fin" with the file 
				        // given by character string argv[1]  (recall, 
				        // the first parameter as read from the command 
				        // line). Now we are ready to read data from this 
				        // file.
	if (fin.fail()) {
		std::cerr << "Error. Can't open the file to read the data." 
			<< std::endl;
		exit (EXIT_FAILURE);
	} // Checks it the file was opened successfully

	int n, nu;

	fin >> n >> nu; //read the dimension of the system, and the number of
	                //components of the matrix that are not 0

	std::vector<std::vector<double>> a(n,std::vector<double>(n,0.0e0));

	for (int k = 0, i, j; k< nu; ++k) 
		fin >> i >> j >> a[i][j]; //read the indexs and the value of the
	                                  //components of the matrix
					  
	fin >> nu; //read the number of the components of the vector that are not 0 
            
	std::vector<double> b(n,0.0e0);

	for (int k = 0, i; k < nu; k++) 
		fin >> i >> b[i];       //read the indexs and the values of the 
                                        //components of the vector
					
	fin.close(); //close the input file
        
	std::vector<double> c = prod(a, b); 
	
	std::ofstream fout; //Create the stream fout (output)

	fout.open(argv[2], std::ios::out);  // Connects the stream "fout" with the file
	                                    // given by the character string argv[2] (the
				            // second parameter as reads from the command
				            // line)
	if (fout.fail()) {
		std::cerr << "Error. Can't open the file to write the results " 
			<< std::endl;
		exit (EXIT_FAILURE);
	} //Check if the file was opened successfully

	prn(fout, c);  //prints out the vector c to the screen
	prn(std::cout, c);  //writes the vector c to the output file

	fout.close(); //close the output file

	return 0;
}
