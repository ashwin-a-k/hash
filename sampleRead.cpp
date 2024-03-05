//================================================================
// Matt Kretchmar
// February 2024
//
// This is a stub file driver for testing the Board classs with
// the RushHour configuration files.  You can use it for the basis
// of your main file.
//
// To execute:
// ./sampleRead 10 <Config0.txt
//================================================================

#include "Board.h"
// your hash class eventually
//#include "Hash.h"
#include <iostream>
using namespace std;

//================================================================
// This main method simply reads boards one at a time and prints
// the board along with its hash value.
//================================================================
int		main	( int argc, char *argv[] )
{

   // notice the hash table size is a command-line parameter
   if ( argc != 2 )
   {
      printf("Error: you must include the hash table size as a");
      printf(" command-line parameter.\n");
      exit(0);
   }
   int size = atoi(argv[1]);

   // here is what your declaration should look like
   // when you eventually create the HashTable class
   //HashTable<Board>  table(size);

   // Now we attempt to read in boards until "EOF" is detected
   Board	b; // used to store the boards being read
   cin >> b;
   while ( !cin.eof() )
   {
      // here is where you might test if you have seen this board
      // before, if not enter it into your hash table.

      cout << "Read in board: \n";     // comment this out later
      cout << b;
      cin >> b;
   };

   // add some code here to compute statistics for your
   // hashing performance

   return 0;
}
