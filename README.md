# TextFile-to-STDOUT-dup2-fork-pipe-
Reading text file, Writing to another text file and the STDOUT 

This program allows the user to input a text file and write to another text file and standard output.
This is acccomplished by utilizing fork() and pipe.

How to execute the program:

./mighty.txt [inputfile.txt] [outputfile.txt]

*Note: The character buffer max is 600

Details:
- Creates a pipe
- Forks a process

Child process: 
    - Calls dup2, writes to standard output goes to the write of end of pipe
    - Uses EXECL to execute cat-b command
    
Parent process: 
    - opens argument 2, file that we are writing to
    - Reads from the pipe until no characters are available
    - Writes to standard output
    - Writes to file
