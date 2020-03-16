## README
#### DO THE BASICS!
Reads parameters from the command line, open a file to read data, and write the 
results to another file
##### Source files involved
* <tt>main.cc</tt>
* <tt>prod.cc</tt>
* <tt>prn.cc</tt>

To compile, do

<tt>g++ main.cc prod.cc prn.cc -obasics</tt>, 

or

<tt>clang++ main.cc prod.cc prn.cc -obasics</tt> 

(a UNIX makefile is supplied as well).

This builds up an executable file, <tt>basics</tt> (<tt>basics.exe</tt> on
Windows) that reads the ASCII files, <tt>MXX.DAT</tt> (<tt>XX</tt> =
00,01,...,99) shapes the matrix A and the vector b, multiplies the
matrix by the vector, and writes the components of the product vector, c = A b,
to another file. The names of both, the input and output files must be supplied
by the user at the command line.

You can run the program on a Unix/Linux/mac OS terminal with the command, 

<p><tt>
username@machine:~/path/to/folder$ ./basics MXX.DAT PRODXX.TXT
</tt></pp>

or on a (cmd or PowerShell) Windows terminal with the command 

<p><tt>
C:\Users\Username\Path\to\Folder> basics.exe MXX.DAT PRODXX.TXT
</tt></p>

and, on exit, it creates a file, <tt>PRODXX.TXT</tt>, with the indices and the 
components of $c$. These components are also printed out to the terminal.
