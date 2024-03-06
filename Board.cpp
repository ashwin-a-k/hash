//============================================================================
// Matt Kretchmar
// February 2024
// Board.cpp
//
// See the Board.h file for comments on how to use this class.
//============================================================================

#include "Board.h"
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

//============================================================================
// default constructor does nothing
//============================================================================
Board::Board		( void )
{
}
//============================================================================
// destructor does nothing (no dynamic memory management)
//============================================================================
Board::~Board		( void )
{
}
//============================================================================
// copy constructor creates a new board like the input parameter
//============================================================================
		Board::Board		( const Board &b )
{
	for ( int i = 0; i < BOARD_SIZE; i++ )
		for ( int j = 0; j < BOARD_SIZE; j++ )
			board[i][j] = b.board[i][j];
}
//============================================================================
// assignment operator
//============================================================================
Board		Board::operator=			( const Board &b )
{
	for ( int i = 0; i < BOARD_SIZE; i++ )
		for ( int j = 0; j < BOARD_SIZE; j++ )
			board[i][j] = b.board[i][j];

	return *this;
}
//============================================================================
// comparison operator
// Returns true of the two boards are equal, false otherwise.
//============================================================================
bool		Board::operator==			( const Board &b ) const
{
	for ( int i = 0; i < BOARD_SIZE; i++ )
		for ( int j = 0; j < BOARD_SIZE; j++ )
			if ( board[i][j] != b.board[i][j] )
				return false;

	return true;
}
//============================================================================
// friend method to overload cout << to enable printing.
// Prints a 6x6 array of characters that represent a Rush Hour board
// configuration.  It prints in a format that can be read by the cin
// overload.
//============================================================================
ostream &  operator<< ( ostream &os, const Board &b )
{

   os << "+-----------+\n";
   for ( int i = BOARD_SIZE-1; i >= 0; i-- )
   {
      os << "|";
      for ( int j = 0; j < BOARD_SIZE; j++ )
      {
         os << b.board[i][j];
         if ( j != BOARD_SIZE-1 )
            os << " ";
      }
      os << "|\n";
   }
   os << "+-----------+\n\n";

   return os;
}
//============================================================================
// friend method to overload cin >> to enable reading.
// Reads a board configuration from stdin.  The board should look like the
// following:
//
//  +-----------+
//  |  F F M    |
//  |      M   N|
//  |H A A M   N|
//  |H   P C C N|
//  |    P      |
//  |    P B B  |
//  +-----------+
//
// It is critical that the spacing and characters be preserved exactly or this
// method won't work correctly.
//
//============================================================================
istream &  operator>> ( istream &is, Board &b )
{
   char line[255];  // local line buffer

   // read blank lines till start of board box
   do
   {
      is.getline(line,250);
      if ( is.eof() ) return is;
   } while ( strcmp(line,"+-----------+") );

   for ( int i = BOARD_SIZE-1; i >= 0; i-- )
   {
      is.getline(line,250);
      if ( is.eof() ) return is;
      for ( int j = 0; j < BOARD_SIZE; j++ )
      {
         b.board[i][j] = line[2*j+1];
      }
   }

   // read last line of box
   is.getline(line,250);
   return is;
}
//============================================================================
// getHashValue
// The purpose of this function is to hash a board into the range [0..numHashSlots-1].
// We first convert a board into a char array (see Char2Board).  We then compute
// a function based on the numbers in this storage format.
//============================================================================
#ifdef HASHFUNCTION1
int      Board::getHashValue    ( int numHashSlots ) const
{
   unordered_map<char, int> charToPrime = {
        {'A', 786433}, {'B', 12289}, {'C', 389}, {'D', 769},
        {'E', 1543}, {'F', 3079}, {'G', 97}, {'H', 193},
        {'I', 23}, {'J', 29}, {'K', 31}, {'L', 37},
        {'M', 6151}, {'N', 41}, {'O', 47}, {'P', 53}
   };
   unsigned long long hashValue = 0;
   unsigned long long mod = 1e9 + 9;

   for (int i = 0; i < BOARD_SIZE; ++i) {
      for (int j = 0; j < BOARD_SIZE; ++j) {
         char ch = board[i][j];
         if (charToPrime.find(ch) != charToPrime.end()) {
            int multiplier = charToPrime[ch];
            if (ch >= 'A' && ch <= 'L') {
               multiplier *= (i + 2) * (j + 2);
            } else if (ch >= 'M' && ch <= 'P')
               multiplier *= (i + j + 7);
            hashValue = (hashValue * 257 + multiplier) % mod;
         }
      }
   }
   return hashValue % numHashSlots;

}
#endif
//============================================================================
// getHashValue
// The purpose of this function is to hash a board into the range [0..numHashSlots-1].
// We first convert a board into a char array (see Char2Board).  We then compute
// a function based on the numbers in this storage format.
//============================================================================
#ifdef HASHFUNCTION2
int      Board::getHashValue    ( int numHashSlots ) const
{
	unsigned long val = 5381;
   for (int i=0; i < BOARD_SIZE; i++) {
      for (int j=0; j < BOARD_SIZE; j++) {
         val = ((val << 5) + val) ^ ((int)board[i][j]);
      }
   }
   val >>= sizeof(unsigned long);
	return val  % numHashSlots;
}
#endif
//============================================================================
// getHashValue
// The purpose of this function is to hash a board into the range [0..numHashSlots-1].
// We first convert a board into a char array (see Char2Board).  We then compute
// a function based on the numbers in this storage format.
//============================================================================
#ifdef HASHFUNCTION3
int      Board::getHashValue    ( int numHashSlots ) const
{
   unsigned long long hash = 0;
   unsigned long long mod = 1e9 + 9;
   const unsigned int base = 257;

   for (int i = 0; i < BOARD_SIZE; ++i) {
      unsigned long long rowHash = 0;
      for (int j = 0; j < BOARD_SIZE; ++j) {
         unsigned long long mix = (((board[i][j] + 1)*(i + 2)*(j + 2)) ^ (base * (i + j + 2))) % mod;
         rowHash = (rowHash * base + mix) % mod;
      }
      hash += (rowHash * (i + 1)) % mod;
   }
   hash >>= 11;
   return hash % numHashSlots;
}
#endif
//============================================================================
